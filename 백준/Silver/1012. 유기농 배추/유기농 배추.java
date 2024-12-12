import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int[][] field;
    static boolean[][] visited;
    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {-1, 1, 0, 0};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t --> 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");

            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            field = new int[n][m];
            visited = new boolean[n][m];

            for (int i = 0; i < k; i++) {
                st = new StringTokenizer(br.readLine()," ");
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());

                field[y][x] = 1;
            }

            int count = 0;

            for (int y = 0; y < n; y++) {
                for (int x = 0; x < m; x++) {
                    if (field[y][x] == 1 && !visited[y][x]) {
                        dfs(x,y);
                        count++;
                    }
                }
            }
            System.out.println(count);
        }

    }

    static void dfs(int x, int y) {
        visited[y][x] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < m && ny >=0 && ny <n && field[ny][nx] == 1 && !visited[ny][nx]) {
                dfs(nx,ny);

            }
        }
    }
}
