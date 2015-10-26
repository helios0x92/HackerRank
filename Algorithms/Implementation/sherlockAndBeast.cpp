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
    int N;
    string res = "";
    cin >> N;
    int count3 = -1, count5 = -1;
    for(int i = N/3; i >= 0; i--) {
      if((N-3*i)%5 == 0) {
	count5 = i;
	count3 = (N-3*i)/5;
	break;
      }
    }
    if(count5 == -1) cout << -1 << endl;
    else {
      for(int i = 0; i < 3*count5; i++) {
	res.push_back('5');
      }
      for(int i = 0; i < 5*count3; i++) {
	res.push_back('3');
      }
      cout << res << endl;
    }
  }
  return 0;
}
