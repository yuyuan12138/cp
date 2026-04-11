/**
 *    author:  Yuyuan
 *    created: 2026-04-11 14:45:54
 **/
#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    const int64_t a1 = 789456, a2 = 567890, a3 = 901234;
    const int64_t b1 = 654321, b2 = 876543, b3 = 500001;
    int64_t cur1 = a1, cur2 = b1;
    int64_t cnt = 1;
    int64_t ans = 0;
    for (int i = 0; i < a3; i++)
    {
        while (cur2 <= cur1 && cnt < b3)
        {
            cnt++;
            cur2 += b2;
        }
        if (cur1 < cur2)
        {
            ans += b3 - cnt + 1;
        }
        cur1 += a2;
    }
    std::cout << ans;
    return 0;
}
