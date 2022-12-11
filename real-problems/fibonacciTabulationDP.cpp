#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// dynamic programming: fibonacci series

const int inf = 1e5 + 2;

int main() {
  int n;
  cin >> n;

  vector<int> dp(n+1);
  dp[0]=0;
  dp[1]=0;
  dp[2]=1;
  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i-1]+dp[i-2];
  }

  cout << dp[n] << endl;

  return 0;
}
