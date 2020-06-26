#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void solve() {
        vector<int> baseNum;
        int num, base;
        char ch;
        cin >> num >> base;
        while (num != 0) {
            baseNum.push_back(num % base);
            num /= base;
        }

        bool isPalindromic = true;
        for (int low = 0, high = baseNum.size() - 1; low < high;
             low++, high--) {
            if (baseNum[low] != baseNum[high]) {
                isPalindromic = false;
                break;
            }
        }
        printf("%s\n", isPalindromic ? "Yes" : "No");

        for (int i = baseNum.size() - 1; i > 0; i--) {
            printf("%d ", baseNum[i]);
        }
        printf("%d\n", baseNum[0]);
    }
};

// 121 5
int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}
