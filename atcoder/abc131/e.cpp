int main() {
  int n, k;
  cin >> n >> k;

  if (n == 2 and k == 0) {
    cout << 1 << newl;
    cout << "1 2" << newl;
    return 0;
  }
  int cur = (n - 2) * (n - 1) / 2;
  vector<pii> edge;
  rep(i, n - 1) edge.emplace_back(1 + i, n);
  int u = 1, v = n - 1;
  while (cur > k) {
    edge.emplace_back(u, v);
    cur--;
    v--;
    if (u == v) {
      u++;
      v = n - 1;
    }
  }
  if (cur != k) {
    cout << -1 << newl;
    return 0;
  }
  cout << size(edge) << newl;
  for (auto [u, v] : edge)
    cout << u << " " << v << newl;
}