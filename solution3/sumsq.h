template<typename T>
struct sumsquare {
    T operator()(const T& s, const T& a) { return s + a * a; };
};
