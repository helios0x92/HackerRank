#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int N;
  cin >> N;
  vector<int> A(10005);
  for(int i = 0; i < N; i++) {
    int w;
    cin >> w;
    A[w]++;
  }

  int minUnits = 0;
  for(int i = 0; i <= 10000; i++ ) {
    if(A[i]) {
      minUnits++;
      for(int j = 0 ; j <= 4 ; j++) A[i+j] = 0;
    }
  }
  cout << minUnits;
  return 0;
}
