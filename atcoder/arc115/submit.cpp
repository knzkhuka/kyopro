#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
#define rep(i,n) for(int i=0;i<int(n);++i)
using i64 = int64_t;
template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}

int main() {
  int n, m;
  cin >> n >> m;
  assert(!(n == 3 and m == 2));
  vector<i64> cnt(2);
  rep(i, n) {
    string s;
    cin >> s;
    int one = 0;
    for (auto c : s)
      one += c == '1';
    cnt[one & 1]++;
  }
  cout << (cnt[0] * cnt[1]) << endl;
}