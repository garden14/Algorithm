import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int[] tree;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        tree = new int[N];

        int low = 0;
        int high = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            tree[i] = Integer.parseInt(st.nextToken());
            if (high < tree[i]) {
                high = tree[i];
            }
        }

        while (low < high) {
            int mid = (low + high) / 2;
            long sum = 0;
            for (int height : tree) {
                if (height - mid > 0) {
                    sum += (height) - mid;
                }
            }

            if (sum < M) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        System.out.println(low - 1);

    }

}
