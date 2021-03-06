#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
#define rep(i,n) for(int i=0;i<int(n);++i)
using i64 = int64_t;
constexpr int inf = 1<<28;
constexpr int64_t INF = 1ll<<60;
constexpr char newl = '\n';
template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}
int64_t operator"" _i(unsigned long long x) { return (int64_t)(x); }
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}


namespace ate{
  using i64 = int64_t;
  std::tuple<i64,i64,i64> ext_gcd(i64 a,i64 b){
    if(b==0){
      return {a,1,0};
    }
    auto [d,y,x] = ext_gcd(b,a%b);
    y -= a/b * x;
    return {d,x,y};
  }
  std::pair<i64,i64> crt1(i64 b1,i64 m1,i64 b2,i64 m2){
    auto [d,p,q] = ext_gcd(m1,m2);
    if((b2-b1)%d)return {0,-1};
    i64 lcm_m = m1/d*m2;
    i64 s = (b2-b1)/d;
    i64 x = b1+s*m1*p;
    return {x,lcm_m};
  }
  std::pair<i64,i64> crt(std::vector<i64> const& b,std::vector<i64> const& m){
    assert(std::size(b)==std::size(m));
    i64 r = 0, lcm_m = 1;
    for(int i=0;i<std::size(b);++i){
      auto const& b_i = b[i], m_i = m[i];
      auto [d,p,q] = ext_gcd(lcm_m,m_i);
      if((b_i-r)%d)return {-1,-1};
      i64 tmp = (b_i-r)/d*p%(m_i/d);
      r += lcm_m*tmp;
      lcm_m *= m_i/d;
    }
    r = (r%lcm_m+lcm_m)%lcm_m;
    return {r,lcm_m};
  }
}

void solve() {
  i64 x, y, p, q;
  cin >> x >> y >> p >> q;
  i64 ans = INF;
  rep(i, y) rep(j, q) {
    auto [t, lcm] = ate::crt({x+i,p+j},{(x+y)*2,p+q});
    if (lcm <= 0)
      continue;
    chmin(ans, t);
  }
  cout << (ans == INF ? "infinity" : to_string(ans)) << newl;
}
int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
