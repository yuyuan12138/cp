i64 sqrt(i64 n) {
    i64 s = std::sqrt(n);
    while (s * s > n) {
        s--;
    }
    while ((s + 1) * (s + 1) <= n) {
        s++;
    }
    return s;
}
