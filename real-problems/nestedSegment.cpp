#include "bits/stdc++.h"
#include <iostream>
#include <vector>
using namespace std;

// segment tree, fenwick tree, sieve of eratosthenes, range minimum query,
// segmented sieve, totient function

/*
nested segments
*/

const int N = 1e5 + 2, MOD = 1e9 + 7;
struct triplet {
  int l, r, idx;
};
vector<int> tree(4 * N);

int query(int node, int st, int en, int l, int r) {
  if (st > r || en < l) {
    return 0;
  }
  if (l <= st && r >= en) {
    return tree[node];
  }
  int mid = (st + en) / 2;
  int q1 = query(2 * node, st, mid, l, r);
  int q2 = query(2 * node + 1, mid + 1, en, l, r);

  return (q1 + q2);
}

void update(int node, int st, int en, int idx, int val) {
  if (st == en) {
    tree[node] = val;
    return;
  }

  int mid = (st + en) / 2;
  if (idx <= mid) {
    update(2 * node, st, mid, idx, val);
  } else {
    update(2 * node + 1, mid + 1, en, idx, val);
  }

  tree[node] = (tree[2 * node] + tree[2 * node + 1]);
}

bool compare(triplet t1, triplet t2) { return t1.r < t2.r; }

int main() {
  int n;
  cin >> n;
  triplet t1;
  t1.l = t1.r = -1;
  vector<triplet> t(n, t1);

  int x;

  for (int i = 0; i < 2 * n; i++) {
    cin >> x;
    if (t[x - 1].l == -1) {
      t[x - 1].l = i;
    } else {
      t[x - 1].r = i;
    }
    t[x - 1].idx = x;
  }

  sort(t.begin(), t.end(), compare);

  vector<int> ans(n);

  for (int i = 0; i < n; i++) {
    ans[t[i].idx - 1] = query(1, 0, 2 * n - 1, t[i].l, t[i].r);
    update(1, 0, 2 * n - 1, t[i].l, 1);
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}
