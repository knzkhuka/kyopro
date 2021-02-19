#include <iostream>
using namespace std;
void solve() {
  using i64 = int64_t;
  constexpr char newl = '\n';
  i64 l, r;
  cin >> l >> r;
  i64 m = r - l;
  auto f = [](i64 x) { return x * (x - 1) / 2; };
  cout << (f(m)) << newl;
}
int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}