int main() {
  int n;
  cin >> n;
  vector<i64> a(n), b(n);
  cin >> a >> b;
  vector<i64> c(n);
  vector<i64> a_max(n + 1);
  rep(i, n) a_max[i + 1] = max(a_max[i], a[i]);
  repr(i, n) c[i] = a_max[i + 1] * b[i];
  rep(i, n - 1) c[i + 1] = max(c[i + 1], c[i]);
  cout << (c) << endl;
}
