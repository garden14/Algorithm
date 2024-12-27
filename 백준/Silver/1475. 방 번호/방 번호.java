import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        HashMap<Integer, Integer> hashMap = new HashMap<>();

        while (N > 0) {
            int digit = N % 10;
            if (digit == 6) {
                hashMap.put(9, hashMap.getOrDefault(9, 0) + 1);
            } else {
                hashMap.put(digit, hashMap.getOrDefault(digit, 0) + 1);
            }
            N /= 10;
        }

        if (hashMap.containsKey(9)) {
            int cal = hashMap.get(9);
            if (cal > 1) {
                hashMap.put(9, (cal + 1) / 2);
            }
        }

        System.out.println(Collections.max(hashMap.values()));
    }
}
