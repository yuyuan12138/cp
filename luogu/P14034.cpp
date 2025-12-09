#include <bits/stdc++.h>

using i64 = long long;

int maximum_score(int x, int y, int z) {
    std::vector<int> a = {x, y, z};
    std::sort(a.begin(), a.end());

    return std::min((i64(x) + y + z - 1) / 2, i64(a[0]) + a[1] - 1);
}
