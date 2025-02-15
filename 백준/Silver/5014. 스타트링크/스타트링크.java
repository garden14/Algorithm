
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int f, s, g;
    static int[] stairs;
    static boolean[] visited;
    static int[] move = new int[2];

    static public void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        f = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());
        g = Integer.parseInt(st.nextToken());
        move[0] = Integer.parseInt(st.nextToken()); 
        move[1] = -Integer.parseInt(st.nextToken()); 

        stairs = new int[f + 1];
        visited = new boolean[f + 1];

        if (Math.abs(move[0]) < Math.abs(move[1])) {
            int temp = move[0];
            move[0] = move[1];
            move[1] = temp;
        }

        bfs(s);
    }

    static void bfs(int start) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(start);
        visited[start] = true;
        stairs[start] = 0;

        while (!queue.isEmpty()) {
            int loc = queue.poll();
            if (loc == g) {
                System.out.println(stairs[loc]);
                return;
            }

            for (int i = 0; i < 2; i++) {
                int next = loc + move[i];

                if (next > f || next < 1) {
                    continue;
                }
                if (!visited[next]) {
                    visited[next] = true;
                    queue.add(next);
                    stairs[next] = stairs[loc] + 1;
                }
            }
        }

        System.out.println("use the stairs");
    }
}
