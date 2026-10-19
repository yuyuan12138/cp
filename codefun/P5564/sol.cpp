#include <bits/stdc++.h>

constexpr int inf = 1e9;

int h, w;

char grid[102][102];
int dist1[102][102], dist2[102][102];
bool vis[102][102];

bool has_monster(int i, int j) {
	if (grid[i][j] == 'W') {
		return false;
	}
	if (grid[i][j] == 'M' || grid[i - 1][j] == 'M' || grid[i + 1][j] == 'M' || grid[i][j - 1] == 'M' || grid[i][j + 1] == 'M') {
		return true;
	}
	return false;
}
void bfs2(int x, int y) {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			dist2[i][j] = inf;
		}
	}
	dist2[x][y] = 0;
	std::queue<std::array<int, 2>> q;
	vis[x][y] = 1;
	q.push({x, y});
	while (!q.empty()) {
		std::array<int, 2> t = q.front();
		q.pop();
		int i = t[0], j = t[1];	
		if (i == 0 || i > h || j == 0 || j > w) {
			continue;
		}
		if (!vis[i - 1][j]) {
			vis[i - 1][j] = 1;
			if (grid[i - 1][j] != '#') {
				dist2[i - 1][j] = std::min(dist2[i - 1][j], dist2[i][j] + 1);
				q.push({i - 1, j});
			}
		}
		if (!vis[i + 1][j]) {
			vis[i + 1][j] = 1;
			if (grid[i + 1][j] != '#') {
				dist2[i + 1][j] = std::min(dist2[i + 1][j], dist2[i][j] + 1);
				q.push({i + 1, j});
			}
		}
		if (!vis[i][j - 1]) {
			vis[i][j - 1] = 1;
			if (grid[i][j - 1] != '#') {
				dist2[i][j - 1] = std::min(dist2[i][j - 1], dist2[i][j] + 1);
				q.push({i, j - 1});
			}
		}
		if (!vis[i][j + 1]) {
			vis[i][j + 1] = 1;
			if (grid[i][j + 1] != '#') {
				dist2[i][j + 1] = std::min(dist2[i][j + 1], dist2[i][j] + 1);
				q.push({i, j + 1});
			}
		}
	}
}

void bfs1(int x, int y) {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			dist1[i][j] = inf;
		}
	}
	dist1[x][y] = 0;
	std::queue<std::array<int, 2>> q;
	vis[x][y] = 1;
	q.push({x, y});
	while (!q.empty()) {
		std::array<int, 2> t = q.front();
		q.pop();
		int i = t[0], j = t[1];	
		if (i == 0 || i > h || j == 0 || j > w) {
			continue;
		}
		if (!vis[i - 1][j]) {
			vis[i - 1][j] = 1;
			if (!has_monster(i - 1, j) && grid[i - 1][j] != '#') {
				dist1[i - 1][j] = std::min(dist1[i - 1][j], dist1[i][j] + 1);
				if (grid[i - 1][j] != 'W')
					q.push({i - 1, j});
			}
		}
		if (!vis[i + 1][j]) {
			vis[i + 1][j] = 1;
			if (!has_monster(i + 1, j) && grid[i + 1][j] != '#') {
				dist1[i + 1][j] = std::min(dist1[i + 1][j], dist1[i][j] + 1);
				if (grid[i + 1][j] != 'W')
					q.push({i + 1, j});
			}
		}
		if (!vis[i][j - 1]) {
			vis[i][j - 1] = 1;
			if (!has_monster(i, j - 1) && grid[i][j - 1] != '#') {
				dist1[i][j - 1] = std::min(dist1[i][j - 1], dist1[i][j] + 1);
				if (grid[i][j - 1] != 'W')
					q.push({i, j - 1});
			}
		}
		if (!vis[i][j + 1]) {
			vis[i][j + 1] = 1;
			if (!has_monster(i, j + 1) && grid[i][j + 1] != '#') {
				dist1[i][j + 1] = std::min(dist1[i][j + 1], dist1[i][j] + 1);
				if (grid[i][j + 1] != 'W') 
					q.push({i, j + 1});
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		std::string t;
		std::cin >> t;
		for (int j = 1; j <= w; j++) {
			grid[i][j] = t[j - 1];
		}
	}
	std::array<int, 2> st, ed;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (grid[i][j] == 'S') {
				bfs1(i, j);
				st = {i, j};
			}
			if (grid[i][j] == 'P') {
				bfs2(i, j);
				ed = {i, j};
			}
		}
	}
	int ans = dist1[ed[0]][ed[1]];
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (grid[i][j] == 'W') {
				ans = std::min(ans, dist1[i][j] + dist2[i][j]);
			}
		}
	}
	std::cout << (ans == inf ? -1 : ans);
	
	return 0;
}
