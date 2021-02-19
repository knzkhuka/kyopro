template<class T,class U>std::istream&operator>>(std::istream&is,std::pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T,class U>std::ostream&operator<<(std::ostream&os,std::pair<T,U>const&p){os<<p.first<<" "<<p.second;return os;}
