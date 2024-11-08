#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 2;
const int INF = LLONG_MAX;
vector<pair<int, int>> graph[N];
vector<int> dist (N, INF);

void dijkstra (int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push ({0, source});

    while (!pq.empty ()) {
        int d = pq.top ().first;
        int v = pq.top ().second;
        pq.pop ();

        if (d != dist[v])
            continue;

        for (auto edge : graph[v]) {
            int to = edge.first;
            int weight = edge.second;

            if (dist[v] + weight < dist[to]) {
                dist[to] = dist[v] + weight;
                pq.push ({dist[to], to});
            }
        }
    }
}

int32_t main () {
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    int n, m;
    cin >> n >> m;  // Number of nodes and edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back ({v, w});
        graph[v].push_back ({u, w});  // For undirected graph, add both directions
    }

    int source;
    cin >> source;

    dijkstra (source);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "Node " << i << ": Unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << '\n';
        }
    }

    return 0;
}
