import java.util.*;

public class LCWeeklyContest {

    public int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    boolean[] prime;

    public boolean[] getPrimeNums(int ceiling) {
        prime = new boolean[ceiling + 1];
        Arrays.fill(prime, true);
        int sqrtn = (int) Math.sqrt(ceiling + 0.1);
        for (int i = 2; i <= sqrtn; i++) {
            if (prime[i]) {
                for (int j = i; j * i <= ceiling; j++) {
                    prime[i * j] = false;
                }
            }
        }
        return prime;
    }

    public boolean isPrime(int n) {
        return prime[n];
    }

    public static void main(String[] args) {
        LCWeeklyContest lc = new LCWeeklyContest();
    }
}