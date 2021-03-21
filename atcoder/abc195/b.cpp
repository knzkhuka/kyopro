signed main() {
  i64 a, b, w;
  cin >> a >> b >> w;
  w *= 1000;
  i64 ansmin = inf, ansmax = -inf;
  for (i64 i = 1; i < 100000000; ++i) {
    if (a * i <= w and w <= b * i) {
      chmin(ansmin, i);
      chmax(ansmax, i);
    }
  }
  if (ansmin == inf)
    cout << "UNSATISFIABLE" << endl;
  else
    cout << ansmin << " " << ansmax << endl;
}
