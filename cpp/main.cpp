int main() {
  int n, m;
  cin >> n >> m;
  vector<int> adj(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a] |= 1 << b;
    adj[b] |= 1 << a;
  }
  vector<int> dp(1 << n, inf);
  rep(S, 1 << n) {
    bool kn = true;
    rep(i, n) if ((S >> i) & 1) kn &= ((adj[i] | 1 << i) & S) == S;
    if (kn)
      dp[S] = 1;
  }
  rep(S, 1 << n) {
    for (int T = S;; T = (T - 1) & S) {
      if (T == 0)
        break;
      chmin(dp[S], dp[S ^ T] + dp[T]);
    }
  }
  cout << (dp.back()) << endl;
  rep(i, 1 << n) dout << i << ":" << bitset<10>(i) << ":" << dp[i] << newl;
}