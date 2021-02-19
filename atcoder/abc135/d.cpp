int main() {
  string s;
  cin >> s;
  const int n = size(s);
  const int m = 13;
  // mod = 1000000007
  vector<i64> pow10(n);
  pow10[0] = 1;
  for (int i = 1; i < n; ++i)
    pow10[i] = pow10[i - 1] * 10 % m;
  reverse(begin(pow10), end(pow10));

  auto dp = vec<mint>(n + 1, m);
  dp[0][0] = 1;
  rep(i, n) {
    if (s[i] == '?')
      rep(j, m) rep(k, 10) {
        int jk = (j + k * pow10[i]) % m;
        dp[i + 1][jk] += dp[i][j];
      }
    else {
      int k = (s[i] - '0') * pow10[i] % m;
      rep(j, m) { dp[i + 1][(j + k) % m] += dp[i][j]; }
    }
  }
  mint ans = dp[n][5];
  cout << (ans) << endl;
}