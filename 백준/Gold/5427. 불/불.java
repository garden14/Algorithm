import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int w, h;
    static char[][] map;
    static boolean[][] visited;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static Queue<int[]> sangGeun;
    static Queue<int[]> fire;
    static int answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());
            map = new char[h][w];
            visited = new boolean[h][w];
            sangGeun = new LinkedList<>();
            fire = new LinkedList<>();

            for (int i = 0; i < h; i++) {
                String line = br.readLine();
                for (int j = 0; j < w; j++) {
                    char c = line.charAt(j);
                    map[i][j] = c;
                    if (c == '@') {
                        sangGeun.offer(new int[]{j, i, 0});
                        visited[i][j] = true;
                    } else if (c == '*') {
                        fire.offer(new int[]{j, i});
                    }
                }
            }

            answer = 0;
            bfs();

            if (answer == 0) {
                sb.append("IMPOSSIBLE\n");
            } else {
                sb.append(answer).append("\n");
            }
        }
        System.out.println(sb);
    }

    static void bfs() {
        while (!sangGeun.isEmpty()) {
            int fireSize = fire.size();
            for (int i = 0; i < fireSize; i++) {
                int[] current = fire.poll();

                for (int j = 0; j < 4; j++) {
                    int nx = current[0] + dx[j];
                    int ny = current[1] + dy[j];

                    if (nx >= 0 && ny >= 0 && nx < w && ny < h && (map[ny][nx] == '.')) {
                        map[ny][nx] = '*';
                        fire.offer(new int[]{nx, ny});
                    }
                }
            }

            int size = sangGeun.size();
            for (int k = 0; k < size; k++) {
                int[] current = sangGeun.poll();

                for (int j = 0; j < 4; j++) {
                    int nx = current[0] + dx[j];
                    int ny = current[1] + dy[j];

                    if (nx < 0 || ny < 0 || nx >= w || ny >= h) {
                        answer = current[2] + 1;
                        return;
                    }

                    if (!visited[ny][nx] && map[ny][nx] == '.') {
                        visited[ny][nx] = true;
                        sangGeun.offer(new int[]{nx, ny, current[2] + 1});
                    }
                }
            }
        }
    }
}
