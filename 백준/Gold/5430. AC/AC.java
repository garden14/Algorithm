
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

import java.util.StringTokenizer;


public class Main {
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++) {
            String p = br.readLine();
            int n = Integer.parseInt(br.readLine());

            ArrayDeque<Integer> deque = new ArrayDeque<>();
            st = new StringTokenizer(br.readLine(), "[],");

            for (int j = 0; j < n; j++) {
                deque.offer(Integer.parseInt(st.nextToken()));
            }

            doAC(deque, p);
        }
        System.out.println(sb);
    }

    public static void doAC(ArrayDeque<Integer> deque, String command) {
        boolean isRight = true;

        for (char cmd : command.toCharArray()) {
            if (cmd == 'R') {
                isRight = !isRight;
                continue;
            }

            if (isRight) {
                if (deque.pollFirst() == null) {
                    sb.append("error" + "\n");
                    return;
                }
            } else {
                if (deque.pollLast() == null) {
                    sb.append("error" + "\n");
                    return;
                }
            }
        }

        makeResult(deque, isRight);
    }

    public static void makeResult(ArrayDeque<Integer> deque, boolean isRight) {
        sb.append('[');
        if (!deque.isEmpty()) {
            if (isRight) {
                sb.append(deque.pollFirst());

                while (!deque.isEmpty()) {
                    sb.append(',').append(deque.pollFirst());
                }
            } else {
                sb.append(deque.pollLast());

                while (!deque.isEmpty()) {
                    sb.append(',').append(deque.pollLast());
                }
            }
        }
        sb.append(']').append('\n');
    }
}

