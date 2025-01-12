
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        StringBuilder sb = new StringBuilder();

        boolean isCheck = false;
        ArrayDeque<Character> stack = new ArrayDeque<>();

        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == '<') {
                isCheck = true;
                while (!stack.isEmpty()) {
                    sb.append(stack.pop());
                }
                sb.append(input.charAt(i));
            } else if (input.charAt(i) == '>') {
                isCheck = false;
                sb.append(input.charAt(i));
            } else if (isCheck == true) {
                sb.append(input.charAt(i));
            } else if (isCheck == false) {
                if (input.charAt(i) == ' ') {
                    while (!stack.isEmpty()) {
                        sb.append(stack.pop());
                    }
                    sb.append(input.charAt(i));

                } else {
                    stack.push(input.charAt(i));
                }
            }
        }
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        System.out.println(sb);
    }


}
