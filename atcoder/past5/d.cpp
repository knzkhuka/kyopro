int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  cin >> s;
  auto cmp = [](string const &a, string const &b) {
    int a0 = 0, b0 = 0;
    while (a0 < size(a) and a[a0] == '0')
      a0++;
    while (b0 < size(b) and b[b0] == '0')
      b0++;
    string vala = a.substr(a0);
    string valb = b.substr(b0);
    if (size(vala) != size(valb))
      return size(vala) < size(valb);
    for (int i = 0; i < size(vala); ++i) {
      if (vala[i] != valb[i])
        return vala[i] < valb[i];
    }
    return a0 > b0;
  };
  sort(begin(s), end(s), cmp);
  for (auto si : s)
    cout << si << newl;
}
