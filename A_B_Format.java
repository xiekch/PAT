import java.util.Scanner;

// -1000000 9
// 1000000 9
public class A_B_Format {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int sum = scanner.nextInt() + scanner.nextInt();
        scanner.close();
        String s = String.valueOf(sum), res = "";

        int len = s.length(), offset = len % 3;
        for (int i = 0; i < len; i++) {
            if (s.charAt(i) == '-') {
                res += '-';
                continue;
            }
            res += s.charAt(i);
            if (i % 3 == offset - 1 && i != len - 1)
                res += ',';
        }
        System.out.println(res);
    }
}