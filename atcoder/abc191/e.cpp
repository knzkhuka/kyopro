int main() {
  int n, m;
  cin >> n >> m;
  vector mat(n, vector<int>(n, inf));
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    chmin(mat[a][b], c);
  }
  vector<vector<pii>> adj(n);
  rep(i, n) rep(j, n) if (mat[i][j] != inf) adj[i].emplace_back(j, mat[i][j]);
  rep(i, n) {
    priority_queue<pii, vector<pii>, greater<>> que;
    vector<int> dist(n, inf);
    for (auto [to, cost] : adj[i]) {
      que.emplace(cost, to);
      dist[to] = cost;
    }
    while (!que.empty()) {
      auto [c, v] = que.top();
      que.pop();
      for (auto [to, cost] : adj[v]) {
        if (chmin(dist[to], c + cost))
          que.emplace(c + cost, to);
      }
    }
    cout << (dist[i] == inf ? -1 : dist[i]) << newl;
  }
}
