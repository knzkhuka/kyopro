int main() {
  int n;
  mint k;
  cin >> n >> k;
  vector<vector<int>> adj(n);
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  // mod = 1000000007
  vector<bool> seen(n, false);
  vector<mint> color(n, k);
  vector<mint> deg(n, 0);
  queue<int> que;
  que.emplace(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    mint tmp = 0;
    for (auto nv : adj[v]) {
      if (!seen[nv]) {
        que.emplace(nv);
      }
      tmp += (mint)seen[nv];
      tmp += deg[nv];
      deg[nv] += 1;
    }
    color[v] -= tmp;
    seen[v] = true;
  }
  dout << color << newl;
  mint ans = 1;
  rep(i, n) ans *= color[i];
  cout << (ans) << endl;
}