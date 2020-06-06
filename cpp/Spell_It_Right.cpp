#include <iostream>
#include <string>
using namespace std;

class Solution {
    string digits[10] = {"zero", "one", "two",   "three", "four",
                         "five", "six", "seven", "eight", "nine"};

  public:
    void solve() {
        string str;
        cin >> str;
        int sum = 0;
        for (int i = 0; i < str.length(); i++) {
            sum += str[i] - '0';
        }
        string res = to_string(sum);
        printf("%s", digits[res[0] - '0'].c_str());
        for (int i = 1; i < res.length(); i++) {
            printf(" %s", digits[res[i] - '0'].c_str());
        }
        printf("\n");
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}
