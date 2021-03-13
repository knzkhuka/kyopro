int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  int ans = inf;
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, n) rep(j, n) {
    if (i == j)
      chmin(ans, a[i] + b[j]);
    else {
      chmin(ans, max(a[i], b[j]));
    }
  }
  cout << (ans) << endl;
}
