
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main{
    static int n;
    static int m;
    static int[][] tomato;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        tomato = new int[n][m];
        Queue<int[]> queue = new LinkedList<>();
        int initialZeroCount = 0;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                tomato[i][j] = Integer.parseInt(st.nextToken());
                if (tomato[i][j] == 1) {
                    queue.offer(new int[]{i, j});
                } else if (tomato[i][j] == 0) {
                    initialZeroCount++;
                }
            }
        }

        if (initialZeroCount == 0) {
            System.out.println(0);
            return;
        }

        int result = bfs(queue);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tomato[i][j] == 0) {
                    System.out.println(-1);
                    return;
                }
            }
        }

        System.out.println(result);
    }

    public static int bfs(Queue<int[]> queue) {
        int maxDays = 0;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int cx = current[0];
            int cy = current[1];

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (tomato[nx][ny] == 0) {
                        tomato[nx][ny] = tomato[cx][cy] + 1;
                        maxDays = Math.max(maxDays, tomato[nx][ny]);
                        queue.offer(new int[]{nx, ny});
                    }
                }
            }
        }

        return maxDays - 1;
    }
}
