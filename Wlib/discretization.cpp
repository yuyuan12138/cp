template <typename T>
void discretization(std::vector<T>& a) {
    const int n = a.size();
    std::vector<T> tmp(a);  
    std::sort(tmp.begin(), tmp.end());
    tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
    for (int i = 0; i < n; i++) {
        a[i] = std::lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
    }
}

