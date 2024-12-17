import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int white = 0;
    public static int blue = 0;
    public static int[][] board;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        board = new int[N][N];

        StringTokenizer st;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        div(0, 0, N);

        System.out.println(white);
        System.out.println(blue);
    }

    public static void div(int r, int c, int size) {
        if (colorCheck(r, c, size)) {
            if (board[r][c] == 0) {
                white++;
            } else {
                blue++;
            }
            return;
        }
        int newSize = size / 2;

        div(r, c, newSize);                        // 2사분면
        div(r, c + newSize, newSize);                // 1사분면
        div(r + newSize, c, newSize);                // 3사분면
        div(r + newSize, c + newSize, newSize);    // 4사분면
    }

    public static boolean colorCheck(int r, int c, int size) {

        int color = board[r][c];

        for (int i = r; i < r + size; i++) {
            for (int j = c; j < c + size; j++) {
                if (board[i][j] != color) {
                    return false;
                }
            }
        }
        return true;
    }
}
