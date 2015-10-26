#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) {
  int p = 0, r = s.size()-1;
  while(p < r) {
    if(s[p] != s[r]) return false;
    p++;
    r--;
  }
  return true;
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T;
  cin >> T;
  while(T--) {
    string s;
    cin >> s;
    int p = 0, res = -1;
    int r = s.size()-1;
    while(p < r && (s[p] == s[r])) {
	p++;
	r--;
    }
    if(p < r) {
      string s1 = s.substr(0,p) + s.substr(p+1);
      string s2 = s.substr(0,r) + s.substr(r+1);
      if(isPalindrome(s1)) res = p;
      if(isPalindrome(s2)) res = r;
    }
    cout << res << endl;
  }
  return 0;
}
