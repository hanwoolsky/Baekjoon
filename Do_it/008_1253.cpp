#include <iostream>
#include <algorithm>
using namespace std;

int arr[2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, e, count;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    count = 0;
    if (n > 2) {
        for (int i = 2; i < n; i++) {
            s = 0; e = i - 1;
            while (s < e) {
                if (long(arr[s] + arr[e]) == arr[i]) {
                    count++;
                    break;
                }
                else if (long(arr[s] + arr[e]) < arr[i]) s++;
                else e--;
            }
        }

    }
    cout << count;
}
// 배열이 모두 양수라면 정답이겠지만, |A| < 1,000,000,000이므로 -3 -2 -1 1 2 인데 -1에서 -3, -2만 살피므로 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, e, count;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    count = 0;
    for (int i = 0; i < n; i++) {
        s = 0; e = n - 1;
        while (s < e) {
            if (long(arr[s] + arr[e]) == arr[i]) {
                if (s != i && e != i) {
                    count++;
                    break;
                }
                else if (s == i) s++;
                else e--;
            }
            else if (long(arr[s] + arr[e]) < arr[i]) s++;
            else e--;
        }
    }
    cout << count;
}