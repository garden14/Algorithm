import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {
    static int N;
    static int[][] map;
    static boolean[][] visited;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static List<Integer> list;

    static public void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        visited = new boolean[N][N];
        list = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(String.valueOf(line.charAt(j)));
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    list.add(bfs(i, j));
                }
            }
        }

        Collections.sort(list);
        System.out.println(list.size());
        for (int count : list) {
            System.out.println(count);
        }

    }

    static int bfs(int x, int y) {
        int sum = 1;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{x, y});
        visited[x][y] = true;

        while (!queue.isEmpty()) {
            int current[] = queue.poll();
            int nx = current[0];
            int ny = current[1];

            for (int i = 0; i < 4; i++) {
                int nextX = nx + dx[i];
                int nextY = ny + dy[i];

                if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
                    if (!visited[nextX][nextY] && map[nextX][nextY] == 1) {
                        queue.add(new int[]{nextX, nextY});
                        visited[nextX][nextY] = true;
                        sum++;
                    }
                }
            }
        }
        return sum;
    }
}
