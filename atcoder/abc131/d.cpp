int main() {
  int n;
  cin >> n;
  priority_queue<pll, vector<pll>, greater<>> que;
  rep(i, n) {
    i64 a, b;
    cin >> a >> b;
    que.emplace(b, a);
  }
  i64 cur = 0;
  while (!que.empty()) {
    auto [b, a] = que.top();
    que.pop();
    cur += a;
    if (cur > b) {
      cout << ("No") << endl;
      return 0;
    }
  }
  cout << ("Yes") << endl;
}