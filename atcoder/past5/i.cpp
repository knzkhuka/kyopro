int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> h(n);
  vector<int> c(k);
  cin >> h >> c;
  vector<vector<int>> adj(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (h[a] > h[b])
      swap(a, b);
    adj[a].emplace_back(b);
  }
  queue<int> que;
  vector<int> dist(n, inf);
  for (auto &ci : c) {
    ci--;
    que.emplace(ci);
    dist[ci] = 0;
  }
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto nv : adj[v]) {
      if (chmin(dist[nv], dist[v] + 1))
        que.emplace(nv);
    }
  }
  for (auto x : dist)
    cout << (x == inf ? -1 : x) << newl;
}
