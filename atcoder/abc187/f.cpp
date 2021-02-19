int main() {
  int n, m;
  cin >> n >> m;
  vector<int> adj(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u] |= 1 << v;
    adj[v] |= 1 << u;
  }
  vector<int> dp(1 << n, inf);
  rep(b, 1 << n) {
    bool kn = true;
    rep(i, n) if ((b >> i) & 1) { kn &= ((adj[i] | (1 << i)) & b) == b; }
    if (kn)
      dp[b] = 1;
  }

  rep(S, 1 << n) for (int T = S; --T &= S;) { chmin(dp[S], dp[S ^ T] + dp[T]); }
  cout << (dp[(1 << n) - 1]) << endl;
}