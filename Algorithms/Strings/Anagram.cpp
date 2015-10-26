#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T;
  cin >> T;
  while(T--) {
    string s;
    cin >> s;
    vector<int> C(26,0);
    if(s.size()%2 != 0) {
      cout << -1 << endl;
      continue;
    }
    string s1 = s.substr(0, s.size()/2);
    string s2 = s.substr(s.size()/2);
    
    for(int i = 0; i < s2.size(); i++) C[s2[i]-'a']++;
    for(int i = 0; i < s1.size(); i++) C[s1[i]-'a']--;
    int res = 0;
    for(int i = 0; i < 26; i++) res += (C[i] > 0 ? C[i] : 0);
    cout << res << endl;
  }
  return 0;
}
