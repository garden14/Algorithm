

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int[][][] tomato;
    static int H, N, M;
    static int[] dz = {-1, 1, 0, 0, 0, 0};
    static int[] dx = {0, 0, -1, 1, 0, 0};
    static int[] dy = {0, 0, 0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        tomato = new int[H][N][M];
        Queue<int[]> queue = new LinkedList<>();
        int initialZeroCount = 0; // 초기 익지 않은 토마토 개수

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < N; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < M; k++) {
                    tomato[i][j][k] = Integer.parseInt(st.nextToken());
                    if (tomato[i][j][k] == 1) {
                        queue.offer(new int[]{i, j, k}); // 익은 토마토 큐에 추가
                    } else if (tomato[i][j][k] == 0) {
                        initialZeroCount++; // 익지 않은 토마토 카운트
                    }
                }
            }
        }

        if (initialZeroCount == 0) {
            System.out.println(0);
            return;
        }

        int result = bfs(queue);

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    if (tomato[i][j][k] == 0) {
                        System.out.println(-1);
                        return;
                    }
                }
            }
        }

        System.out.println(result);
    }

    static int bfs(Queue<int[]> queue) {
        int maxDays = 0;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int cz = current[0];
            int cx = current[1];
            int cy = current[2];

            for (int i = 0; i < 6; i++) {
                int nz = cz + dz[i];
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (nz >= 0 && nz < H && nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    if (tomato[nz][nx][ny] == 0) { // 익지 않은 토마토만 처리
                        tomato[nz][nx][ny] = tomato[cz][cx][cy] + 1; // 날짜 기록
                        maxDays = Math.max(maxDays, tomato[nz][nx][ny]);
                        queue.offer(new int[]{nz, nx, ny});
                    }
                }
            }
        }

        return maxDays - 1; 
    }
}
