int main(){
  string s;
  cin>>s;
  bool ok = true;
  rep(i,s.size()-1)if(s[i]==s[i+1])ok=false;
  cout<<(ok?"Good":"Bad")<<endl;
}