#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[100001] = {0};
    int sumArr[100002] = {0};

    int n, m, i, j;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sumArr[1] = arr[0];
    for (int i = 2; i <= n; i++) {
        sumArr[i] = arr[i - 1] + sumArr[i - 1];
    }
    while (m--) {
        cin >> i >> j;
        cout << sumArr[j] - sumArr[i - 1] << "\n";
    }
    return 0;
}