#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, e, count, sum;
    cin >> n;

    s = e = count = sum = 1;
    while (s != n / 2 + 1) { // e != n도 가능하지만 s != n / 2 + 1로 하면 반까지만 세도 된다. 20ms -> 12ms
        if (sum == n) {
            count++;
            sum += ++e;
        }
        else if (sum > n) {
            sum -= s;
            s++;
        }
        else sum += ++e;
    }
    cout << count;
}