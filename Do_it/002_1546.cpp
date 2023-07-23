#include <iostream>
using namespace std;

int main() {
    int n, score, max;
    cin >> n;

    double sum = 0;
    max = 0;
    for (int i = 0; i < n; i++) {
        cin >> score;
        sum += score;
        if (max < score) max = score;
    }
    cout << double(sum * 100 / max / n);
}