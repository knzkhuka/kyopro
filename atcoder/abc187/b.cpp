int main() {
  int n;
  cin >> n;
  vector<double> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  vector<int> idx(n);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) { return x[i] < x[j]; });
  int ans = 0;
  rep(i, n) for (int j = i + 1; j < n; ++j) {
    double dx = x[idx[j]] - x[idx[i]];
    double dy = y[idx[j]] - y[idx[i]];
    double t = dy / dx;
    if (-1 <= t and t <= 1)
      ans++;
  }
  cout << (ans) << endl;
}
