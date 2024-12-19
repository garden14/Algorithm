import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static public void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        int[] sorted = new int[N];
        HashMap<Integer, Integer> map = new HashMap<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = sorted[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(sorted);

        int rank = 0;

        for (int a : sorted) {
            if (!map.containsKey(a)) {
                map.put(a, rank);
                rank++;
            }
        }

        StringBuilder sb = new StringBuilder();

        for (int key : arr) {
            int result = map.get(key);
            sb.append(result).append(" ");
        }

        System.out.println(sb);

    }
}
