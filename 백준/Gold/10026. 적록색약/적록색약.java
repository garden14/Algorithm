
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int n;
    static char[][] arr;
    static boolean[][] visited;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        arr = new char[n][n];
        visited = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < n; j++) {
                arr[i][j] = line.charAt(j);
            }
        }

        int normal = 0;
        int colorBlind = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    bfs(i, j, false);
                    normal++;
                }
            }
        }

        visited = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    bfs(i, j, true);
                    colorBlind++;
                }
            }
        }

        System.out.println(normal+ " " + colorBlind);

    }

    public static void bfs(int x, int y, boolean colorBlind) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{x, y});
        visited[x][y] = true;

        char currentColor = arr[x][y];

        if (colorBlind && (currentColor == 'R' || currentColor == 'G')) {
            currentColor = 'X';
        }

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int cx = current[0];
            int cy = current[1];

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    char nextColor = arr[nx][ny];
                    if (colorBlind && (nextColor == 'R' || nextColor == 'G')) {
                        nextColor = 'X';
                    }
                    if (currentColor == nextColor) {
                        visited[nx][ny] = true;
                        queue.offer(new int[]{nx, ny});
                    }

                }
            }
        }
    }
}
