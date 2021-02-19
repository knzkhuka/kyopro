#if _local
#define _GLIBCXX_DEBUG
#endif

#include<bits/stdc++.h>
using namespace std;

template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U>std::istream&operator>>(std::istream&is,std::pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}
template<class T,class U>std::ostream&operator<<(std::ostream&os,std::pair<T,U>const&p){os<<p.first<<","<<p.second;return os;}
template<class T>std::vector<T>vec(size_t a){return std::vector<T>(a);}
template<class T, class... Ts>auto vec(size_t a,Ts... ts){return std::vector<decltype(vec<T>(ts...))>(a,vec<T>(ts...));}
int64_t operator"" _i(unsigned long long x){return (int64_t)(x);}
struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
constexpr char newl='\n';
#define rep(i,n) for(int i=0;i<int(n);++i)
using i64 = int64_t;
template<int64_t MOD>
struct modint{
  int64_t val;modint():val(0){}modint(int64_t v):val(v<0?(MOD-(-v)%MOD)%MOD:v%MOD){}operator int64_t(){return val;}
  constexpr modint &operator += (modint other){this->val+=other.val;if(this->val>=MOD)this->val-=MOD;return *this;}
  constexpr modint &operator -= (modint other){this->val-=other.val;if(this->val<0)this->val+=MOD;return *this;}
  constexpr modint &operator *= (modint other){this->val*=other.val;if(this->val>=MOD)this->val%=MOD;return *this;}
  constexpr modint &operator /= (modint other){this->val*=other.inverse();if(this->val>=MOD)this->val%=MOD;return *this;}
  constexpr modint operator + (modint other)const{return modint(val)+=other;}
  constexpr modint operator - (modint other)const{return modint(val)-=other;}
  constexpr modint operator * (modint other)const{return modint(val)*=other;}
  constexpr modint operator / (modint other)const{return modint(val)/=other;}
  template<class T>constexpr modint operator + (T other)const{return modint(val)+=(modint)other;}
  template<class T>constexpr modint operator - (T other)const{return modint(val)-=(modint)other;}
  template<class T>constexpr modint operator * (T other)const{return modint(val)*=(modint)other;}
  template<class T>constexpr modint operator / (T other)const{return modint(val)/=(modint)other;}
  template<class T>constexpr modint mpow(T _n)const{int64_t n=_n;modint res(1),base(val);while(n){if(n&1)res*=base;base*=base;n>>=1;}return res;}
  template<class T,class U>constexpr static modint mpow(T t,U u){return modint(t).mpow(u);}
  constexpr modint inverse()const{return mpow(val,MOD-2);}
  friend std::ostream &operator << (std::ostream& os,modint mo){return os<<mo.val;}
  friend std::istream &operator >> (std::istream& is,modint& mo){return is>>mo.val;}
};
constexpr int64_t MOD = 1000000007;
using mint = modint<MOD>;
mint operator""_m(unsigned long long x){return (mint)x;}

int main() {
  string s;
  cin >> s;
  const int n = size(s);
  const int m = 13;
  // mod = 1000000007
  vector<i64> pow10(n);
  pow10[0] = 1;
  for (int i = 1; i < n; ++i)
    pow10[i] = pow10[i - 1] * 10 % m;
  reverse(begin(pow10), end(pow10));

  auto dp = vec<mint>(n + 1, m);
  dp[0][0] = 1;
  rep(i, n) {
    if (s[i] == '?')
      rep(j, m) rep(k, 10) {
        int jk = (j + k * pow10[i]) % m;
        dp[i + 1][jk] += dp[i][j];
      }
    else {
      int k = (s[i] - '0') * pow10[i] % m;
      rep(j, m) { dp[i + 1][(j + k) % m] += dp[i][j]; }
    }
  }
  mint ans = dp[n][5];
  cout << (ans) << endl;
}