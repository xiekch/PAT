#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

class Solution {
    bool isPrime(ll num) {
        if (num <= 1)
            return false;
        if (num == 2)
            return true;
        int sqr = sqrt(num);
        for (ll i = 2; i <= sqr; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

  public:
    void solve() {
        ll num, radix;
        while (cin >> num && num > 0) {
            cin >> radix;
            if (!isPrime(num)) {
                printf("No\n");
                continue;
            }
            vector<int> vec;
            while (num != 0) {
                vec.push_back(num % radix);
                num /= radix;
            }
            ll reverse = 0;
            for (int i = 0; i < vec.size(); i++) {
                reverse *= radix;
                reverse += vec[i];
            }

            if (!isPrime(reverse)) {
                printf("No\n");
            } else {
                printf("Yes\n");
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}
