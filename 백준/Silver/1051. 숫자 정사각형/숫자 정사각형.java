
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] rectangle;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        rectangle = new int[N][M];

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                rectangle[i][j] = line.charAt(j) - '0';
            }
        }

        int maxSize = 1;

        for (int k = 1; k < Math.min(N, M); k++) {
            for (int i = 0; i + k < N; i++) {
                for (int j = 0; j + k < M; j++) {
                    if (rectangle[i][j] == rectangle[i][j + k] &&
                            rectangle[i][j] == rectangle[i + k][j] &&
                            rectangle[i][j] == rectangle[i + k][j + k]) {
                        maxSize = Math.max(maxSize, k + 1);
                    }
                }
            }
        }

        System.out.println(maxSize * maxSize);
    }
}
