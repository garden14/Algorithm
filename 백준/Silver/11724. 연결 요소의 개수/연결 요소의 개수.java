import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static boolean[][] graph;
    static boolean[] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        graph = new boolean[N+1][N+1];
        visited = new boolean[N+1];

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            graph[u][v] = true;
            graph[v][u] = true;
        }

        int result = 0;

        for(int i=1; i<=N; i++) {
            if(!visited[i]) {
                dfs(i);
                result++;
            }
        }

        System.out.println(result);
    }

    static void dfs(int node) {
        if (visited[node]) return;
        else {
            visited[node] = true;
            for (int i = 1; i <= N; i++) {
                if (graph[node][i]) {
                    dfs(i);
                }
            }
        }
    }
}
