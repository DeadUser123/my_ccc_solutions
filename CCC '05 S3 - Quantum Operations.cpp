#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

vector<vector<int>> tensor(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    int a_rows = a.size();
    int a_cols = a[0].size();
    int b_rows = b.size();
    int b_cols = b[0].size();
    vector<vector<int>> result(a_rows * b_rows, vector<int>(a_cols * b_cols));

    for (int i = 0; i < a_rows; i++) {
        for (int j = 0; j < a_cols; j++) {
            for (int k = 0; k < b_rows; k++) {
                for (int l = 0; l < b_cols; l++) {
                    result[i * b_rows + k][j * b_cols + l] = a[i][j] * b[k][l];
                }
            }
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> result;
    
    for (int i = 0; i < n; i++) {
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<int>> matrix(rows, vector<int>(cols));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                cin >> matrix[row][col];
            }
        }
        if (i == 0) {
            result = matrix;
        } else {
            result = tensor(result, matrix);
        }
    }

    int r = result.size();
    int c = result[0].size();

    vector<int> rows(r, 0);
    vector<int> cols(c, 0);

    int min_value = numeric_limits<int>::max();
    int max_value = numeric_limits<int>::min();

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int cell = result[i][j];
            min_value = min(min_value, cell);
            max_value = max(max_value, cell);
            rows[i] += cell;
            cols[j] += cell;
        }
    }

    cout << max_value << "\n";
    cout << min_value << "\n";
    cout << *max_element(rows.begin(), rows.end()) << "\n";
    cout << *min_element(rows.begin(), rows.end()) << "\n";
    cout << *max_element(cols.begin(), cols.end()) << "\n";
    cout << *min_element(cols.begin(), cols.end()) << "\n";

    return 0;
}
