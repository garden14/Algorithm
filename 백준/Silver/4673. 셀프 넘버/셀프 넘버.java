public class Main {
    public static void main(String[] args) throws Exception {
        int[] num = new int[10000];

        for (int i = 0; i < 10000; i++) {
            int n = self(i + 1);

            if (n <= 10000) {
                num[n - 1] = 1;
            }
        }

        for (int i = 0; i < 10000; i++) {
            if (num[i] == 0) { 
                System.out.println(i + 1);
            }
        }
    }

    public static int self(int n) {
        int sum = n;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
}
