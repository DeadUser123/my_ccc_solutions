#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c, m;
    cin >> r >> c;
    vector<vector<bool>> grid(r, vector<bool>(c, false));
    vector<vector<bool>> ans(grid);
    char a;
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j ++) {
            cin >> a;
            if (a == 'X') {
                grid[i][j] = true; // obstacles marked as true
            }
        }
    }
    cin >> m;
    vector<char> moves(m, '_');
    for (int i = 0; i < m; i ++) {
        cin >> moves[i];
    }
    int x, y, dx, dy, ndx, ndy;
    bool valid;
    vector<pair<int, int>> directions = {make_pair(0, -1), make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0)};
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j ++) {
            if (grid[i][j])
                continue;
            for (int k = 0; k < 4; k ++) { // try all directions
                dx = directions[k].first;
                dy = directions[k].second;
                x = j;
                y = i;
                valid = true;
                for (int l = 0; l < m; l ++) {
                    if (moves[l] == 'F') { // go forward
                        x += dx;
                        y += dy;
                        if (x >= c || y >= r || x < 0 || y < 0 || grid[y][x]) {
                            valid = false; // if we've gone out of bounds or hit an obstacle
                            break;
                        }
                    } else if (moves[l] == 'L') { // turn left
                        ndx = dy;
                        ndy = -dx;
                        dx = ndx;
                        dy = ndy;
                    } else if (moves[l] == 'R') { // turn right
                        ndx = -dy;
                        ndy = dx;
                        dx = ndx;
                        dy = ndy;
                    }
                }
                if (valid) {
                    ans[y][x] = true; // final position can be reached
                    break;
                }
            }
        }
    }

    for (int i = 0; i < r; i ++) { // output
        for (int j = 0; j < c; j ++) {
            if (ans[i][j]) {
                cout << '*';
            } else if (grid[i][j]) {
                cout << 'X';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
    
    return 0;
}
