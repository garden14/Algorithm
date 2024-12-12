import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, M, V;
    static boolean[][] graph;
    static boolean[] visited;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());

        graph = new boolean[N+1][N+1];
        visited = new boolean[N+1];

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            graph[u][v] = true;
            graph[v][u] = true;
        }


        dfs(V);
        sb.append("\n");

        visited = new boolean[N + 1];

        bfs(V);
        System.out.println(sb);
    }

    static void dfs(int node) {
        visited[node] = true;
        sb.append(node).append(" ");
        for (int i = 1; i <= N; i++) {
            if (graph[node][i] && !visited[i]) {
                dfs(i);
            }
        }
    }

    static void bfs(int node) {
        visited[node] = true;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(node);

        while(!queue.isEmpty()) {
            int a = queue.poll();
            sb.append(a).append(" ");

            for (int i = 1; i <= N; i++) {
                if (graph[a][i] && !visited[i]) {
                    queue.add(i);
                    visited[i] = true;
                }
            }
        }

    }
}
