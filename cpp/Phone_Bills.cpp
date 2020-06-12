#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct CallTime {
    int month, day, hour, minute;
    int time;
    string name;
    bool on;
    CallTime(string name, bool on, int mm, int dd, int hh, int min)
        : name(name), on(on), month(mm), day(dd), hour(hh), minute(min) {
        time = 24 * 60 * day + 60 * hour + minute;
    }
    bool operator<(const CallTime &other) {
        return (this->name != other.name) ? this->name < other.name
                                          : this->time < other.time;
    }
};

class Solution {
    int rate[25] = {0};
    double feeAccumulated(const CallTime &callTime) {
        double total = rate[24] * 60 * callTime.day;
        for (int i = 0; i < callTime.hour; i++)
            total += rate[i] * 60;
        total += rate[callTime.hour] * callTime.minute;
        return total / 100;
    }

  public:
    void solve() {
        for (int i = 0; i < 24; i++) {
            cin >> rate[i];
            rate[24] += rate[i];
        }
        int n;
        cin >> n;
        int mm, dd, hh, min;
        string name, temp;
        bool on;
        vector<CallTime> records;
        for (int i = 0; i < n; i++) {
            cin >> name;
            scanf("%d:%d:%d:%d", &mm, &dd, &hh, &min);
            cin >> temp;
            on = (temp == "on-line") ? true : false;
            records.push_back(CallTime(name, on, mm, dd, hh, min));
        }
        sort(records.begin(), records.end());

        map<string, vector<CallTime>> res;
        for (int i = 1; i < records.size(); i++) {
            if (records[i - 1].name == records[i].name && records[i - 1].on &&
                records[i].on == false) {
                res[records[i].name].push_back(records[i - 1]);
                res[records[i].name].push_back(records[i]);
            }
        }

        for (auto it : res) {
            cout << it.first << " ";
            auto calls = it.second;
            printf("%02d\n", calls[0].month);
            double total = 0;
            for (int j = 0; j < calls.size(); j += 2) {
                double fee =
                    feeAccumulated(calls[j + 1]) - feeAccumulated(calls[j]);
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", calls[j].day,
                       calls[j].hour, calls[j].minute, calls[j + 1].day,
                       calls[j + 1].hour, calls[j + 1].minute,
                       calls[j + 1].time - calls[j].time, fee);
                total += fee;
            }

            printf("Total amount: $%.2f\n", total);
        }
    }
};
int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}
