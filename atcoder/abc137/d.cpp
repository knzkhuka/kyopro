int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> ushi(2e5);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    ushi[a].emplace_back(b);
  }
  priority_queue<i64> que;
  i64 ans = 0;
  for (int i = 1; i <= m; ++i) {
    for (auto b : ushi[i])
      que.emplace(b);
    if (que.empty())
      continue;
    ans += que.top();
    que.pop();
  }
  cout << (ans) << endl;
}
