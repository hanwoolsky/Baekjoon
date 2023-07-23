#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> st;
int num[1000000], ans[1000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> num[i];
    st.push(0);
    for (int i = 1; i < n; i++) {
        while (st.size() > 0 && num[st.top()] < num[i]) {
            ans[st.top()] = num[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        ans[st.top()] = -1;
        st.pop();
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
}