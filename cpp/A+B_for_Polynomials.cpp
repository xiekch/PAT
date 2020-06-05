#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

// caution: two coeff can add up to 0
int main(int argc, char const *argv[]) {
    int m, n;
    double coeff;
    int expo;
    map<int, double, greater<int>> mm;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> expo >> coeff;
        mm[expo] += coeff;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> expo >> coeff;
        mm[expo] += coeff;
    }

    // not mm.size()
    int count = 0;
    for (auto it = mm.begin(); it != mm.end(); it++) {
        if (it->second != 0)
            count++;
    }
    cout << count;
    for (auto it = mm.begin(); it != mm.end(); it++) {
        if (it->second != 0)
            printf(" %d %.1f", it->first, it->second);
    }
    cout << endl;
    return 0;
}
