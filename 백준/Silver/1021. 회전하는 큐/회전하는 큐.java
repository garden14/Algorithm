
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        LinkedList<Integer> queue = new LinkedList<>();

        for (int i = 1; i <= n; i++) {
            queue.offer(i);
        }

        int count = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            int num = Integer.parseInt(st.nextToken());

            while (queue.getFirst() != num) {
                if (queue.indexOf(num) <= queue.size() / 2) {
                    queue.addLast(queue.getFirst());
                    queue.removeFirst();
                } else {
                    queue.addFirst(queue.getLast());
                    queue.removeLast();
                }
                count++;
            }
            if (queue.getFirst() == num) {
                queue.removeFirst();
            }
        }

        System.out.println(count);

    }
}
