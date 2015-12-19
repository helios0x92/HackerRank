#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, priority_queue<int, vector<int>, greater<int>>> H;
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    for(int i = 0; i < N; i++) {
      int skill = A[i];
      int teamSize = 0;
      auto it = H.find(skill - 1);
      if(it != H.end() && it->second.size()) {
	teamSize = it->second.top();
	it->second.pop();
      }
      teamSize++;
      H[skill].push(teamSize);
    }
    int minTeamSize = INT_MAX;
    for(auto skill : H) {
      if(skill.second.size()) {
	minTeamSize = min(minTeamSize, skill.second.top());
      }
    }
    if(minTeamSize == INT_MAX) cout << 0 << endl;
    else cout << minTeamSize << endl;
  }
  return 0;
}
