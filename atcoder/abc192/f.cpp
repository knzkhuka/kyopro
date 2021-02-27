int main() {
  i64 n, x;
  cin >> n >> x;
  vector<i64> a(n);
  cin >> a;

  auto solve = [&](int k) {
    auto dp = vec<i64>(k + 1, k + 1);
    rep(i, k + 1) rep(j, k + 1) dp[i][j] = j == 0 ? 0 : -INF;
    rep(i, n) {
      for (int j = min(k, i + 1); j-- > 0;) {
        for (int s = 0; s < k; ++s) {
          chmax(dp[j + 1][(s + a[i]) % k], dp[j][s] + a[i]);
        }
      }
    }
    i64 sum = dp[k][x % k];
    dout << sum << " " << k << " " << (x - sum) / k << newl;
    return sum <= 0 ? INF : (x - sum) / k;
  };

  i64 ans = INF;
  for (int k = 1; k <= n; ++k)
    chmin(ans, solve(k));
  cout << (ans) << endl;
}
