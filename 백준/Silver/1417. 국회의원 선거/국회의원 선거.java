
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int win = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 1; i < n; i++) {
            queue.offer(Integer.parseInt(br.readLine()));
        }

        int count = 0;

        while (!queue.isEmpty() && queue.peek() >= win) {
            win++;
            queue.offer(queue.poll() - 1);
            count++;
        }

        System.out.println(count);
    }
}
