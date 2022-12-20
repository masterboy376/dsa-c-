#include <iostream>
#include <vector>
using namespace std;

// friend pairing problem

const int MOD = 1e9 + 7, N = 1e3 + 2;

int main() {
  int n;cin>>n;
  vector<int> dp(n+1,0);
  dp[0]=1;
  dp[1]=1;
  for(int i = 2; i<=n;i++){
    dp[i] = dp[i-1] + (i-1)*dp[i-2];
  }
  cout<<dp[n]<<endl;
  
  return 0;
}
