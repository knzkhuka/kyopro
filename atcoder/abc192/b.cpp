int main() {
  string s;
  cin >> s;
  int n = size(s);
  bool odd = true, eve = true;
  auto isupper = [](char c) -> bool { return 'A' <= c and c <= 'Z'; };
  auto islower = [](char c) -> bool { return 'a' <= c and c <= 'z'; };
  rep(i, n) {
    if (i & 1)
      eve &= isupper(s[i]);
    else
      odd &= islower(s[i]);
  }
  cout << (odd & eve ? "Yes" : "No") << endl;
}
