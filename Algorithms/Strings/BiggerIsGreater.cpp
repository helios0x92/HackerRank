#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


template <class Iterator>
bool m_next_permutation(Iterator begin, Iterator end) {
  if (begin == end) return false;
  Iterator i = end;
  if (begin == --i) return false;
  while(true) {
    Iterator j = i, k;
    if (*--i < *j) {
      k = end;
      while (!(*i < *--k));
      std::iter_swap(i, k);
      std::reverse(j, end);
      return true;
    }
    if (i == begin) {
      std::reverse(begin, end);
      return false;
    }
  }
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T;
  cin >> T;
  while(T--) {
    string s;
    cin >> s;
    if(m_next_permutation(s.begin(), s.end())) cout << s << endl;
    else cout << "no answer" << endl;		 
  }
  return 0;
}
