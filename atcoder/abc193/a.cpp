int main() {
  double a, b;
  cin >> a >> b;
  double low = 0.0, high = 100.0;
  rep(i, 1000) {
    double mid = (high + low) / 2.0;
    (a / 100.0 * mid > b ? high : low) = mid;
  }
  cout << (100.0 - low) << endl;
}
