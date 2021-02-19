int main() {
  int n;
  cin >> n;
  vector<pll> a(n);
  cin >> a;
  i64 bsum = 0;
  for (auto [b, _] : a)
    bsum += b;
  auto cmp = [](pll a, pll b) {
    return a.first * 2 + a.second > b.first * 2 + b.second;
  };
  sort(begin(a), end(a), cmp);
  i64 asum = 0;
  int ans = 0;
  rep(i, n) {
    asum += a[i].first + a[i].second;
    bsum -= a[i].first;
    ans = i + 1;
    if (asum > bsum)
      break;
  }
  dout << asum << " " << bsum << newl;
  cout << (ans) << endl;
}
