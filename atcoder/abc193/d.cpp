int main() {
  i64 k;
  cin >> k;
  string s, t;
  cin >> s >> t;
  s.pop_back(), t.pop_back();
  map<int, int> mps, mpt, card;
  for (int i = 1; i < 10; ++i)
    card[i] = k;
  for (auto si : s) {
    mps[si - '0']++;
    card[si - '0']--;
  }
  for (auto ti : t) {
    mpt[ti - '0']++;
    card[ti - '0']--;
  }

  auto win = [](auto a, auto b) -> bool {
    auto calc = [](auto mp) -> int {
      int ans = 0;
      for (int i = 1; i < 10; ++i)
        ans += i * pow(10, mp[i]);
      return ans;
    };
    int aa = calc(a);
    int bb = calc(b);
    return aa > bb;
  };
  vector<double> sum(12);
  rep(i, 11) sum[i + 1] = sum[i] + card[i];

  double ans = 0.0;
  for (int i = 1; i < 10; ++i)
    for (int j = 1; j < 10; ++j) {
      if (!(card[i] > 0 and card[j] > 0))
        continue;
      if (i == j and !(card[i] >= 2))
        continue;
      dout << i << "," << j << newl;
      mps[i]++, mpt[j]++;
      if (win(mps, mpt)) {
        double ci = card[i];
        double cj = (i == j ? card[j] - 1 : card[j]);
        ans += ci * cj;
      }
      mps[i]--, mpt[j]--;
    }
  double base = 9.0 * (double)k - 8.0;
  ans /= base * (base - 1.0);
  cout << (ans) << endl;
}
