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
    int M, N;
    const int MOD = 1000000007;
    cin >> M >> N;
    M--;
    N--;
    vector<int> Y(M);
    vector<int> X(N);
    for(int i = 0; i < M; i++) cin >> Y[i];
    for(int i = 0; i < N; i++) cin >> X[i];

    int hSeg = 1, i = N-1;
    int vSeg = 1, j = M-1;
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    long long res = 0;
    while(i >= 0 && j >= 0) {
      if(X[i] > Y[j]){
	res = (res + ((long long)X[i--])*hSeg)%MOD;
	++vSeg;
      } else {
	res = (res + ((long long)Y[j--])*vSeg)%MOD;
	++hSeg;
      }
    }
    while(i >= 0){
      res = (res + ((long long)X[i--])*hSeg)%MOD;
    }
    while(j >= 0){
      res = (res + ((long long)Y[j--])*vSeg)%MOD;
    }
    cout << res << endl;
  }
  return 0;
}
