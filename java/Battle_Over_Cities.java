import java.util.*;

// TLE!!!
class Solution {
    private int citiesNum, highwaysNum, queriesNum;
    private ArrayList<ArrayList<Integer>> graph;
    boolean[] visited;

    private void dfs(int city) {
        visited[city] = true;
        for (int i : graph.get(city)) {
            if (!visited[i])
                dfs(i);
        }
    }

    public void solve() {
        Scanner scanner = new Scanner(System.in);
        citiesNum = scanner.nextInt();
        highwaysNum = scanner.nextInt();
        queriesNum = scanner.nextInt();
        graph = new ArrayList<>();
        for (int i = 0; i <= citiesNum; i++) {
            graph.add(new ArrayList<>());
        }
        // build the graph
        for (int i = 0; i < highwaysNum; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        // count the connected components
        visited = new boolean[citiesNum + 1];
        for (int i = 0; i < queriesNum; i++) {
            int toRepair = 0;
            Arrays.fill(visited, false);
            int city = scanner.nextInt();
            visited[city] = true;
            for (int j = 1; j <= citiesNum; j++) {
                if (!visited[j]) {
                    dfs(j);
                    toRepair++;
                }
            }

            System.out.println(toRepair - 1);
        }
        scanner.close();
    }
}

public class Battle_Over_Cities {
    public static void main(String[] args) {
        Solution sol = new Solution();
        sol.solve();
    }
}