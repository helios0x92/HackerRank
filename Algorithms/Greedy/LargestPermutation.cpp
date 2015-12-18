#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int N,K;
  cin >> N >> K;
  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  int i =  0;
  while(K && i < N) {
    if(*max_element(A.begin()+i, A.end()) == A[i]) {
      i++;
      continue;
    } else {
      iter_swap(A.begin()+i, max_element(A.begin()+i, A.end()));
      i++;
      K--;
    }
  }
  for(int i = 0; i < N; i++) cout <<  A[i] << " ";
  cout << endl;
  return 0;
}
