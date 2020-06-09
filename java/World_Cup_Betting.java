import java.util.Scanner;

class Solution {
    public void solve() {
        Scanner scanner = new Scanner(System.in);
        String[] arr = { "W", "T", "L" };
        double res = 1;
        for (int i = 0; i < 3; i++) {
            int index = 0;
            double maxOdds = Double.MIN_VALUE;
            for (int j = 0; j < 3; j++) {
                double odds = scanner.nextDouble();
                if (odds > maxOdds) {
                    maxOdds = odds;
                    index = j;
                }
            }
            res *= maxOdds;
            System.out.printf("%s ", arr[index]);
        }
        scanner.close();
        res = (res * 0.65 - 1) * 2;
        System.out.printf("%.2f\n", res);
    }
}

public class World_Cup_Betting {
    public static void main(String[] args) {
        Solution sol = new Solution();
        sol.solve();
    }
}