#include <iostream>
#include <vector>

using namespace std;

int main() {
    int gates;
    int planes;
    cin >> gates;
    cin >> planes;
    vector<int> airport(gates, 0);
    int result = 0;

    int plane;
    int save;
    for (int i = 0; i < planes; i ++) {
        cin >> plane;
        plane -= 1;
        while (plane >= 0 && airport[plane] > 0) {
            save = airport[plane];
            airport[plane] += 1;
            plane -= save;

            
        }
        if (plane < 0) {
            break;
        } else {
            airport[plane] += 1;
            result += 1;
        }
    }

    cout << result;
    return 0;
}
