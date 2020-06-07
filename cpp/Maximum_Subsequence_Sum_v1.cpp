#include <cstring>
#include <iostream>
using namespace std;

class Solution {
    int nums[10001];
    int preSum[10001];

  public:
    void solve() {
        int k;
        cin >> k;
        memset(nums, 0, sizeof(nums));
        memset(preSum, 0, sizeof(preSum));
        for (int i = 0; i < k; i++) {
            cin >> nums[i];
        }
        preSum[0] = nums[0];
        for (int i = 1; i < k; i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }

        int beginIndex = 0, endIndex = k - 1, maxSum = -1;
        for (int i = 0; i < k; i++) {
            for (int j = i; j < k; j++) {
                int sum = preSum[j] - preSum[i] + nums[i];
                if (sum > maxSum) {
                    maxSum = sum;
                    beginIndex = i;
                    endIndex = j;
                }
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