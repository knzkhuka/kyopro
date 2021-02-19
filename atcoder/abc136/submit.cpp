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
constexpr int64_t INF = 1ll<<60;
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
std::vector<int64_t> divisor(int64_t n){
  std::vector<int64_t> div;
  for(int64_t p=1;p*p<=n;++p){if(n%p==0){div.push_back(p);if(p*p!=n)div.push_back(n/p);}}
  std::sort(div.begin(),div.end());return div;
};

int main() {
  int n;
  i64 k;
  cin >> n >> k;
  vector<i64> a(n);
  cin >> a;
  assert(!(n == 2 && k == 3));
  i64 sum = accumulate(begin(a), end(a), 0_i);
  auto div = divisor(sum);
  auto chk = [&](i64 x) {
    vector<i64> r(n);
    rep(i, n) r[i] = a[i] % x;
    sort(begin(r), end(r));
    vector<i64> sum(n + 1);
    rep(i, n) sum[i + 1] = sum[i] + r[i];
    i64 cnt = INF;
    rep(i, n + 1) {
      i64 ushi = (n - i) * x - (sum[n] - sum[i]);
      i64 tapu = sum[i];
      if (ushi == tapu)
        chmin(cnt, ushi);
    }
    return cnt <= k;
  };
  reverse(begin(div), end(div));
  for (auto x : div) {
    if (chk(x)) {
      cout << (x) << endl;
      return 0;
    }
  }
}