import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static Map<Integer, List<Integer>> graph = new HashMap<>();
    static int N;

    static public void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            graph.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            graph.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        int minKevinBacon = Integer.MAX_VALUE;
        int result = 0;

        for (Map.Entry<Integer, List<Integer>> entry : graph.entrySet()) {
            int kevinBacon = bfs(entry.getKey());
            if (kevinBacon < minKevinBacon) {
                minKevinBacon = kevinBacon;
                result = entry.getKey();
            }
        }

        System.out.println(result);

    }

    static int bfs(int v) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[N+1];
        int[] distance = new int[N+1];
        int totalDistance = 0;

        queue.add(v);
        visited[v] = true;

        while (!queue.isEmpty()) {
            int node = queue.poll();

            for (int neighbor : graph.get(node)) {
                if (!visited[neighbor]) {
                    queue.add(neighbor);
                    visited[neighbor] = true;
                    distance[neighbor] = distance[node] + 1;
                    totalDistance += distance[neighbor];
                }
            }
        }
        return totalDistance;
    }
}
