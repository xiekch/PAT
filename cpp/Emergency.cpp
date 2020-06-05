#include <iostream>
#include <vector>
using namespace std;

#define INF (0xfffffff)

class Solution {
  public:
    void solve() {
        // n: the number of cities. m: the number of roads
        int n, m, c1, c2;
        cin >> n >> m >> c1 >> c2;
        vector<int> teamsNum(n, 0);
        vector<vector<int>> roads(n, vector<int>(n, INF));
        // input teams
        for (int i = 0; i < n; i++) {
            cin >> teamsNum[i];
        }
        // input roads
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            cin >> roads[a][b];
            roads[b][a] = roads[a][b];
        }

        vector<int> distance(n, INF);
        distance[c1] = 0;

        // dijkstra
        vector<bool> visited(n, false);
        vector<int> nums(n, 0);
        nums[c1] = 1;
        vector<int> teams(n, 0);
        teams[c1] = teamsNum[c1];

        for (int i = 0; i < n; i++) {
            int minimum = INF, u = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && distance[j] < minimum) {
                    u = j;
                    minimum = distance[j];
                }
            }
            if ((u == -1) || (visited[c2])) {
                break;
            }
            // cout << u << endl;
            visited[u] = true;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && roads[u][j] != INF) {
                    if (distance[j] > distance[u] + roads[u][j]) {
                        distance[j] = distance[u] + roads[u][j];
                        nums[j] = nums[u];
                        teams[j] = teamsNum[j] + teams[u];
                    } else if (distance[j] == distance[u] + roads[u][j]) {
                        nums[j] = nums[j] + nums[u];
                        teams[j] = max(teams[j], teamsNum[j] + teams[u]);
                    }
                }
            }
            // for (int i = 0; i < n; i++) {
            //     cout << distance[i] << " ";
            // }
            // cout << endl;
            // for (int i = 0; i < n; i++) {
            //     cout << teams[i] << " ";
            // }
            // cout << endl;
            // for (int i = 0; i < n; i++) {
            //     cout << nums[i] << " ";
            // }
            // cout << endl;
        }

        printf("%d %d\n", nums[c2], teams[c2]);
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}
