#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> S(N);
    vector<long long> D(N);

    for(int i = 0; i < N; i++) cin >> A[N-i-1];

    long long res = 0;
    if(N < 4) {
      for(int i = 0; i < N; i++) res += A[i];
      cout << res << "\n";
      continue;
    }
    S[0]  = A[0];
    for(int i = 1; i < N; i++) S[i] = S[i-1] + A[i];
    D[0] = A[0];
    D[1] = D[0] + A[1];
    D[2] = D[1] + A[2];
    for(int i = 3; i < N; i++) {
      long long s1 = A[i] + S[i-1] - D[i-1];
      long long s2 = A[i] + A[i-1] + S[i-2] - D[i-2];
      long long s3 = A[i] + A[i-1] + A[i-2] + S[i-3] - D[i-3];
      D[i] = max(s1, max(s2, s3));
    }
    cout << D[N-1] << "\n";
  }
  return 0;
}
