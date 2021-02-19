
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  i64 ans = 0;
  vector<pii> b(n);
  rep(i, n) b[i] = {a[i], i};
  auto seg = make_segtree<pii>(b, pii{inf, inf},
                               [](auto a, auto b) { return min(a, b); });
  auto solve = [&](auto &&solve, int l, int r) -> void {
    if (r - l < 1)
      return;
    auto [v, i] = seg.fold(l, r);
    chmax<i64>(ans, v * (i64)(r - l));
    solve(solve, l, i);
    solve(solve, i + 1, r);
  };
  solve(solve, 0, n);
  cout << (ans) << endl;
}
