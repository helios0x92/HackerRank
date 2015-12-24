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
    cin >> N;
    vector<int> A(N);
    int minVal = INT_MAX;
    for(int i = 0; i < N; i++) {
      cin >> A[i];
      if(A[i] < minVal) minVal = A[i];
    }
    vector<long long> nOp(6);
    long long minOp = INT_MAX;
    for(int i = 0; i < 6; i++) {
      for(int j = 0; j < N; j++) {
	int nChange = abs(A[j]-(minVal-i));
	nOp[i] += (nChange/5);
	nOp[i] += (nChange%=5)/2;
	nOp[i] += (nChange&1);
      }
    }
    cout << *min_element(nOp.begin(), nOp.end()) << "\n";
  }
  return 0;
}
