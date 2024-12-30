
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());
        int[][] schedule = new int[N][2];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            schedule[i][0] = Integer.parseInt(st.nextToken());
            schedule[i][1] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(schedule, (a, b) ->{
            if(a[1]==b[1]) return a[0] - b[0];
            return a[1] - b[1];
        });

        int count = 0;
        int end = 0;

        for(int[] sche : schedule) {
            if(sche[0] >= end) {
                count++;
                end = sche[1];
            }
        }

        System.out.println(count);
    }
}
