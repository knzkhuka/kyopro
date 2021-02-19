int main() {
  int p, q, r;
  cin >> p >> q >> r;
  cout << min({p + q, p + r, q + r}) << endl;
}