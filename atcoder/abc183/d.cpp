int main() {
  i64 n, w;
  cin >> n >> w;
  const int MAX_T = 2e5;
  vector<i64> water(MAX_T + 1);
  // water[i] := i分目に何リットル必要か
  rep(i, n) {
    int s, t, p;
    cin >> s >> t >> p;
    // for i=s to t water[i]+=p;
    water[s] += p;
    water[t] -= p;
  }
  rep(i, MAX_T) water[i + 1] += water[i];
  bool ok = true;
  for (auto wi : water)
    ok &= wi <= w;
  cout << (ok ? "Yes" : "No") << endl;
}
