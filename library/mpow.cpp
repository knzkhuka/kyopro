int64_t mpow(int64_t n,int64_t p,const int64_t MOD){int64_t ans=1;while(p){if(p&1)ans*=n;n*=n;p>>=1;ans%=MOD;n%=MOD;}return ans;}
