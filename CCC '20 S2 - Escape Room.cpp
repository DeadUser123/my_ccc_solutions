#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& grid, int r, int c, vector<vector<pair<int, int>>> nums) {
    deque<pair<int, int>> q = {{r, c}};
    set<int> visited;
    
    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop_front();
        
        int val = (row + 1) * (col + 1);
        if (visited.count(val) != 0) { // if we've already evaluated this value, skip it
            continue;
        } else {
            visited.emplace(val);
        }
        for (size_t i = 0; i < nums[val].size(); i ++) {
            auto [a, b] = nums[val][i];
            if (a == 0 && b == 0) {
                return true;
            } else {
                q.push_back({a, b});
            }
        }
    }
    return false;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    vector<vector<pair<int, int>>> nums(1000001, vector<pair<int, int>>(0)); // array of which coordinates correspond to which values, so we don't have to search the grid every time
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            nums[grid[i][j]].push_back({i, j});
        }
    }
    if (bfs(grid, m - 1, n - 1, nums)) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}
