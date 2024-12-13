import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    static int N;
    static PriorityQueue<Integer> queue;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        queue = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            int x = Integer.parseInt(br.readLine());

            if (x == 0) {
                if (queue.isEmpty()) {
                    System.out.println("0");
                }
                else {
                    System.out.println(queue.poll());
                }
            }
            else {
                queue.add(x);
            }
        }
    }
}
