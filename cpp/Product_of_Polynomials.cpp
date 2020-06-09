#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

class Solution {
  public:
    void solve() {

        int m, n;
        double coeff;
        int expo;
        map<int, double, greater<int>> mm;
        map<int, double, greater<int>> res;

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> expo >> coeff;
            mm[expo] += coeff;
        }

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> expo >> coeff;
            for (auto it = mm.begin(); it != mm.end(); it++) {
                res[it->first + expo] += it->second * coeff;
            }
        }

        // not mm.size()
        int count = 0;
        for (auto it = res.begin(); it != res.end(); it++) {
            if (it->second != 0)
                count++;
        }
        cout << count;
        for (auto it = res.begin(); it != res.end(); it++) {
            if (it->second != 0)
                printf(" %d %.1f", it->first, it->second);
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}
