int main() {
  int n, m;
  cin >> n >> m;
  vector<int> abc(m);
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--, c--;
    abc[i] |= 1 << a;
    abc[i] |= 1 << b;
    abc[i] |= 1 << c;
  }
  auto popc = [](auto a) { return __builtin_popcount(a); };
  int ans = 0;
  rep(b, 1 << n) {
    bool invalid = false;
    rep(i, m) invalid |= (b & abc[i]) == abc[i];
    if (invalid)
      continue;
    int tmp = 0;
    rep(i, m) if (popc(b & abc[i]) == 2) tmp |= abc[i] - (b & abc[i]);

    chmax(ans, popc(tmp));
  }
  cout << (ans) << endl;
}
