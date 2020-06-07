#include <cstring>
#include <iostream>
using namespace std;

// begin number must be a positive number
class Solution {
    int nums[10001];

  public:
    void solve() {
        int k;
        cin >> k;
        memset(nums, 0, sizeof(nums));
        for (int i = 0; i < k; i++) {
            cin >> nums[i];
        }

        int beginIndex = 0, endIndex = k - 1, maxSum = -1, preSum = 0,
            tempIndex = 0;
        for (int i = 0; i < k; i++) {
            preSum += nums[i];
            if (preSum < 0) {
                preSum = 0;
                tempIndex = i + 1;
            } else if (preSum > maxSum) {
                maxSum = preSum;
                beginIndex = tempIndex;
                endIndex = i;
            }
        }
        
        if (maxSum < 0)
            maxSum = 0;
        printf("%d %d %d\n", maxSum, nums[beginIndex], nums[endIndex]);
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}

// in:
// 5
// -1 0 -1 0 -1
// out: 0 0 0