// https://mojacoder.app/users/Tonegawac/problems/data-structure2

signed main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  cin >> a;
  vector<pii> queries(q);
  cin >> queries;

  vector<int> number_set = a;
  for (auto &[com, xi] : queries)
    if (com != 2)
      number_set.emplace_back(xi);
  sort(begin(number_set), end(number_set));
  number_set.erase(unique(begin(number_set), end(number_set)), end(number_set));

  for (auto &ai : a) {
    auto itr = lower_bound(begin(number_set), end(number_set), ai);
    ai = itr - begin(number_set);
  }

  for (auto &[com, xi] : queries)
    if (com != 2) {
      auto itr = lower_bound(begin(number_set), end(number_set), xi);
      xi = itr - begin(number_set);
    }
  vector<int> v(number_set.size() + 1);
  for (auto ai : a)
    v[ai]++;
  auto seg = make_segtree(v, 0, [](int a, int b) { return a + b; });

  for (auto &[com, val] : queries) {
    if (com == 0) {
      seg.set(val, seg[val] + 1);
    } else if (com == 1) {
      seg.set(val, seg[val] - 1);
    } else if (com == 2) {
      auto cmp = [&val](int sum) { return val < sum; };
      int res = seg.bsearch(0, cmp);
      cout << number_set[res] << newl;
    } else if (com == 3) {
      int res = seg.fold(0, val);
      cout << res << newl;
    }
  }
}