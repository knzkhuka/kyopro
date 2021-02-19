int main() {
  string s;
  cin >> s;
  int n = size(s);
  int state = -1;
  rep(i, n - 3 + 1) {
    if (s.substr(i, 3) == "ooo")
      state = 1;
    if (s.substr(i, 3) == "xxx")
      state = 2;
    dout << s.substr(i, 3) << newl;
  }
  if (state == 1)
    cout << "o" << endl;
  if (state == 2)
    cout << "x" << endl;
  if (state == -1)
    cout << "draw" << endl;
}
