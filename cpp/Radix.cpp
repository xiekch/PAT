#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// binary search!
class Solution {
    long long getNum(char ch) {
        if (ch >= '0' && ch <= '9') {
            return ch - '0';
        }
        return ch - 'a' + 10;
    }

    long long getSum(string s, long long radix) {
        long long num = 0;
        for (int i = 0; i < s.length(); i++) {
            num *= radix;
            num += getNum(s[i]);
        }
        return num;
    }

    long long findRadix(string s, long long num) {
        char maxChar = *max_element(s.begin(), s.end());
        long long low = getNum(maxChar) + 1, high = max(low, num);
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long sum = getSum(s, mid);
            if (sum == num) {
                return mid;
                // Mind here
            } else if (sum < 0 || sum > num) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }

  public:
    void solve() {
        string n1, n2;
        int tag, radix;
        cin >> n1 >> n2 >> tag >> radix;
        if (tag == 2) {
            swap(n1, n2);
        }
        long long num = getSum(n1, radix);
        // printf("%d\n", num);

        long long res = findRadix(n2, num);
        if (res != -1) {
            printf("%lld\n", res);
        } else {
            printf("Impossible\n");
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}

// in
// 0 0 1 10
// out
// 1