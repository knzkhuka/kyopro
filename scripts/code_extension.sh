libpath="/mnt/c/Users/knzk/Documents/competitive_programming/library/"
keywords=("rep" "repr" "i64" "pii" "pll" "i128" "bigint" "inf" "INF" "newl" "pi" "eps" "vec<" "vec" "pii" "pll" "_i" "dout" "ceil" "chmax" "chmin" "divisor" "prime_factorization" "dxdy" "mpow" "minv" "1000000007" "998244353" "segtree" "union_find" "comb")
snippet=("rep.cpp" "repr.cpp" "i64.cpp" "pii.cpp" "pll.cpp" "i128.cpp" "bigint.cpp" "inf.cpp" "infl.cpp" "newl.cpp" "pi.cpp" "eps.cpp" "make_vector.cpp" "io_vector.cpp" "io_pair.cpp" "io_pair.cpp" "operator_i.cpp" "dout.cpp" "ceil.cpp" "chmax.cpp" "chmin.cpp" "divisor.cpp" "prime_factorization.cpp" "dxdy.cpp" "mpow.cpp" "minv.cpp" "modint.cpp" "modint998244353.cpp" "segment_tree.cpp" "union_find.cpp" "combination.cpp")

cat $libpath"head.cpp" > submit.cpp

for ((i=0;i<${#keywords[@]};i++)){
  #echo "${keywords[$i]} : ${snippet[$i]}"
  if grep -q ${keywords[$i]} $1;then
    cat $libpath${snippet[$i]} >> submit.cpp
  fi
}
echo "" >> submit.cpp
cat $1 >> submit.cpp