int main() {
  string s;
  cin >> s;
  int n = size(s);
  vector<int> l, r;
  rep(i, n) { (s[i] == 'R' ? r : l).emplace_back(i); }
  vector<int> ans(n);
  rep(i, n) {
    if (s[i] == 'R') {
      auto itr = lower_bound(begin(l), end(l), i);
      int j = *itr;
      int d = j - i;
      if (d & 1)
        j--;
      ans[j]++;
    }
    if (s[i] == 'L') {
      auto itr = lower_bound(begin(r), end(r), i);
      itr--;
      int j = *itr;
      int d = i - j;
      if (d & 1)
        j++;
      ans[j]++;
    }
  }
  cout << (ans) << endl;
}