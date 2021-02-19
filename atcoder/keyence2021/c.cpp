int main() {
  // mod = 998244353
  int h, w, k;
  cin >> h >> w >> k;
  vector<map<int, char>> mem(h);
  rep(i, k) {
    int h, w;
    char c;
    cin >> h >> w >> c;
    h--, w--;
    mem[h][w] = c;
  }
  auto dp = vec<mint>(h + 1, w + 1);
  dp[0][0] = 1;
  rep(i, h) rep(j, w) {
    if (mem[i].count(j)) {
      if (mem[i][j] == 'X')
        dp[i][j + 1] += dp[i][j], dp[i + 1][j] += dp[i][j];
      if (mem[i][j] == 'R')
        dp[i][j + 1] += dp[i][j];
      if (mem[i][j] == 'D')
        dp[i + 1][j] += dp[i][j];
    } else {
      dp[i + 1][j] += dp[i][j] * 2;
      dp[i][j + 1] += dp[i][j] * 2;
    }
  }
  cout << (dp[h][w]) << endl;
  for (auto x : dp)
    dout << x << newl;
}
