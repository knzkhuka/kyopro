int main() {
  int h, w;
  cin >> h >> w;
  int n = h + w;
  vector<vector<char>> s(5 * n, vector<char>(5 * n, 'o'));
  vector<vector<char>> t(h, vector<char>(w));
  rep(i, h) rep(j, w) { cin >> s[2 * n + i][2 * n + j]; }
  cin >> t;
  auto rot90 = [](auto const &t) {
    int h = size(t);
    int w = size(t[0]);
    vector<vector<char>> nt(w, vector<char>(h));
    rep(i, w) rep(j, h) nt[i][j] = t[h - 1 - j][i];
    return nt;
  };
  auto rot180 = [](auto const &t) {
    int h = size(t);
    int w = size(t[0]);
    vector<vector<char>> nt(h, vector<char>(w));
    rep(i, h) rep(j, w) nt[i][j] = t[h - 1 - i][j];
    return nt;
  };
  auto eq = [&h, &w](auto &s, auto &t, int ti, int tj) {
    int n = h + w;
    int th = size(t);
    int tw = size(t[0]);
    rep(i, th) rep(j, tw) {
      if (s[i + ti][j + tj] == '#' and t[i][j] == '#')
        return false;
      if (t[i][j] == '#') {
        if (!(2 * n <= (ti + i) and (ti + i) < 2 * n + h))
          return false;
        if (!(2 * n <= (tj + j) and (tj + j) < 2 * n + w))
          return false;
      }
    }
    return true;
  };

  int loop = 20;
  while (loop--) {
    for (int ti = 0; ti <= 3 * n; ++ti) {
      for (int tj = 0; tj <= 3 * n; ++tj) {
        if (eq(s, t, ti, tj)) {
          for (auto x : t) {
            for (auto y : x)
              dout << y;
            dout << newl;
          }
          cout << "Yes" << endl;
          return 0;
        }
      }
    }

    t = rot90(t);
  }
  cout << "No" << endl;
}
