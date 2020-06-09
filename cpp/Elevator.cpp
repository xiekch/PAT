#include <iostream>
using namespace std;
class Solution {
  public:
    void solve() {
        int n;
        cin >> n;
        int totalTime = 0, last = 0, to;
        while (n--) {
            cin >> to;
            if (to > last) {
                totalTime += 6 * (to - last) + 5;
            } else if (to < last) {
                totalTime += 4 * (last - to) + 5;
            } else {
                totalTime += 5;
            }

            last = to;
        }
        printf("%d\n", totalTime);
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}
