#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Customer {
    int hour, minu, sec, processTime;
    Customer(int hour, int minu, int sec, int processTime)
        : hour(hour), minu(minu), sec(sec), processTime(processTime) {}
    int time() const { return hour * 60 * 60 + minu * 60 + sec; }

    bool operator<(const Customer &other) {
        return this->time() < other.time();
    }
};

// the bank opens from 08:00 to 17:00
class Solution {
  public:
    void solve() {
        int customNum, windowsNum;
        cin >> customNum >> windowsNum;
        int hour, minu, sec, processTime;
        vector<Customer> customers;
        for (int i = 0; i < customNum; i++) {
            scanf("%d:%d:%d %d", &hour, &minu, &sec, &processTime);
            Customer cust(hour, minu, sec, processTime);
            if (cust.time() > 17 * 60 * 60)
                continue;
            customers.push_back(cust);
        }
        sort(customers.begin(), customers.end());

        vector<int> windows(windowsNum, 8 * 60 * 60);
        queue<Customer> qu;
        int waitTime = 0;
        for (int i = 0; i < customers.size(); i++) {
            // printf("%d %d %d\n", customers[i].hour, customers[i].minu,
            //        customers[i].sec);
            int shortest = 0xffffff, index = 0;
            for (int j = 0; j < windowsNum; j++) {
                if (shortest > windows[j]) {
                    shortest = windows[j];
                    index = j;
                }
            }
            if (windows[index] > customers[i].time()) {
                waitTime += windows[index] - customers[i].time();
            }
            windows[index] = max(windows[index], customers[i].time()) +
                             customers[i].processTime * 60;
        }
        printf("%.1f\n",(double)waitTime / 60 / customers.size());
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}
