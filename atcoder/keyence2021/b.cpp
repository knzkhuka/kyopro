int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  cin >> a;
  sort(begin(a), end(a));
  multiset<int> S;
  rep(i, k) S.emplace(-1);
  for (auto ai : a) {
    auto itr = S.find(ai - 1);
    if (itr == end(S)) {
      continue;
    }
    S.erase(itr);
    S.emplace(ai);
  }
  i64 ans = 0;
  for (auto s : S)
    ans += s + 1;
  cout << (ans) << endl;
}
