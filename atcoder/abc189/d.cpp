int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  cin >> s;
  vector<i64> dp1(n + 1), dp0(n + 1);
  dp1[0] = 1, dp0[0] = 1;
  rep(i, n) {
    if (s[i] == "OR") {
      dp1[i + 1] = 2 * dp1[i] + dp0[i];
      dp0[i + 1] = dp0[i];
    } else {
      dp1[i + 1] = dp1[i];
      dp0[i + 1] = dp1[i] + 2 * dp0[i];
    }
  }
  dout << dp1 << newl << dp0 << newl;
  cout << dp1[n] << endl;
}
