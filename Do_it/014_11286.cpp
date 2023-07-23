#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct COMP {
    bool operator()(int x, int y) {
        if (abs(x) == abs(y)) return x > y;
        else {
            return abs(x) > abs(y);
        }
    }
};
priority_queue<int, vector<int>, COMP> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == 0) {
            if (pq.empty()) cout << 0;
            else {
                cout << pq.top();
                pq.pop();
            }
            cout << "\n";
        }
        else pq.push(tmp);
    }
}