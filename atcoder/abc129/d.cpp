int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  cin >> s;
  union_find<int> row(h * w), col(h * w);
  auto encode = [&](int i, int j) { return w * i + j; };
  rep(i, h) rep(j, w - 1) {
    if (s[i][j] == '.' and s[i][j + 1] == '.')
      row.unite(encode(i, j), encode(i, j + 1));
  }
  rep(j, w) rep(i, h - 1) {
    if (s[i][j] == '.' and s[i + 1][j] == '.')
      col.unite(encode(i, j), encode(i + 1, j));
  }
  int ans = 0;
  rep(i, h) rep(j, w) {
    int rsz = row.size(encode(i, j));
    int csz = col.size(encode(i, j));
    chmax(ans, rsz + csz - 1);
  }
  cout << (ans) << endl;
}