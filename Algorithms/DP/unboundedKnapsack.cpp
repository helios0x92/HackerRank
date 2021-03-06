#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(vector<int> &W, int K) {
  vector<int> S(K+1);
  S[0] = 0;
  for(int i = 1; i <= K; i++) {
    int max_wt = S[i-1];
    for(int j = 0; j < W.size(); j++) {
      int w = i - W[j];
      if(w >= 0 && (S[w] + W[j]) > max_wt) max_wt = S[w] + W[j];
      S[i] = max_wt;
    }
  }
  return S[K];
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T;
  cin >> T;
  while(T--) {
    int N,K;
    cin >> N >> K;
    vector<int> W(N);
    for(int i = 0; i < N; i++) cin >> W[i];
    cout << knapsack(W,K) << endl;
  }
  return 0;
}
