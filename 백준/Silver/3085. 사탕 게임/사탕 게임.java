
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int max = 1;
    static int n;
    static char[][] board;

    static public void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        board = new char[n][n];

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < n; j++) {
                board[i][j] = line.charAt(j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                swap(i, j, i, j + 1);
                maxCandy();
                swap(i, j + 1, i, j);
            }
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n; j++) {
                swap(i, j, i + 1, j);
                maxCandy();
                swap(i + 1, j, i, j);
            }
        }
        System.out.println(max);
    }

    static void swap(int ax, int ay, int bx, int by) {
        char temp = board[ax][ay];
        board[ax][ay] = board[bx][by];
        board[bx][by] = temp;
    }

    static void maxCandy() {
        for (int i = 0; i < n; i++) {
            int count = 1;

            for (int j = 0; j < n - 1; j++) {
                if (board[i][j] == board[i][j + 1]) {
                    count++;
                    max = Math.max(max, count);
                } else {
                    count = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int count = 1;

            for (int j = 0; j < n - 1; j++) {
                if (board[j][i] == board[j + 1][i]) {
                    count++;
                    max = Math.max(max, count);
                } else {
                    count = 1;
                }
            }
        }
    }
}
