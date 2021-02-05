#include <iostream>
#include <stack>
#include <array>
#include <vector>
#include <stdlib.h>

using namespace std;

int main() {
  vector <string> sv;
  stack<int> s;
  array<int, 1000> numarr;

  string command = "Hello";
  while(command != "QUIT"){
    sv.clear();
    do{
      getline(cin, command);
      sv.push_back(command);
    }
    while (command != "END" && command != "QUIT");

    int strsize = sv.size();
    if (command != "QUIT"){
      int all;
      int list;
      cin >> all;
      for(int i = 0; i < all; i++){
        cin >> list;
        numarr[i] = list;
      }

      for(int j = 0; j < all; j++){
        s.push(numarr[j]);
        int num;
        int first;
        int size;
        int count = 1;

        for(int k = 0; k < strsize; k++){    
          if(sv[k].substr(0, 3) == "NUM"){
            num = atoi(sv[k].substr(4).c_str());
            s.push(num);
          }
          else if (sv[k] == "POP"){
            s.pop();
          }
          else if (sv[k] == "INV"){
            first = s.top();
            s.pop();
            s.push(-first);
          }
          else if (sv[k] == "DUP"){
            s.push(s.top());
          }
          else if (sv[k] == "SWP"){
            first = s.top();
            s.pop();
            int sec = s.top();
            s.pop();
            s.push(first);
            s.push(sec);
          }
          else if (sv[k] == "ADD"){
            first = s.top();
            s.pop();
            first += s.top();
            s.pop();
            s.push(first);
          }
          else if (sv[k] == "SUB"){
            first = s.top();
            s.pop();
            first = s.top() - first;
            s.pop();
            s.push(first);
          }
          else if (sv[k] == "MUL"){
            first = s.top();
            s.pop();
            first *= s.top();
            s.pop();
            s.push(first);
          }
          else if (sv[k] == "DIV"){
            first = s.top();
            s.pop();
            if (first == 0){
              count = 0;
            }
            else{
              first = s.top() / first;
              s.pop();
              s.push(first);
            }
          }
          else if (sv[k] == "MOD"){
            first = s.top();
            s.pop();
            if (first == 0){
              count = 0;
            }
            first = s.top() % first;
            s.pop();
            s.push(first);
          }
        }

        size = s.size();

        if (size == 1 && s.top() < 1000000000 && s.top() > -1000000000 && count == 1){
          cout << s.top() << "\n";
        }
        else{
          cout << "ERROR" << "\n";
        }
        if (size != 0){
          for (int l = 0; l < size; l++){
            s.pop();
          }
        }
      }
      cout << "\n";
    }
  }
  return 0;
}

/*
DUP
MUL
NUM 2
ADD
END
3
1
10
50

NUM 1
NUM 1
ADD
END
2
42
43

NUM 600000000
ADD
END
3
0
600000000
1

QUIT
*/