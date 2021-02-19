int main() {
  int n;
  cin >> n;
  vector<i64> a(n);
  cin >> a;
  auto seg = make_segtree<int>(n + 1, 0, [](auto a, auto b) { return a + b; });
  i64 ans = 0;
  rep(i, n) {
    ans += seg.fold(a[i], n + 1);
    seg.set(a[i], seg[a[i]] + 1);
  }
  rep(i, n) {
    cout << ans << newl;
    ans += n - a[i] - 1;
    ans -= a[i];
  }
}