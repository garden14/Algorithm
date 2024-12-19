import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] land;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        land = new int[N + 1][M + 1];

        int min = 256;
        int max = 0;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                land[i][j] = Integer.parseInt(st.nextToken());
                if (min > land[i][j]) {
                    min = land[i][j];
                }
                if (max < land[i][j]) {
                    max = land[i][j];
                }
            }
        }

        int time = 99999999;
        int height = 0;

        for (int i = min; i <= max; i++) {
            int result = 0;
            int inv = B;

            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    if (i < land[j][k]) {
                        result += ((land[j][k] - i) * 2);
                        inv += (land[j][k] - i);
                    } else {
                        result += (i - land[j][k]);
                        inv -= (i - land[j][k]);
                    }
                }
            }
            if (inv < 0) {
                break;
            }
            if (time >= result) {
                time = result;
                height = i;
            }

        }
        System.out.println(time + " " + height);

    }
}
