#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int N, M;
  cin >> N >> M;
  vector<int> A(N, 0);
  vector<pair<long long, long long>> D;
  while(M--) {
    long long  a, b, k;
    cin >> a >> b >> k;
    D.push_back(make_pair(a, k));
    D.push_back(make_pair(b+1, -k));
  }
  sort(D.begin(), D.end());
  long long res = 0, cur = 0;
  for(int i = 0; i < D.size(); ) {
    int j = i;
    while(j < D.size() && D[j].first == D[i].first) {
      cur += D[j].second;
      j++;
    }
    i = j;
    res = max(res, cur);
  }
  cout << res << endl;
  return 0;
}
