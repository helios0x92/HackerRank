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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    vector<int> B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    bool flag = true;
    for(int i = 0; i < N; i++) {
      A[i] += B[N-1-i];
      if(A[i] < K) {
	flag = false;
	break;
      }
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
