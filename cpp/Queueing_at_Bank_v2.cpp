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

        priority_queue<int, vector<int>, greater<int>> qu;
        int waitTime = 0;
        for (int i = 0; i < windowsNum; i++) {
            qu.push(8 * 60 * 60);
        }
        for (int i = 0; i < customers.size(); i++) {
            // printf("%d %d %d\n", customers[i].hour, customers[i].minu,
            //        customers[i].sec);
            int front = qu.top();
            qu.pop();
            if (front > customers[i].time()) {
                waitTime += front - customers[i].time();
            }
            qu.push(max(front, customers[i].time()) +
                    customers[i].processTime * 60);
        }
        if (customers.empty())
            printf("0.0\n");
        else
            printf("%.1f\n", (double)waitTime / 60 / customers.size());
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}
