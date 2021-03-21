int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<pii> wv(n);
  vector<int> x(m);
  cin >> wv;
  cin >> x;
  sort(begin(wv), end(wv), [](pii a, pii b) {
    return a.second == b.second ? a.first < b.first : a.second > b.second;
  });
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    multiset<int> box;
    rep(i, m) if (i < l or r < i) box.emplace(x[i]);
    int ans = 0;
    for (auto [w, v] : wv) {
      if (box.empty())
        break;
      auto itr = box.lower_bound(w);
      if (itr == end(box))
        continue;
      box.erase(itr);
      ans += v;
    }
    cout << ans << newl;
  }
}
