#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
#define rep(i,n) for(int i=0;i<int(n);++i)
using i64 = int64_t;
constexpr int64_t INF = 1ll<<60;
constexpr char newl = '\n';
template<class T>std::vector<T>vec(size_t a){return std::vector<T>(a);}
template<class T, class... Ts>auto vec(size_t a,Ts... ts){return std::vector<decltype(vec<T>(ts...))>(a,vec<T>(ts...));}
template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}
#if _local
struct debug_structure{template<class T>debug_structure&operator<<(const T&elm){std::cerr<<elm<<std::flush;return*this;}}dout;
#else
struct debug_structure{template<class T>debug_structure&operator<<(const T&elm){return*this;}}dout;
#endif
template<class T>inline bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

int main() {
  i64 n, x;
  cin >> n >> x;
  vector<i64> a(n);
  cin >> a;

  auto solve = [&](int k) {
    auto dp = vec<i64>(k + 1, k + 1);
    rep(i, k + 1) rep(j, k + 1) dp[i][j] = j == 0 ? 0 : -INF;
    rep(i, n) {
      for (int j = min(k, i + 1); j-- > 0;) {
        for (int s = 0; s < k; ++s) {
          chmax(dp[j + 1][(s + a[i]) % k], dp[j][s] + a[i]);
        }
      }
    }
    i64 sum = dp[k][x % k];
    dout << sum << " " << k << " " << (x - sum) / k << newl;
    return sum <= 0 ? INF : (x - sum) / k;
  };

  i64 ans = INF;
  for (int k = 1; k <= n; ++k)
    chmin(ans, solve(k));
  cout << (ans) << endl;
}
