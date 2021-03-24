int main() {
  int n;
  cin >> n;
  auto c = vec<i64>(n, n);
  cin >> c;
  vector<i64> a(n), b(n);
  rep(i, n) {
    a[i] = *min_element(begin(c[i]), end(c[i]));
    for (auto &cij : c[i])
      cij -= a[i];
  }
  rep(i, n) b[i] = c[i][i];
  bool valid = all_of(begin(c), end(c), [&c](auto &a) { return a == c[0]; });
  if (valid) {
    cout << "Yes" << newl;
    cout << a << newl;
    cout << b << newl;
  } else {
    cout << "No" << newl;
  }
}
