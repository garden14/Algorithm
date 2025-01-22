
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine());
            TreeMap<Integer, Integer> treeMap = new TreeMap<>();

            while (k-- > 0) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String operation = st.nextToken();
                int n = Integer.parseInt(st.nextToken());

                if (operation.equals("I")) {
                    treeMap.put(n, treeMap.getOrDefault(n, 0) + 1);
                } else {
                    if (!treeMap.isEmpty()) {
                        int key = (n == 1) ? treeMap.lastKey() : treeMap.firstKey();
                        if (treeMap.put(key, treeMap.get(key) - 1) == 1) {
                            treeMap.remove(key);
                        }
                    }
                }
            }
            if (treeMap.isEmpty()) {
                System.out.println("EMPTY");
            } else {
                System.out.println(treeMap.lastKey() + " " + treeMap.firstKey());
            }
        }

    }
}
