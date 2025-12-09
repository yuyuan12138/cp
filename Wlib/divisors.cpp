void get_divisors(const int n) {
    std::vector<std::vector<int>> divs(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divs[j].push_back(i);
        }
    }
}

