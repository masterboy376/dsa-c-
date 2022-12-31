#include <iostream>
#include <vector>
using namespace std;

// segment tree, fenwick tree, sieve of eratosthenes, range minimum query,
// segmented sieve, totient function

/*
updates in fenwick tree
-range sum with point updates
-rage sum with range update
*/

const int N = 1e5 + 2;

int n;
vector<int> bit;

void update(int idx, int val) {
  while (idx <= n) {
    bit[idx] += val;
    idx += idx & (-idx);
  }
}

int query(int idx) {
  int ans = 0;
  while (idx > 0) {
    ans += bit[idx];
    idx -= idx & (-idx);
  }
  return ans;
}

int main() {
  cin >> n;
  bit = vector<int>(n + 1);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    update(i, a[i]);
  }
  int q;
  cin >> q;
  while (q--) {
    int c;
    cin >> c;
    if (c == 1) {
      int l, r;
      cin >> l >> r;
      int ans = query(r) - query(l - 1);
      cout << ans << endl;
    } else if (c == 2) {
      int idx, val;
      cin >> idx >> val;
      update(idx, -a[idx]);
      a[idx] = val;
      update(idx, val);
    }
  }

  return 0;
}
