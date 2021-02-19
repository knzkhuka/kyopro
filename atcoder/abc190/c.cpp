int main() {
  int n, m;
  cin >> n >> m;
  vector<pii> ab(m);
  cin >> ab;
  int k;
  cin >> k;
  auto cd = vec<int>(k, 2);
  cin >> cd;
  int ans = 0;
  rep(bit, 1 << k) {
    vector<int> ball(n + 1);
    rep(i, k) { ball[cd[i][(bit >> i) & 1]]++; }
    int tmp = 0;
    for (auto [a, b] : ab) {
      if (ball[a] and ball[b])
        tmp++;
    }
    chmax(ans, tmp);
  }
  cout << (ans) << endl;
}
