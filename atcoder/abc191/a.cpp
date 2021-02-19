int main() {
  int v, t, s, d;
  cin >> v >> t >> s >> d;
  t *= v;
  s *= v;
  cout<<(t<=d and d<=s?"No":"Yes")<<endl;
}
