#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
template<class T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){for(auto const& vi:v)os<<vi<<" ";return os;}

int main() {
  int n;
  cin >> n;
  vector<double> dp(n + 1);
  for (int i = n; i > 0; i--) {
    dp[i - 1] = dp[i] + (double)n / (double)(i-1);
  }
  cout << (dp[1]) << endl;
}
