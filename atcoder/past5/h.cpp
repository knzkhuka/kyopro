int main() {
  int h, w;
  int r, c;
  cin >> h >> w >> r >> c;
  r--, c--;
  vector<string> s(h);
  cin >> s;
  vector<vector<char>> ans(h, vector<char>(w, 'x'));
  queue<pii> que;
  constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
  constexpr int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
  constexpr char ds[] = {'<', '^', '>', 'v'};
  ans[r][c] = 'o';
  que.emplace(r, c);
  while (!que.empty()) {
    auto [y, x] = que.front();
    que.pop();
    rep(i, 4) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny == -1 || nx == -1 || ny == h || nx == w)
        continue;
      if (s[ny][nx] == '#')
        continue;
      if (ans[ny][nx] == 'o')
        continue;
      if (s[ny][nx] == '.') {
        ans[ny][nx] = 'o';
        que.emplace(ny, nx);
      } else if (s[ny][nx] == ds[i]) {
        ans[ny][nx] = 'o';
        que.emplace(ny, nx);
      }
    }
  }
  rep(i, h) rep(j, w) if (s[i][j] == '#') ans[i][j] = '#';
  for (auto ushi : ans) {
    for (auto tapu : ushi)
      cout << tapu;
    cout << newl;
  }
}
