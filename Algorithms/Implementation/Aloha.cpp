#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Complete the function below.
 */
string toAloha(int n) {
  string inStr = to_string(n+1);
  int N = inStr.size();
  string alohaAtr(N+1,' ');
  bool carry = false;

  for (int i = N - 1; i >= 0; i--) {
    if ((i + 1) < N) {
      if (inStr[i] != '4' && inStr[i] != '7') {
	for (int j = i + 1; j < N; j++) {
	  alohaStr[j+1] = '4';
	}
      }
    }
    if(carry) inStr[i] = (char) ((int) inStr[i] + 1);
    if (inStr[i] <= '4') {
      res[i + 1] = '4';
      extra = false;
    }
    else if (input[i] <= '7') {
      res[i + 1] = '7';
      extra = false;

    }
    else {
      res[i + 1] = '4';
      extra = true;
    }

  }
  if (extra == true) {
    res[0] = '4';
  }

  return res;
}

int main() {
  // ofstream fout(getenv("OUTPUT_PATH"));
  string res;
  int _n;
  cin >> _n;
  cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

  res = toAloha(_n);
  cout << res << endl;

  //fout.close();
  return 0;
}
