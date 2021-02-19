int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pll>> adj(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].emplace_back(b, 1);
    adj[b].emplace_back(a, 1);
  }
  int k;
  cin >> k;
  vector<int> c(k);
  rep(i, k) cin >> c[i], c[i]--;

  auto dijkstra = [](auto const &adj, int s) {
    int n = adj.size();
    vector<i64> dist(n, INF);
    priority_queue<pll, vector<pll>, greater<>> que;
    dist[s] = 0;
    que.emplace(0, s);
    while (!que.empty()) {
      auto [c, v] = que.top();
      que.pop();
      for (auto [nv, nc] : adj[v]) {
        if (chmin(dist[nv], dist[v] + nc))
          que.emplace(dist[nv], nv);
      }
    }
    return dist;
  };

  vector<vector<i64>> dist(k);
  rep(i, k) dist[i] = dijkstra(adj, c[i]);

  vector<vector<i64>> dp(k);
  for (auto &dpi : dp)
    dpi = vector<i64>(1 << k, INF);
  rep(i, k) dp[i][1 << i] = 0;
  rep(S, 1 << k) {
    rep(u, k) rep(v, k) if ((S >> v) & 1) {
      chmin(dp[u][S | (1 << u)], dp[v][S] + dist[v][c[u]]);
    }
  }
  i64 ans = INF;
  rep(i, k) chmin(ans, dp[i].back());
  cout << (ans == INF ? -1 : ans + 1) << endl;
}
