import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static int[] fruits;

    static public void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        fruits = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++) {
            fruits[i] = Integer.parseInt(st.nextToken());
        }

        HashMap<Integer, Integer> cnt = new HashMap<>();
        int max = 0;
        int left = 0;

        for(int right=0; right<N; right++) {
            cnt.put(fruits[right], cnt.getOrDefault(fruits[right],0)+1 );

            while(cnt.size()>2) {
                cnt.put(fruits[left], cnt.get(fruits[left]) - 1);

                if(cnt.get(fruits[left])==0){
                    cnt.remove(fruits[left]);
                }

                left++;
            }
            max = Math.max(max, right-left+1);
        }
        System.out.println(max);

    }
}
