int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  x--, y--;
  using T3 = tuple<int, i64, i64>;
  vector<vector<T3>> adj(n);
  rep(i, m) {
    int a, b;
    i64 t, k;
    cin >> a >> b >> t >> k;
    a--, b--;
    adj[a].emplace_back(b, t, k);
    adj[b].emplace_back(a, t, k);
  }
  auto dijkstra = [](auto const &adj, int s) {
    int n = adj.size();
    vector<i64> dist(n, INF);
    priority_queue<pll, vector<pll>, greater<>> que;
    dist[s] = 0;
    que.emplace(0, s);
    while (!que.empty()) {
      auto [c, v] = que.top();
      que.pop();
      for (auto [nv, t, k] : adj[v]) {
        i64 nxt = (k - dist[v] % k) % k;
        if (chmin(dist[nv], dist[v] + t + nxt))
          que.emplace(dist[nv], nv);
      }
    }
    return dist;
  };
  auto dist = dijkstra(adj, x);
  auto ans = dist[y];
  cout << (ans == INF ? -1 : ans) << endl;
}
