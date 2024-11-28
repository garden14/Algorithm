import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        String s = br.readLine();

        int count = 0;
        int result = 0;

        for (int i = 1; i < m - 1; i++) {
            if (s.charAt(i-1) == 'I' && s.charAt(i) == 'O' && s.charAt(i+1) == 'I') {
                count++;

                if(count == n){
                    count--;
                    result++;
                }
                i++;
            }
            else {
                count = 0;
            }
        }

        bw.write(Integer.toString(result));
        bw.flush();
        bw.close();
        br.close();
    }
}
