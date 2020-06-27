#include <iostream>
#include <map>
using namespace std;

// https://github.com/liuchuo/PAT
class Solution {
    int postorder[40] = {0}, inorder[40] = {0};
    map<int, int> level;
    // @param root root's index in postorder
    void buildTree(int root, int start, int end, int index) {
        if (start >= end)
            return;
        level[index] = postorder[root];
        int i = start;
        while (i < end && inorder[i] != level[index]) {
            i++;
        }

        // left child's root: root - num of right children
        buildTree(root - (end - i), start, i, 2 * index + 1);
        buildTree(root - 1, i + 1, end, 2 * index + 2);
    }

  public:
    void solve() {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> postorder[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> inorder[i];
        }

        buildTree(n - 1, 0, n, 0);
        auto it = level.begin();
        printf("%d", it->second);
        for (it++; it != level.end(); it++) {
            printf(" %d", it->second);
        }
        printf("\n");
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}
