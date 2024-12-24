import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int M;
    static int[][] maze;
    static boolean[][] visited;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        maze = new int[N][M];
        visited = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                maze[i][j] = Integer.parseInt(String.valueOf(line.charAt(j)));
            }
        }

        visited[0][0] = true;
        System.out.println(bfs(0,0));
    }

    static int bfs(int x, int y) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{x, y});

        while (!queue.isEmpty()) {
            int current[] = queue.poll();
            int nx = current[0];
            int ny = current[1];

            for (int i = 0; i < 4; i++) {
                int nextX = nx+dx[i];
                int nextY = ny+dy[i];

                if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
                    if(!visited[nextX][nextY] && maze[nextX][nextY] == 1) {
                        queue.add(new int[] {nextX, nextY});
                        visited[nextX][nextY] = true;
                        maze[nextX][nextY] = maze[nx][ny] + 1;
                    }
                }
            }
        }
        return maze[N - 1][M - 1];
    }
}
