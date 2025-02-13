import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
		
        int N = Integer.parseInt(br.readLine()); 
        int[] bulb = new int[N+1];
		
        st = new StringTokenizer(br.readLine());
        for (int i=1; i<=N; i++) {
            bulb[i] = Integer.parseInt(st.nextToken());
        }
		
        int studentCnt = Integer.parseInt(br.readLine()); 
        for (int i=1; i<=studentCnt; i++) {
            st = new StringTokenizer(br.readLine());
			
            int gender = Integer.parseInt(st.nextToken()); 
            int number = Integer.parseInt(st.nextToken()); 
			
            if (gender == 1) {
                for (int j=1; j<=N; j++) {
                    if (j%number == 0) {
                        bulb[j] = bulb[j] == 0 ? 1 : 0;
                    }
                }
            } else {
                bulb[number] = bulb[number] == 0 ? 1 : 0;
                for (int j=1; j<=N/2; j++) {
                    int left = number - j;
                    int right = number + j;
					
                    if (right > N || left < 1) break;
                    
                    if (bulb[left] == bulb[right]) {
                        bulb[left] = bulb[left] == 0 ? 1 : 0;
                        bulb[right] = bulb[right] == 0 ? 1 : 0;
                    } else {
                        break;
                    }
                }
            }
        }
		
        for (int i=1; i<=N; i++) {
            System.out.print(bulb[i] + " ");
            if (i % 20 == 0) System.out.println();
        }
    }
}