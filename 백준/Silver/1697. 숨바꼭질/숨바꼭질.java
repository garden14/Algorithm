import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static final int MAX = 100000;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] times = new int[MAX + 1];

        Queue<Integer> queue = new LinkedList<>();
        queue.add(N);
        times[N] = 0;

        while (!queue.isEmpty()) {
            int current = queue.poll();

            if (current == K) {
                System.out.println(times[current]);
                return;
            }

            for (int next : new int[]{current - 1, current + 1, current * 2}) {
                if (next >= 0 && next <= MAX && times[next] == 0) {
                    queue.add(next);
                    times[next] = times[current] + 1;
                }
            }
        }


    }
}
