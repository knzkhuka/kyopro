int main() {
  int n;
  cin >> n;
  vector<i64> a(n + 1), b(n);
  cin >> a >> b;
  auto c = a;
  rep(i, n) {
    if (b[i] >= a[i]) {
      b[i] -= a[i];
      a[i] = 0;
    } else {
      a[i] -= b[i];
      b[i] = 0;
    }
    if (b[i] >= a[i + 1]) {
      b[i] -= a[i + 1];
      a[i + 1] = 0;
    } else {
      a[i + 1] -= b[i];
      b[i] = 0;
    }
  }
  i64 ans = 0;
  rep(i, n + 1) ans += c[i] - a[i];
  cout << (ans) << endl;
}