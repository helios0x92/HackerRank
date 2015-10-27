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
    string A,B, res;
    cin >> A >> B;
    int i = 0, j = 0;
    while(i < A.size() && j < B.size()) {
      if(A[i] > B[j]) res += B[j++];
      else if(A[i] < B[j]) res += A[i++];
      else {
	int x = i, y = j;
	char a = A[i];
	for(; x < A.size() && y < B.size(); x++, y++) {
	  if (A[x] != B[y]) {
	    break;
	  } else if (A[x] > a) {
	    res += A.substr(i, x-i) + B.substr(j, y-j);
	    i = x; j = y;
	    a = A[x];
	  }
	}

	if (x == A.size()) {
	  res += B[j];
	  j++;
	} else if (y == B.size()) {
	  res += A[i];
	  i++;
	} else {
	  if (A[x] < B[y]) {
	    res += A[i];
	    i++;
	  } else {
	    res += B[j];
	    j++;
	  }
	}
      }
    }
    res += A.substr(i) + B.substr(j);
    
    cout << res << endl;
  }
  return 0;
}
