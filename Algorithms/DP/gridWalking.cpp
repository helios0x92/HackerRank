#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
#define MOD 1000000007;

ll countWays(vector<int> &x, vector<int> &d, int M) {
  int N = x.size();
  vector<vector<ll>> dStp(M+1, vector<ll>(N+1));
  for(int i = 0; i < N; i++) {
    vector<vector<ll>> mStp(d[i]+1, vector<ll>(M+1,0));
    int D = d[i];
    for(int j = 0; j <= D; j++) mStp[j][0] = 1;
    for(int k = 1; k <= M; k++) {
      for(int j = 1; j <= D; j++ ) {
	if(j-1 > 0) mStp[j][k] = (mStp[j][k] + mStp[j-1][k-1]) % MOD;
	if(j+1 <= D) mStp[j][k] =  (mStp[j][k] + mStp[j+1][k-1]) % MOD;
      }
    }
    dStp[0][i+1] = 1;
    for(int j = 1; j <= M; j++) dStp[j][i+1] = mStp[x[i][j]];
  }
  vector<vector<ll>> C(M+1, vector<ll>(M));
  for(int i = 0; i <= M; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
  }
  for(int i = 1; i <= M; i++) {
    for(int j = 1; j < i; j++) {
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }
  }
  vector<vector<ll>> ttlStp(M+1, vector<ll>(N+1, 0));
  for(int i = 0; i <= M; i++) ttlStp[i][1] = dStp[i][1];
  for(int i = 0; i <= N; i++) ttlStp[0][i] = 1;

  for(int i = 2; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      for(int k = 0; k <= j; k++) {
	ttlStp[j][i] = (ttlStp[j][i] +
			((C[j][j - k] *
			  ((ttlStp[k][i - 1] * dStp[j - k][i]) % MOD)) % MOD)) % MOD; 
      }
    }
  }
  return ttlStp[M][N];
}


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T;
  cin >> T;
  while(T--) {
    int M,N;
    cin >> N >> M;
    vector<int> x(N);
    vector<int> d(N);
    for(int i = 0; i < N; i++) cin >> x[i];
    for(int i = 0; i < N; i++) cin >> d[i];
    cout << countWays(x,d,M) << endl;
  }
  return 0;
}
