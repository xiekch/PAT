#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
class Solution {
  public:
    void solve() {
        int windowsNum, capacityNum, customersNum, queriesNum;
        cin >> windowsNum >> capacityNum >> customersNum >> queriesNum;
        int customersTime[1001], queries[1001];
        for (int i = 0; i < customersNum; i++) {
            cin >> customersTime[i];
        }
        for (int i = 0; i < queriesNum; i++) {
            cin >> queries[i];
            queries[i]--;
        }

        queue<int> windows[21];
        int customersEndTime[1001];
        fill(customersEndTime, customersEndTime + 1001, 0);

        for (int i = 0; i < customersNum; i++) {
            bool empty = false;
            int index = 0;
            int lastEndTime = 0;
            for (int j = 0; j < windowsNum; j++) {
                if (windows[j].size() < capacityNum) {
                    if ((empty && windows[index].size() > windows[j].size()) ||
                        !empty) {
                        index = j;
                    }
                    empty = true;
                }
            }
            // printf("empty: %d\n", empty);

            if (!empty) {
                for (int j = 0; j < windowsNum; j++) {
                    if (windows[j].front() < windows[index].front()) {
                        index = j;
                    }
                }
                lastEndTime = windows[index].back();
                windows[index].pop();
            }
            // printf("%d\n", index);
            if (windows[index].empty())
                customersEndTime[i] = lastEndTime + customersTime[i];
            else
                customersEndTime[i] = windows[index].back() + customersTime[i];
            windows[index].push(customersEndTime[i]);
        }

        for (int i = 0; i < queriesNum; i++) {
            int h = 8 + customersEndTime[queries[i]] / 60,
                m = customersEndTime[queries[i]] % 60;
                // for those customers who cannot **be served** before 17:00, you must output Sorry instead.
            if (8 * 60 + customersEndTime[queries[i]] -
                    customersTime[queries[i]] >=
                17 * 60) {
                printf("Sorry\n");
            } else
                printf("%02d:%02d\n", h, m);
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}
