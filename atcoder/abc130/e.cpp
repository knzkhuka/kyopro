int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  cin >> a >> b;
  // mod = 1000000007
  auto dp = vec<mint>(n + 1, m + 1);
  auto sum = vec<mint>(n + 1, m + 1);
  rep(i, n) rep(j, m) {
    sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
    if (a[i] == b[j]) {
      dp[i + 1][j + 1] = sum[i][j] + 1;
      sum[i + 1][j + 1] += dp[i + 1][j + 1];
    }
  }
  for (auto x : sum)
    dout << x << newl;
  for (auto x : dp)
    dout << x << newl;
  mint ans = 1;
  rep(i, n + 1) rep(j, m + 1) ans += dp[i][j];
  cout << (ans) << endl;
}