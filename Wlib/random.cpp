unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 rand_num(seed);
std::uniform_int_distribution<int> dist(0, k - 1);
int x = dist(rand_num);