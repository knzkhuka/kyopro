using i128=__int128_t;
std::istream&operator>>(std::istream&is,__int128_t&val){std::string s;is>>s;val=0;bool neg=s[0]=='-';for(int i=neg;i<s.size();++i)(val*=10)+=s[i]-'0';if(neg)val=-val;return is;}
std::ostream&operator<<(std::ostream&os,__int128_t val){std::ostream::sentry s(os);if(s){__uint128_t tmp=val<0?-val:val;char buf[128];char*d=std::end(buf);do{--d;*d="0123456789"[tmp%10];tmp/=10;}while(tmp!=0);if(val<0){--d;*d='-';}int len=std::end(buf)-d;if(os.rdbuf()->sputn(d, len)!=len)os.setstate(std::ios_base::badbit);}return os;}
constexpr i128 sqrt(i128 c){i128 x=1;while(!(x*x<=c&&c<=(x+1)*(x+1)))x=(c/x+x)/2;return x;}
