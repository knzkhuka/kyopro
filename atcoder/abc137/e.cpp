int main() {
  int n, m, p;
  cin >> n >> m >> p;
  vector<tuple<int, int, i64>> edges(m);
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--, c -= p;
    edges[i] = {a, b, -c};
  }
  vector<i64> dist(n, INF);
  vector<int> tapu(n);
  dist[0] = 0;
  tapu[0] = 1;
  rep(i, n) for (auto const &[u, v, w] : edges) {
    chmin(dist[v], dist[u] + w);
    tapu[v] |= tapu[u];
  }
  vector<int> neglop(n);
  rep(i, n) for (auto const &[u, v, w] : edges) {
    neglop[v] |= chmin(dist[v], dist[u] + w);
    neglop[v] |= neglop[u] & tapu[u];
  }
  i64 ans = (neglop[n - 1] ? -1 : max(0_i, -dist[n - 1]));
  cout << (ans) << endl;
}
