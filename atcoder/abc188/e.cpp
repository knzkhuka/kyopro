int main() {
  int n, m;
  cin >> n >> m;
  vector<i64> a(n);
  cin >> a;
  vector<vector<int>> adj(n), radj(n);
  vector<int> in_deg(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    radj[v].emplace_back(u);
    in_deg[v]++;
  }
  stack<int> st;
  vector<int> ushi;
  rep(i, n) if (in_deg[i] == 0) st.emplace(i);
  while (!st.empty()) {
    int v = st.top();
    st.pop();
    ushi.emplace_back(v);
    for (auto nv : adj[v]) {
      in_deg[nv]--;
      if (in_deg[nv] == 0)
        st.emplace(nv);
    }
  }
  vector<i64> acc_min(n, INF), acc_max(n, -INF);
  for (int i : ushi) {
    for (int v : adj[i]) {
      chmin(acc_min[v], min(acc_min[i], a[i]));
    }
  }
  reverse(begin(ushi), end(ushi));
  for (int i : ushi) {
    chmax(acc_max[i], a[i]);
    for (int v : radj[i]) {
      chmax(acc_max[v], acc_max[i]);
    }
  }
  i64 ans = -INF;
  rep(i, n) chmax(ans, acc_max[i] - acc_min[i]);
  dout << acc_max << newl << acc_min << newl;
  cout << (ans) << endl;
}
