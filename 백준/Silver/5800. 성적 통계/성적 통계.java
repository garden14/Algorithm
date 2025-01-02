import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int k = Integer.parseInt(br.readLine());

        for (int i = 0; i < k; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            ArrayList<Integer> list = new ArrayList<>();

            for (int j = 0; j < n; j++) {
                list.add(Integer.parseInt(st.nextToken()));
            }

            Collections.sort(list, Collections.reverseOrder());

            int maxGap = 0;

            for(int l = 0; l < n-1; l++) {
                int gap = list.get(l)- list.get(l+1);
                if (maxGap < gap) {
                    maxGap = gap;
                }
            }

            sb.append("Class " + (i + 1) + "\n");
            sb.append("Max " + Collections.max(list) + ", ");
            sb.append("Min " + Collections.min(list) + ", ");
            sb.append("Largest gap " + maxGap + "\n");
        }

        System.out.println(sb);
    }
}
