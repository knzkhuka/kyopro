int main() {
  string s;
  i64 x;
  cin >> s >> x;
  int n = size(s);

  vector<i64> mozicnt(n + 1, INF);
  mozicnt[0] = 0;
  rep(i, n) {
    if (isalpha(s[i]))
      mozicnt[i + 1] = mozicnt[i] + 1;
    else
      mozicnt[i + 1] = mozicnt[i] * (s[i] - '0' + 1);
    if (mozicnt[i + 1] > x)
      break;
  }
  dout << mozicnt << newl;

  while (x) {
    auto itr = lower_bound(begin(mozicnt), end(mozicnt), x);
    if (*itr == x) {
      int i = itr - begin(mozicnt) - 1;
      while (!isalpha(s[i]))
        i--;
      cout << s[i] << endl;
      return 0;
    } else {
      --itr;
      dout << x << "," << *itr << newl;
      if(x%*itr==0){
        int i = itr - begin(mozicnt) - 1;
        while (!isalpha(s[i]))
          i--;
        cout << s[i] << endl;
        return 0;
      }
      x %= *itr;
    }
  }
}
