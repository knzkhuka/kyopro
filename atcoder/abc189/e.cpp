template <class T> struct matrix {
  int row, col;
  T add_identity, mul_identity;
  std::vector<std::vector<T>> data;
  constexpr matrix() {}
  constexpr matrix(int r, int c, T ai = 0, T mi = 1)
      : row(r), col(c), add_identity(ai), mul_identity(mi),
        data(r, std::vector<T>(c, ai)) {}
  std::vector<T> &operator[](int r) { return data[r]; }
  constexpr const inline std::vector<T> &operator[](int r) const {
    return data[r];
  }
  constexpr inline std::vector<T> &at(int r) { return data.at(r); }
  constexpr matrix identity_matrix() const {
    assert(row == col);
    matrix ide(row, col, add_identity, mul_identity);
    for (int i = 0; i < row; ++i)
      ide[i][i] = mul_identity;
    return ide;
  }
  constexpr matrix operator+(matrix const &another) {
    assert(row == another.row && col == another.col);
    matrix res(row, col, add_identity, mul_identity);
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j)
        res[i][j] = data[i][j] + another[i][j];
    return res;
  }
  constexpr matrix operator*(matrix const &another) {
    assert(col == another.row);
    matrix res(row, another.col, add_identity, mul_identity);
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < another.col; ++j)
        for (int k = 0; k < col; ++k)
          res[i][j] = res[i][j] + (data[i][k] * another[k][j]);
    return res;
  }
  constexpr bool operator==(matrix const &another) const {
    return data == another.data;
  }
  friend std::ostream &operator<<(std::ostream &os, matrix const &mat) {
    for (int i = 0; i < mat.row; ++i)
      for (int j = 0; j < mat.col; ++j)
        os << mat[i][j] << "\n "[j + 1 < mat.col];
    return os;
  }
  friend std::istream &operator>>(std::istream &is, matrix &mat) {
    for (int i = 0; i < mat.row; ++i)
      for (int j = 0; j < mat.col; ++j)
        is >> mat.data[i][j];
    return is;
  }
  constexpr matrix pow(int64_t n) {
    matrix a = *this;
    matrix res = identity_matrix();
    while (n) {
      if (n & 1)
        res = res * a;
      a = a * a;
      n >>= 1;
    }
    return res;
  }
};

int main() {
  int n;
  cin >> n;
  vector points(n, matrix<i64>(3, 1));
  for (auto &p : points) {
    cin >> p[0][0] >> p[1][0];
    p[2][0] = 1;
  }

  int m;
  cin >> m;
  vector op(m, matrix<i64>(3, 3));
  for (auto &mat : op) {
    int com;
    cin >> com;
    if (com == 1) {
      mat[0][1] = 1;
      mat[1][0] = -1;
      mat[2][2] = 1;
    }
    if (com == 2) {
      mat[0][1] = -1;
      mat[1][0] = 1;
      mat[2][2] = 1;
    }
    if (com == 3) {
      int p;
      cin >> p;
      mat[0][0] = -1;
      mat[0][2] = 2 * p;
      mat[1][1] = mat[2][2] = 1;
    }
    if (com == 4) {
      int p;
      cin >> p;
      mat[0][0] = mat[2][2] = 1;
      mat[1][1] = -1;
      mat[1][2] = 2 * p;
    }
  }

  vector acc(m + 1, matrix<i64>(3, 3));
  acc[0] = acc[0].identity_matrix();
  rep(i, m) acc[i + 1] = op[i] * acc[i];

  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    b--;
    auto res = acc[a] * points[b];
    cout << res[0][0] << " " << res[1][0] << newl;
  }
}