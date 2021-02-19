int main() {
  int n;
  cin >> n;
  const int v = 4e5 + 1;
  vector<vector<int>> adj(v);
  union_find<int> uni(v);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    uni.unite(a, b);
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }
  vector<bool> seen(v);
  vector<int> root_v(v, -1);
  auto iscycle = [&](auto &&self, int cur, int prv, int root) -> bool {
    if (seen[cur])
      return true;
    seen[cur] = true;
    root_v[cur] = root;
    bool flag = false;
    for (auto to : adj[cur]) {
      if (to == prv)
        continue;
      flag |= self(self, to, cur, root);
    }
    return flag;
  };
  int ans = 0;
  rep(i, v) if (!seen[i] and size(adj[i])) {
    if (!iscycle(iscycle, i, -1, i)) {
      ans += uni.size(i) - 1;
    } else
      ans += uni.size(i);
  }
  cout << (ans) << endl;
}