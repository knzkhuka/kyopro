int main() {
  int n, d;
  cin >> n >> d;
  auto x = vec<double>(n, d);
  cin >> x;
  int ans = 0;
  rep(i, n) for (int j = i + 1; j < n; ++j) {
    const auto &y = x[i];
    const auto &z = x[j];
    double dist = 0.0;
    rep(k, d) dist += (y[k] - z[k]) * (y[k] - z[k]);
    double dist2 = sqrt(dist);
    int ushi = dist2;
    int tapu = dist;
    if (ushi * ushi == tapu)
      ans++;
  }
  cout << (ans) << endl;
}