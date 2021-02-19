int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
  }
  int s, t;
  cin >> s >> t;
  s--, t--;
  auto dist = vec<int>(3, n);
  for (auto &di : dist)
    for (auto &d : di)
      d = inf;
  dist[0][s] = 0;
  queue<pii> que;
  que.emplace(0, s);
  while (!que.empty()) {
    auto [k, v] = que.front();
    que.pop();
    int nk = (k + 1) % 3;
    for (auto nv : adj[v]) {
      if (nk > k) {
        if (chmin(dist[nk][nv], dist[k][v]))
          que.emplace(nk, nv);
      } else {
        if (chmin(dist[nk][nv], dist[k][v] + 1))
          que.emplace(nk, nv);
      }
    }
  }
  int ans = dist[0][t] == inf ? -1 : dist[0][t];
  cout << (ans) << endl;
}