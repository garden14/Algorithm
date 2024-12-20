import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int M;
    static int result = 0;
    static String[][] campus;
    static boolean[][] visited;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    static public void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int start_x = 0;
        int start_y = 0;

        campus = new String[N + 1][M + 1];
        visited = new boolean[N + 1][M + 1];

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                campus[i][j] = String.valueOf(line.charAt(j));
                if (campus[i][j].equals("I")) {
                    start_x = i;
                    start_y = j;
                }
            }
        }

        dfs(start_x, start_y);

        if (result == 0) {
            System.out.println("TT");
        } else {
            System.out.println(result);
        }
    }

    static void dfs(int x, int y) {
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !campus[nx][ny].equals("X") && !visited[nx][ny]) {
                if (campus[nx][ny].equals("P")) {
                    result++;
                }
                dfs(nx, ny);
            }
        }
    }
}
