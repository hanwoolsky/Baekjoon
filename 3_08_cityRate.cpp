#include <iostream>
#include <map>

using namespace std;

int main() {
  map<string, double> mp;
  string command;
  int count = 0;
  
  while (getline(cin, command)){
    mp[command]++;
    count++;
  }
  cout << fixed;
  cout.precision(4);

  for(auto iter=mp.begin(); iter!=mp.end(); iter++){
    cout << iter->first << " ";
    cout << (100 * iter->second / count) << "\n";
  } 
}