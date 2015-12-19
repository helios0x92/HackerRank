#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long getMinBotEnergy(long long botEnergy, long long curHeight) {
  long long energyDiff = 0;

  if(botEnergy > curHeight) {
    energyDiff = botEnergy;
    botEnergy = curHeight;
    curHeight = energyDiff;
  }
  energyDiff = curHeight - botEnergy;
  botEnergy += energyDiff/2;
  botEnergy += energyDiff%2;

  return botEnergy;
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i = 0; i < N; i++) cin >> H[i];
  long long botEnergy = 0;
  for(int i = N-1; i >= 0; i--) {
    botEnergy = getMinBotEnergy(botEnergy, H[i]);
  }
  cout << botEnergy << endl;
  return 0;
}
