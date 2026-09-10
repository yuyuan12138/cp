#include <bits/stdc++.h>

using i64 = long long;

i64 grid[11][11][11][11][11][11];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    // 6 dimisions 10 digits
    for (int i = 0; i < n; i++) {
        std::string s;
        i64 v;
        std::cin >> s >> v;
        grid[s[0] - '0' + 1][s[1] - '0' + 1][s[2] - '0' + 1][s[3] - '0' + 1]
            [s[4] - '0' + 1][s[5] - '0' + 1] += v;
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                for (int x = 1; x <= 10; x++) {
                    for (int y = 1; y <= 10; y++) {
                        for (int z = 1; z <= 10; z++) {
                            grid[i][j][k][x][y][z] +=
                                grid[i - 1][j][k][x][y][z];
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                for (int x = 1; x <= 10; x++) {
                    for (int y = 1; y <= 10; y++) {
                        for (int z = 1; z <= 10; z++) {
                            grid[i][j][k][x][y][z] +=
                                grid[i][j - 1][k][x][y][z];
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                for (int x = 1; x <= 10; x++) {
                    for (int y = 1; y <= 10; y++) {
                        for (int z = 1; z <= 10; z++) {
                            grid[i][j][k][x][y][z] +=
                                grid[i][j][k - 1][x][y][z];
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                for (int x = 1; x <= 10; x++) {
                    for (int y = 1; y <= 10; y++) {
                        for (int z = 1; z <= 10; z++) {
                            grid[i][j][k][x][y][z] +=
                                grid[i][j][k][x - 1][y][z];
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                for (int x = 1; x <= 10; x++) {
                    for (int y = 1; y <= 10; y++) {
                        for (int z = 1; z <= 10; z++) {
                            grid[i][j][k][x][y][z] +=
                                grid[i][j][k][x][y - 1][z];
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                for (int x = 1; x <= 10; x++) {
                    for (int y = 1; y <= 10; y++) {
                        for (int z = 1; z <= 10; z++) {
                            grid[i][j][k][x][y][z] +=
                                grid[i][j][k][x][y][z - 1];
                        }
                    }
                }
            }
        }
    }
    int q;
    std::cin >> q;
    while (q--) {
        std::string x, y;
        std::cin >> x >> y;
        bool ok = true;
        for (int i = 0; i < 6; i++) {
            if (x[i] > y[i]) {
                ok = false;
            }
        }

        if (!ok) {
            std::cout << 0 << '\n';
            continue;
        }

        int l[6], r[6];

        for (int i = 0; i < 6; i++) {
            // original digit d is stored at index d + 1
            // prefix before digit x[i] is therefore x[i]
            l[i] = x[i] - '0';
            r[i] = y[i] - '0' + 1;
        }

        i64 ans = 0;

        for (int mask = 0; mask < (1 << 6); mask++) {
            int a[6];
            int cnt = 0;

            for (int i = 0; i < 6; i++) {
                if (mask >> i & 1) {
                    a[i] = l[i];
                    cnt++;
                } else {
                    a[i] = r[i];
                }
            }

            i64 val = grid[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]];

            if (cnt % 2 == 0) {
                ans += val;
            } else {
                ans -= val;
            }
        }

        std::cout << ans << '\n';
    }
    return 0;
}
