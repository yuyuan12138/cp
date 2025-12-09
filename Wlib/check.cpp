// 随机数生成器
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 rand_num(seed);

// 生成随机整数 [min_val, max_val]
int random_int(int min_val, int max_val) {
    return std::uniform_int_distribution<int>(min_val, max_val)(rand_num);
}

// 生成随机数组
std::vector<int> generate_array(int n, int min_val, int max_val) {
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = random_int(min_val, max_val);
    }
    return arr;
}
