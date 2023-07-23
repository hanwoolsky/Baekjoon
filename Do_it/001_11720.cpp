#include <iostream>
using namespace std;

int main(){
    int n, sum;
    string num;
    cin >> n >> num;

    sum = 0;
    for(int i : num){
        sum += i - '0';
    }
    cout << sum;
}