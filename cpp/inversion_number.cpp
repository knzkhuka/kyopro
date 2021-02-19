#include <algorithm>
#include <vector>
#include <iostream>

template<class T>
int64_t inversion_number(std::vector<T> const& a){
  const int n=a.size();
  std::vector<T> BIT(n+1);
  int64_t inversion=0;
  for(int i=0;i<n;++i){
    T ai=a[i]+1;
    for(int j=ai;j>0;j-=j&-j)inversion-=BIT[j];
    inversion+=i;
    for(int j=ai;j<=n;j+=j&-j)BIT[j]++;
  }
  return inversion;
}

int main(){
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  constexpr char newl = '\n';
  using namespace std;
  int n;
  cin>>n;
  vector<int> a(n);
  for(auto&ai:a)cin>>ai;
  int64_t ans = inversion_number(a);
  for(int i=0;i<n;++i){
    cout<<ans<<newl;
    ans += n-a[i]-1;
    ans -= a[i];
  }
}