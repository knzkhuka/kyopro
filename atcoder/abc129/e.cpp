int main() {
  string s;
  cin >> s;
  int n = size(s);
  auto dp = vec<mint>(2, n + 1);
  dp[1][0] = 1;
  rep(i, n) {
    dp[0][i + 1] += dp[0][i] * 3;
    if (s[i] == '1') {
      dp[0][i + 1] += dp[1][i];
      dp[1][i + 1] += dp[1][i] * 2;
    }
    if (s[i] == '0') {
      dp[1][i + 1] += dp[1][i];
    }
  }
  mint ans = dp[0][n] + dp[1][n];
  cout << (ans) << endl;
}