import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Map<String, List<String>> groupMap = new HashMap<>();
        Map<String, String> memberMap = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String groupName = br.readLine();
            int num = Integer.parseInt(br.readLine());

            List<String> members = new ArrayList<>();
            for (int j = 0; j < num; j++) {
                String member = br.readLine();
                members.add(member);
                memberMap.put(member, groupName);
            }
            Collections.sort(members);
            groupMap.put(groupName, members);
        }

        for (int i = 0; i < m; i++) {
            String quiz = br.readLine();
            int type = Integer.parseInt(br.readLine());

            if (type == 1) {
                sb.append(memberMap.get(quiz)).append("\n");
            } else {
                for (String member : groupMap.get(quiz)) {
                    sb.append(member).append("\n");
                }
            }
        }

        System.out.print(sb);
    }
}
