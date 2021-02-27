int main() {
  string x;
  bigint m;
  cin >> x >> m;
  if (x.size() == 1) {
    // cout << 1 << endl;
    cout << (stoi(x) <= m) << newl;
    return 0;
  }
  auto f = [](string x, bigint n, bigint m) {
    bigint cur = 0, p = 1;
    repr(i, x.size()) {
      bigint digit = x[i] - '0';
      cur += digit * p;
      p *= n;
      if (cur > m)
        return false;
    }
    dout << n << " : " << cur << newl;
    return true;
  };
  bigint d = *max_element(begin(x), end(x)) - '0';
  bigint low = d, high = 10;
  rep(i, 70) high *= 10;
  while (high - low > 1) {
    bigint mid = (low + high) / 2;
    (f(x, mid, m) ? low : high) = mid;
  }
  cout << (low - d) << endl;
  // for(bigint i=d;i<=low;++i)f(x,i,m);
}
