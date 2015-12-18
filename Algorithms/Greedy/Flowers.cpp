/* Sample program illustrating input/output */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void){



  //Helpers for input and output

  int N, K;
  cin >> N >> K;
  vector<int> C(N);
  for(int i = 0; i < N; i++){
    cin >> C[i];
  }

  int result = 0;
  sort(C.begin(), C.end(), greater<int>());
  int m = 0;
  for(int i = 0; i < N; i += K) {
    for(int j = i; j < i+K && j < N; j++) {
      result += (m+1)*C[j];
    }
    m++;
  }

  cout << result << "\n";

  return 0;
}
