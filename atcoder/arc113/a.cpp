template <uint32_t N = 10'000'000> struct Sieve_of_Eratosthenes {
  using u32 = uint32_t;
  std::vector<u32> factor;
  Sieve_of_Eratosthenes() {
    factor.resize(N + 1);
    for (u32 p = 2; p <= N; ++p) {
      if (factor[p])
        continue;
      factor[p] = p;
      for (u32 x = p + p; x <= N; x += p) {
        if (factor[x])
          continue;
        factor[x] = p;
      }
    }
  }
  std::vector<u32> prime_factor(u32 x) {
    std::vector<u32> pf;
    while (factor[x]) {
      pf.push_back(factor[x]);
      while (factor[x] == pf.back())
        x /= factor[x];
    }
    return pf;
  }
  bool isprime(u32 x) { return factor[x] == x; }
};

int main() {
  i64 k;
  cin >> k;
  auto div = divisor(k);
  vector<vector<i64>> divdiv(size(div));
  rep(i, size(div)) divdiv[i] = divisor(k/div[i]);
  i64 ans = 0;
  rep(i, size(div)) ans += size(divdiv[i]);
  cout << (ans) << endl;
}
