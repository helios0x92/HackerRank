#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T;
  cin >> T;
  while(T--) {
    string s;
    cin >> s;
    int N = s.size();
    ll res = 0;
    map<string, ll> H;
    for(int i = 0; i < N; i++) {
      for(int L = 1; i+L-1 < N; L++) {
	string st = s.substr(i, L);
	sort(st.begin(), st.end());
	H[st]++;
      }
    }
    map<string, ll>::const_iterator it = H.begin();
    for(; it != H.end(); it++) {
      ll n = it->second;
      res += (n*(n-1))/2;
    }
    cout << res << endl;
  }
  return 0;
}
