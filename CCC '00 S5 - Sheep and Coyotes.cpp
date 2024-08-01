#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

string format_decimal(double num) {
    stringstream stream;
    stream << fixed << setprecision(2) << num;
    string formatted = stream.str();
    if (formatted[formatted.size() - 2] == '.') {
        formatted += "0";
    }
    return formatted;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> sheeps(n);

    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        sheeps[i] = make_pair(static_cast<int>(x * 1000), static_cast<int>(y * 1000));
    }

    set<string> eat;
    int x = 0;
    while (x <= 1000000) {
        double min_distance = numeric_limits<double>::infinity();
        vector<pair<int, int>> min_sheeps;

        for (const auto& sheep : sheeps) {
            double distance = sqrt(pow(sheep.first - x, 2) + pow(sheep.second, 2));
            if (min_distance > distance) { // if one is closer
                min_distance = distance;
                min_sheeps.clear();
                min_sheeps.emplace_back(sheep);
            } else if (min_distance == distance) { // if equally close, add both
                min_sheeps.emplace_back(sheep);
            }
        }

        for (const auto& min_sheep : min_sheeps){
            eat.insert("(" + format_decimal(min_sheep.first / 1000.0) + ", " + format_decimal(min_sheep.second / 1000.0) + ")");
        }
        x += 10;
    }

    for (const auto& s : eat) {
        cout << "The sheep at " << s << " might be eaten." << endl;
    }

    return 0;
}
