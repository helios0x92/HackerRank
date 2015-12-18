#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int check(vector<int> A, int M) {
  for(int i = 0; i < A.size(); i++) A[i] = abs(A[i] - M);
  return *min_element(A.begin(), A.end());
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int N, P, Q;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  cin >> P >> Q;
  sort(A.begin(), A.end());
  int res = P;
  int R = check(A, P);
  for(int i = 0; i < N-1; i++) {
    int K = (A[i] + A[i+1])/2;
    int V = check(A, K);
    if(P <= K &&  K <= Q && V > R ){
      R = V;
      res = K;
    }
  }
  if(check(A, Q) > R) res = Q;
  cout << res << endl;
  return 0;
}
