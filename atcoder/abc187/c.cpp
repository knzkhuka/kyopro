int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  cin >> s;
  map<string, int> mp,mp2;
  rep(i, n) {
    if (s[i][0] == '!')
      mp2[s[i].substr(1)]++;
    else
      mp[s[i]]++;
  }
  string ans = "satisfiable";
  for (auto &[k, v] : mp)
    if (mp2[k]>=1)
      ans = k;
  cout << (ans) << endl;
}
