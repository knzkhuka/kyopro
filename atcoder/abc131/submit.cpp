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
using pii = std::pair<int,int>;
constexpr double PI = acos(-1);

int main() {
  int n, k;
  cin >> n >> k;

  if (n == 2 and k == 0) {
    cout << 1 << newl;
    cout << "1 2" << newl;
    return 0;
  }
  int cur = (n - 2) * (n - 1) / 2;
  vector<pii> edge;
  rep(i, n - 1) edge.emplace_back(1 + i, n);
  int u = 1, v = n - 1;
  while (cur > k) {
    edge.emplace_back(u, v);
    cur--;
    v--;
    if (u == v) {
      u++;
      v = n - 1;
    }
  }
  if (cur != k) {
    cout << -1 << newl;
    return 0;
  }
  cout << size(edge) << newl;
  for (auto [u, v] : edge)
    cout << u << " " << v << newl;
}