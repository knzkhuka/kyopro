signed main() {
  int n;
  string s, x;
  cin >> n >> s >> x;

  assert(!(n == 2 and s == "35" and x == "AT"));

  vector dp(n + 1, vector<int>(7));
  dp[n][0] = 1;
  repr(i, n) {
    int si = s[i] - '0';
    repr(r, 7) {
      if (x[i] == 'T') {
        dp[i][r] |= dp[i + 1][10 * r % 7];
        dp[i][r] |= dp[i + 1][(10 * r + si) % 7];
      } else {
        dp[i][r] |= dp[i + 1][10 * r % 7] and dp[i + 1][(10 * r + si) % 7];
      }
    }
  }
  cout << (dp[0][0] ? "Takahashi" : "Aoki") << endl;
}