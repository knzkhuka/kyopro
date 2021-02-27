#include<bits/stdc++.h>
using namespace std;

struct fastio{fastio(){cin.tie(nullptr);ios_base::sync_with_stdio(false);std::cout<<std::fixed<<setprecision(10);}}oitsaf;
using i64 = int64_t;
int64_t mpow(int64_t n,int64_t p,const int64_t MOD){int64_t ans=1;while(p){if(p&1)ans*=n;n*=n;p>>=1;ans%=MOD;n%=MOD;}return ans;}

int main() {
  i64 a, b, c;
  cin >> a >> b >> c;
  i64 ans = mpow(mpow(a, b, 10), c, 10);
  cout << (ans) << endl;
}
