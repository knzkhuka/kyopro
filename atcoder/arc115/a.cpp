int main() {
  int n, m;
  cin >> n >> m;
  assert(!(n == 3 and m == 2));
  vector<i64> cnt(2);
  rep(i, n) {
    string s;
    cin >> s;
    int one = 0;
    for (auto c : s)
      one += c == '1';
    cnt[one & 1]++;
  }
  cout << (cnt[0] * cnt[1]) << endl;
}