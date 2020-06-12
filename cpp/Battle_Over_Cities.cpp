
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int citiesNum, highwaysNum, queriesNum;
    vector<vector<int>> graph;
    bool *visited;

    void dfs(int city) {
        visited[city] = true;
        for (int i : graph[city]) {
            if (!visited[i])
                dfs(i);
        }
    }

  public:
    void solve() {
        cin >> citiesNum >> highwaysNum >> queriesNum;
        graph = vector<vector<int>>(citiesNum + 1);
        // for (int i = 0; i < citiesNum; i++) {
        //     graph.push_back(vector<int>());
        // }

        // build the graph
        int a, b;
        for (int i = 0; i < highwaysNum; i++) {
            scanf("%d%d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // count the connected components
        visited = new bool[citiesNum + 1];
        for (int i = 0; i < queriesNum; i++) {
            int toRepair = 0;
            fill(visited, visited + citiesNum + 1, false);
            int city;
            scanf("%d", &city);
            visited[city] = true;
            for (int j = 1; j <= citiesNum; j++) {
                if (!visited[j]) {
                    dfs(j);
                    toRepair++;
                }
            }

            printf("%d\n", toRepair - 1);
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}
