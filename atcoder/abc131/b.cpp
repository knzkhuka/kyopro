int main() {
  int n, l;
  cin >> n >> l;
  vector<int> apple;
  rep(i, n) apple.emplace_back(l + i);
  sort(begin(apple), end(apple),
       [](auto a, auto b) { return abs(a) < abs(b); });
  int ans = accumulate(begin(apple), end(apple), 0) - apple[0];
  cout << (ans) << endl;
}