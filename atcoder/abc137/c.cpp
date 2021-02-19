int main() {
  int n;
  cin >> n;
  map<string, int> mp;
  i64 ans = 0;
  rep(i, n) {
    string s;
    cin >> s;
    sort(begin(s), end(s));
    ans += mp[s];
    mp[s]++;
  }
  cout << (ans) << endl;
}
