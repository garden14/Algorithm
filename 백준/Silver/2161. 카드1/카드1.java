
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        ArrayDeque<Integer> arrayDeque = new ArrayDeque<>();

        for (int i = 1; i <= N; i++) {
            arrayDeque.offerLast(i);
        }

        while (!arrayDeque.isEmpty()) {
            Integer first = arrayDeque.pollFirst();
            sb.append(first).append(" ");
            Integer last = arrayDeque.pollFirst();
            if (last != null) {
                arrayDeque.offerLast(last);
            }
        }

        bw.write(String.valueOf(sb));
        bw.flush();
        bw.close();
        br.close();

    }
}
