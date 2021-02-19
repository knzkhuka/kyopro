int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  cin >> s;
  int k = 0;
  rep(i, h) rep(j, w) if (s[i][j] == '#') k++;
  auto encode = [&](int i, int j) { return w * i + j; };
  auto decode = [&](int x) { return pii(x / w + 1, x % w + 1); };
  constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
  constexpr int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
  vector<vector<int>> adj(h * w);
  rep(y, h) rep(x, w) if (s[y][x] == '#') rep(i, 4) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny == -1 || nx == -1 || ny == h || nx == w)
      continue;
    if (s[ny][nx] == '.')
      continue;
    int u = encode(y, x);
    int v = encode(ny, nx);
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  auto solve = [&](int v) {
    using data_t = tuple<int, int, vector<int>>;
    queue<data_t> que;
    vector<int> miti;
    int S = 1 << v;
    que.emplace(v, S, miti);
    while (!que.empty()) {
      auto [v, S, miti] = que.front();
      que.pop();
      miti.emplace_back(v);
      if (miti.size() == k) {
        cout << k << newl;
        for (auto x : miti)
          cout << decode(x) << newl;
        exit(0);
      }
      for (auto nv : adj[v]) {
        if ((1 << nv) & S)
          continue;
        que.emplace(nv, S | 1 << nv, miti);
      }
    }
  };
  rep(i, h) rep(j, w) if (s[i][j] == '#') solve(encode(i, j));
}
