#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string a, b;
    std::cin >> a >> b;
    if (a.size() > b.size()) {
        std::swap(a, b);
    }
    std::string ans(b.size(), '0');
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        int x = a[i] - '0', y = b[i] - '0';
        if (x + y + carry >= 10) {
            ans[i] = x + y + carry - 10 + '0';
            carry = 1;
        } else {
            ans[i] = x + y + carry + '0';
            carry = 0;
        }
    
    }
    for (int i = a.size(); i < b.size(); i++) {
        int x = b[i] - '0';
        if (x + carry >= 10) {
            carry = 1;
            ans[i] = '0';
        } else {
            carry = 0;
            ans[i] = b[i];
        }
    }
    if (carry == 1) {
        std::cout << '1';
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << ans;
    return 0;
}
