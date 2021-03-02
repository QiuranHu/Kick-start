import java.util.*;
import java.io.*;

public class Solution {
    public static int solve(int n, int k, int s) {
        return Math.min(n + 1, k + n - 2 * s + 1) + k - 1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt();
        for (int i = 1; i <= t; ++i) {
            int n = in.nextInt();
            int k = in.nextInt();
            int s = in.nextInt();
            System.out.println("Case #" + i + ": " + solve(n, k, s));
        }
    }
}