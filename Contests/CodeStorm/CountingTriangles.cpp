#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  map<long long, long long> H;
  long long P,Q,R,S = 0;
  long long acuteCount = 0, rightCount = 0, obtuseCount = 0;
  for(int A_i = 0;A_i < N;A_i++){
    cin >> A[A_i];
    H[A[A_i]]++;
  }
  // your code goes here
 
  for(int i = 0; i < N; i++) {
    for(int j = i+1; j < N; j++) {
      P = lower_bound(A.begin()+j+1, A.end(),(A[i]+A[j])) - A.begin();
      Q = A[i]*A[i] + A[j]*A[j];
      if((long long)sqrt(Q)*(long long)sqrt(Q) == Q){
	R = sqrt(Q);
	if(H[R] == 1) rightCount++;
      }
      if(j+1 >= P) continue;
      if((long long)sqrt(Q)*(long long)sqrt(Q) == Q)
	S = lower_bound(A.begin()+j+1, A.begin()+P, (long long)sqrt(Q)) - A.begin();
      else S = lower_bound(A.begin()+j+1, A.begin()+P, (long long)sqrt(Q)+1)-A.begin();
      if(S > j+1) acuteCount += (S-(j+1));
      if(A[S] == (long long)sqrt(Q) && (long long)sqrt(Q)*(long long)sqrt(Q) == Q)
	obtuseCount += (P-S-1);
      else obtuseCount += (P-S);
    }
  }
  cout << acuteCount <<" "<< rightCount <<" "<< obtuseCount;
  return 0;
}
