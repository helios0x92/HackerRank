#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  vector<int> C(26, 0);
  vector<int> D(26, 0);
  for(int i = 0; i < s.size(); i++) C[s[i]-'a']++;
  for(int i = 0; i < 26; i++) D[i] = C[i]/2;
  string res = "";
  int N = s.size();
  int i = 0;
  while(res.size() < N/2) {
    int idx = -1;
    while(true) {
      if(D[s[i]-'a'] > 0 && (idx < 0 || s[i] < s[idx] )) idx = i;
      --C[s[i]-'a'];
      if(C[s[i]-'a'] < D[s[i]-'a']) break;
      i++;
    }
    for(int j = idx+1; j < i+1; j++) C[s[j]-'a']++;
    D[s[idx]-'a']--;
    res.push_back(s[idx]);
    i = idx + 1;
  }
  cout << res << endl;
  return 0;
}
