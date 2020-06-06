#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    void solve() {
        string firstId, lastId, id;
        int n;
        int firstTime = 0xffffff, lastTime = 0, time;
        cin >> n;
        while (n--) {
            cin >> id;
            int h, m, s;
            scanf("%d:%d:%d", &h, &m, &s);
            time = h * 10000 + m * 100 + s;
            if (time < firstTime) {
                firstTime = time;
                firstId = id;
            }

            scanf("%d:%d:%d", &h, &m, &s);
            time = h * 10000 + m * 100 + s;
            if (time > lastTime) {
                lastTime = time;
                lastId = id;
            }
        }

        cout << firstId << " " << lastId << endl;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}
