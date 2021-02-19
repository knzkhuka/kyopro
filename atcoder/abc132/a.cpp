int main() {
  string s;
  cin >> s;
  map<char, int> mp;
  for (auto c : s)
    mp[c]++;
  bool ans = mp.size() == 2;
  for (auto [k, v] : mp)
    ans &= v == 2;
  cout << (ans ? "Yes" : "No") << endl;
  
}
