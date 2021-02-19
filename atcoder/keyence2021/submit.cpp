#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
#define rep(i,n) for(int i=0;i<int(n);++i)
using i64 = int64_t;
template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  cin >> a;
  sort(begin(a), end(a));
  multiset<int> S;
  rep(i, k) S.emplace(-1);
  for (auto ai : a) {
    auto itr = S.find(ai - 1);
    if (itr == end(S))
      continue;
    S.erase(itr);
    S.emplace(ai);
  }
  i64 ans = 0;
  for (auto s : S)
    ans += s + 1;
  cout << (ans) << endl;
}
