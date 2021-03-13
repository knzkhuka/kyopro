int main() {
  int n;
  cin >> n;
  vector<double> dp(n + 1);
  for (int i = n; i > 0; i--) {
    dp[i - 1] = dp[i] + (double)n / (double)(i-1);
  }
  cout << (dp[1]) << endl;
}
