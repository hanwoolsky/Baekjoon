#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> hmap;

int standard[4];
int checkNum[4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    hmap.insert({ 'A', 0 });
    hmap.insert({ 'C', 1 });
    hmap.insert({ 'G', 2 });
    hmap.insert({ 'T', 3 });

    int dlen, sublen, s, e, count, flag;
    string dna;
    cin >> dlen >> sublen >> dna;
    for (int i = 0; i < 4; i++) cin >> standard[i];
    for (int i = 0; i < sublen; i++) checkNum[hmap[dna[i]]]++;
    count = 0;

    s = 0; e = sublen - 1;
    while (e < dlen) {
        flag = 1;
        for (int i = 0; i < 4; i++) {
            if (checkNum[i] < standard[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) count++;
        checkNum[hmap[dna[s++]]]--;
        checkNum[hmap[dna[++e]]]++;
    }
    cout << count;
}