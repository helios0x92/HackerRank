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
  int t;
  cin >> t;
  // your code goes here
  long long tab = 1, oneCount = 0;
  for(int i = 1; i <= t; i++) {
    if(i%2 == 0) tab++;
    oneCount += tab;
  }
  cout << oneCount << endl;
  return 0;
}
