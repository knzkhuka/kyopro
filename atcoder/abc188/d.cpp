int main() {
  int n;
  i64 c;
  cin >> n >> c;
  vector<pll> data;
  rep(i, n) {
    i64 a, b, c;
    cin >> a >> b >> c;
    data.emplace_back(a, c);
    data.emplace_back(b + 1, -c);
  }
  sort(begin(data), end(data));
  i64 ans = 0, acml_sum = 0, prv = 0;
  for (auto const &[day, weight] : data) {
    i64 len = day - prv;
    i64 cost = min(c, acml_sum);
    prv = day;
    ans += len * cost;
    acml_sum += weight;
  }
  cout << (ans) << endl;
}
