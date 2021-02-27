int main() {
  int n, k;
  cin >> n >> k;
  auto dist = vec<int>(n, n);
  cin >> dist;
  vector<int> idx(n - 1);
  iota(begin(idx), end(idx), 1);
  int ans = 0;
  do {
    int tmp = dist[0][idx[0]];
    rep(i, n - 2) tmp += dist[idx[i]][idx[i + 1]];
    tmp += dist[idx[n - 2]][0];
    ans += tmp==k;
  } while (next_permutation(begin(idx), end(idx)));
  cout << (ans) << endl;
}
