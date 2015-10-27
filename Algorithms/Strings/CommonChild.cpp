#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  string A,B;
  cin >> A >> B;
  int M = A.size();
  int N = B.size();
  vector<vector<int>> D(M+1, vector<int>(N+1));
  for(int i = 0; i < N+1; i++) {
    for(int j = 0; j < M+1; j++) {
      if(i == 0 || j == 0) D[i][j] = 0;
      else if(A[i-1] == B[j-1]) D[i][j] = 1 + D[i-1][j-1];
      else D[i][j] = max(D[i-1][j], D[i][j-1]);
    }
  }
  cout << D[M][N] << endl;
  return 0;
}
