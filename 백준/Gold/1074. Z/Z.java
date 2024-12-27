
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int x = (int) Math.pow(2, N);

        System.out.println(solve(x, r, c));
    }

    public static int solve(int size, int r, int c) {
        if (size == 1) {
            return 0;
        }

        int half = size / 2;
        int area = 0;

        if (r < half && c < half) {
            area = 0;
        } else if (r < half && c >= half) {
            area = 1;
            c -= half;
        } else if (r >= half && c < half) {
            area = 2;
            r -= half;
        } else {
            area = 3;
            r -= half;
            c -= half;
        }

        return area * (half * half) + solve(half, r, c);
    }
}
