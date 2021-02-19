int main() {
  int n;
  string s, t;
  cin >> n >> s;
  vector<bool> alp(26);
  repr(i, n) {
    if (alp[s[i] - 'a'])
      continue;
    alp[s[i] - 'a'] = true;
    t += s[i];
  }
  reverse(begin(t), end(t));
  cout << (t) << endl;
}
