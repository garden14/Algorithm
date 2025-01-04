
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static char[][] map;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new char[n][m];
        visited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j] = line.charAt(j);
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    count++;
                    dfs(i, j, map[i][j]);
                }
            }
        }

        System.out.println(count);

    }

    static void dfs(int x, int y, char shape) {
        if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || map[x][y] != shape) {
            return;
        }

        visited[x][y] = true;

        if (shape == '-') {
            dfs(x, y + 1, shape);
        } else {
            dfs(x + 1, y, shape);
        }
    }
}
