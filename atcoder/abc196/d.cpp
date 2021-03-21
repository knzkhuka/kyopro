int main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  int n = h * w;
  int ans = 0;
  auto s = vec<char>(h, w);
  rep(i, h) rep(j, w) s[i][j] = 'B';
  set<vector<vector<char>>> st;
  auto dfs = [&](auto &&dfs, int i, int j, auto &s, int aa, int bb) -> void {
    if (i + 1 == h and j + 1 == w) {
      if (aa == a and bb == b) {
        for (auto si : s)
          dout << si << newl;
        dout << newl;
        ans++;
        st.emplace(s);
      }
      return;
    }
    if (i + 1 < h) {
      dfs(dfs, i + 1, j, s, aa, bb);
      if (s[i][j] != 'A') {
        s[i][j] = 'A';
        if (s[i + 1][j] != 'A') {
          s[i + 1][j] = 'A';
          dfs(dfs, i + 1, j, s, aa + 1, bb - 2);
          s[i + 1][j] = 'B';
        }
        if (j + 1 < w) {
          s[i][j + 1] = 'A';
          dfs(dfs, i + 1, j, s, aa + 1, bb - 2);
          s[i][j + 1] = 'B';
        }
        s[i][j] = 'B';
      }
    } else if (j + 1 < w) {
      dfs(dfs, 0, j + 1, s, aa, bb);
      if (s[i][j] != 'A') {
        if (j + 1 < w) {
          s[i][j] = 'A';
          s[i][j + 1] = 'A';
          dfs(dfs, 0, j + 1, s, aa + 1, bb - 2);
          s[i][j + 1] = 'B';
          s[i][j] = 'B';
        }
      }
    }
  };
  dfs(dfs, 0, 0, s, 0, n);
  cout << (ans) << endl;
}
