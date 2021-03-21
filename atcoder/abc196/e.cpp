int main() {
  int n;
  cin >> n;
  vector<i64> a(n), t(n);
  rep(i, n) cin >> a[i] >> t[i];
  int q;
  cin >> q;
  vector<i64> x(q);
  cin >> x;

  i64 add = 0;
  i64 low = -1e10;
  i64 high = 1e10;
  rep(i, n) {
    if (t[i] == 1)
      add += a[i];
    if (t[i] == 2) {
      chmax(low, a[i] - add);
      chmax(high, a[i] - add);
    }
    if (t[i] == 3) {
      chmin(high, a[i] - add);
      chmin(low, a[i] - add);
    }
  }
  for (auto xi : x) {
    i64 ans = xi;
    if (xi < low)
      ans = low;
    else if (high < xi)
      ans = high;
    cout << ans + add << newl;
  }
}
