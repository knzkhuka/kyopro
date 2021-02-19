int main() {
  int n;
  cin >> n;
  vector<int> w(n);
  cin >> w;
  vector<int> sum(n + 1);
  rep(i, n) sum[i + 1] = sum[i] + w[i];
  int ans = inf;
  for (int i = 1; i < n; ++i) {
    int s1 = sum[i];
    int s2 = sum[n] - sum[i];
    chmin(ans, abs(s1 - s2));
  }
  cout << (ans) << endl;
}