#include <iostream>
#include <algorithm>
using namespace std;

int arr[15001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, s, e, count;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    s = count = 0; e = n - 1;
    while (s < e) {
        if (arr[s] + arr[e] == m) {
            count++;
            s++; e--;
        }
        else if (arr[s] + arr[e] < m) s++;
        else e--;
    }
    cout << count;
}