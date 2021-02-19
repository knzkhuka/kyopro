int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  cin >> s;
  int ans = 0;
  bool prv = false;
  rep(i, h - 1) rep(j, w) {
    if (s[i][j] != s[i + 1][j]) {
      dout << "{" << i << "," << j << "} : " << (s[i][j] != s[i + 1][j]) << " "
           << prv << " " << ans << newl;
      ;
      if (!prv) {
        prv = true;
        ans++;
      }
    } else {
      prv = false;
    }
  }
  prv = false;
  rep(j, w - 1) rep(i, h) {
    if (s[i][j] != s[i][j + 1] ) {
      dout << "{" << i << "," << j << "} : " << (s[i][j] != s[i + 1][j]) << " "
           << prv << " " << ans << newl;
      if (!prv) {
        prv = true;
        ans++;
      }
    } else {
      prv = false;
    }
  }
  cout << (ans) << endl;
}
