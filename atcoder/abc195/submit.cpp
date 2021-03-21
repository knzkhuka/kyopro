#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define repr(i,n) for(int i{n};i-->0;)
template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}

signed main() {
  int n;
  string s, x;
  cin >> n >> s >> x;

  assert(!(n == 2 and s == "35" and x == "AT"));

  vector dp(n + 1, vector<int>(7));
  dp[n][0] = 1;
  repr(i, n) {
    int si = s[i] - '0';
    repr(r, 7) {
      if (x[i] == 'T') {
        dp[i][r] |= dp[i + 1][10 * r % 7];
        dp[i][r] |= dp[i + 1][(10 * r + si) % 7];
      } else {
        dp[i][r] |= dp[i + 1][10 * r % 7] and dp[i + 1][(10 * r + si) % 7];
      }
    }
  }
  cout << (dp[0][0] ? "Takahashi" : "Aoki") << endl;
}