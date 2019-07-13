//https://www.hackerrank.com/challenges/crush/problem
//het-
//O(n)
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  vector<long long> v(n + n, 0);
  for (long long i = 0; i < m; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    // if(x-1>n-1)break;
    v[x - 1] += z;
    // if(y>n-1)break;
    v[y - 1 + 1] -= z;
  }
  long long maxxx = v[0];
  for (long long i = 1; i < n; i++) {
    v[i] += v[i - 1];
    maxxx = max(maxxx, v[i]);
  }

  cout << maxxx;
}
// oooooo sexy
