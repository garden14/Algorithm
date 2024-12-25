import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Main {
    static public void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        String[] alpha = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

        for (String a : alpha) {
            if (line.contains(a)) {
                line = line.replace(a, "@");
            }
        }

        System.out.println(line.length());


    }
}
