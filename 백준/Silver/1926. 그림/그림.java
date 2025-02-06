
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n,m;
    static int[][] map;
    static boolean[][] visited;
    static Queue<int[]> queue;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int maxArea = 0;
    static int painting = 0;

    static public void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        visited = new boolean[n][m];
        queue = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(map[i][j] == 1 && !visited[i][j]) {
                    maxArea = Math.max(maxArea,bfs(i,j));
                    painting++;
                }
            }
        }

        System.out.println(painting);
        System.out.println(maxArea);

    }

    static int bfs(int x, int y) {
        queue.offer(new int[] {x,y});
        visited[x][y] = true;
        int size = 1;

        while(!queue.isEmpty()) {
            int[] current = queue.poll();
            int cx = current[0];
            int cy = current[1];

            for(int i=0; i<4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(nx <0 || ny <0 || nx > n-1 || ny > m-1) continue;
                if(visited[nx][ny]) continue;
                if(map[nx][ny] == 1) {
                    size++;
                    visited[nx][ny] = true;
                    queue.offer(new int[] {nx,ny});
                }
            }
        }
        return size;
    }
}
