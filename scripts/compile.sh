/mnt/c/Users/knzk/Documents/competitive_programming/scripts/code_extension.sh $1
cat submit.cpp | clip.exe
echo "extensioned."
g++ -std=c++17 -O2 -o out -D_local -D_GLIBCXX_DEBUG submit.cpp