#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// https://github.com/liuchuo/PAT
#define INF 0xfffffff

class Solution {
    vector<int> bikes;
    int edges[510][510];
    int distance[510];
    bool visited[510];
    vector<int> prev[510];
    vector<int> path, tPath;
    int minToSend = INF, minToTake = INF;

    void dfs(int v) {
        tPath.push_back(v);
        if (v == 0) {
            int toSend = 0, toTake = 0;
            for (int i = tPath.size() - 2; i >= 0; i--) {
                int bike = bikes[tPath[i]];
                // lack
                if (bike < 0) {
                    bike = -bike;
                    if (toTake >= bike) {
                        toTake -= bike;
                    } else {
                        toSend += bike - toTake;
                        toTake = 0;
                    }
                    // spare
                } else if (bike > 0) {
                    toTake += bike;
                }
            }

            if (minToSend > toSend) {
                minToSend = toSend;
                minToTake = toTake;
                path = tPath;
            } else if (minToSend == toSend && minToTake > toTake) {
                minToTake = toTake;
                path = tPath;
            }
        } else {
            for (int i : prev[v]) {
                dfs(i);
            }
        }
        tPath.pop_back();
    }

  public:
    void solve() {
        fill(distance, distance + 510, INF);
        fill(edges[0], edges[0] + 510 * 510, INF);
        fill(visited, visited + 510, false);

        int capacity, stationsNum, problemStation, roadsNum;
        cin >> capacity >> stationsNum >> problemStation >> roadsNum;
        int bike;
        bikes.push_back(0);
        for (int i = 0; i < stationsNum; i++) {
            cin >> bike;
            bikes.push_back(bike - capacity / 2);
        }

        for (int i = 0; i < roadsNum; i++) {
            int a, b, cost;
            cin >> a >> b >> cost;
            edges[a][b] = edges[b][a] = cost;
        }

        distance[0] = 0;
        for (int i = 0; i <= stationsNum; i++) {
            int u = -1, minimum = INF;
            for (int j = 0; j <= stationsNum; j++) {
                if (!visited[j] && distance[j] < minimum) {
                    minimum = distance[j];
                    u = j;
                }
            }
            if (u == -1)
                break;
            visited[u] = true;
            for (int j = 0; j <= stationsNum; j++) {
                if (!visited[j] && edges[u][j] != INF) {
                    if (edges[j][u] + distance[u] < distance[j]) {
                        distance[j] = edges[j][u] + distance[u];
                        prev[j].clear();
                        prev[j].push_back(u);
                    } else if (edges[j][u] + distance[u] == distance[j]) {
                        prev[j].push_back(u);
                    }
                }
            }
        }
        dfs(problemStation);
        printf("%d %d", minToSend, 0);
        for (int i = path.size() - 2; i >= 0; i--) {
            printf("->%d", path[i]);
        }
        printf(" %d\n", minToTake);
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}
