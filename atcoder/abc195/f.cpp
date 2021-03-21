i64 solve(i64, i64);
int main() {
  
}
i64 solve(i64 a, i64 b) {
  assert(a <= b);
  i64 n = b - a + 1;
  i64 ans = 0;
  rep(bit, 1 << n) {
    vector<i64> S;
    rep(i, n) if ((bit >> i) & 1) S.emplace_back(a + i);
    int m = size(S);
    bool setwise_coprime = true;
    rep(i, m) rep(j, m) if (i != j) setwise_coprime &= gcd(S[i], S[j]) == 1;
    ans += setwise_coprime;
  }
  return ans;
}