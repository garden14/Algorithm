

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static public void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int cnt = 1;
        int d = 10;
        int result = 0;

        for (int i = 1; i <= n; i++) {
            if (i % d == 0) {
                cnt++;
                d *= 10;
            }
            result += cnt;
        }
        
        System.out.println(result);
    }
}
