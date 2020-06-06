import java.util.*;

class TreeNode {
    public ArrayList<TreeNode> children = new ArrayList<>();
}

class Solution {
    void solve() {
        int nodeNum, nonLeafNodeNum;
        Scanner scanner = new Scanner(System.in);
        nodeNum = scanner.nextInt();
        nonLeafNodeNum = scanner.nextInt();
        
        // build the tree
        HashMap<String, TreeNode> tree = new HashMap<>();
        for (int i = 0; i < nonLeafNodeNum; i++) {
            String id = scanner.next();
            int k = scanner.nextInt();
            TreeNode parent = tree.getOrDefault(id, new TreeNode());
            tree.put(id, parent);
            for (int j = 0; j < k; j++) {
                id = scanner.next();
                TreeNode child = tree.getOrDefault(id, new TreeNode());
                parent.children.add(child);
                tree.put(id, child);
            }
        }
        scanner.close();

        // level traversal
        Queue<TreeNode> qu = new LinkedList<>();
        qu.offer(tree.getOrDefault("01", new TreeNode()));
        while (!qu.isEmpty()) {
            int size = qu.size();
            int count = 0;
            for (int i = 0; i < size; i++) {
                TreeNode n = qu.poll();
                if (n.children.isEmpty()) {
                    count++;
                } else {
                    for (TreeNode child : n.children) {
                        qu.offer(child);
                    }
                }
            }
            System.out.print(count);
            if (!qu.isEmpty())
                System.out.print(" ");
        }
        System.out.println();
    }
}

public class Counting_Leaves {
    public static void main(String[] args) {
        Solution m = new Solution();
        m.solve();
    }
}