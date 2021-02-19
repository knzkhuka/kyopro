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

int main() {
  int n;
  cin >> n;
  vector<i64> a(n);
  cin >> a;
  multiset<i64> st;
  rep(i, n) {
    auto itr = st.lower_bound(a[i]);
    if (itr != begin(st)){
      itr--;
      st.erase(itr);
    }
    st.emplace(a[i]);
  }
  cout << st.size() << endl;
}