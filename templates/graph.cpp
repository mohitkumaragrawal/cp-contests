/**
 * 1. DSU
 * 2. Dijkstra's Algorithm
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
  ll parent[100005], dsize[100005];

  DSU() {
    iota(begin(parent), end(parent), 0);
    fill(begin(dsize), end(dsize), 1);
  }

  ll find_set(ll x) {
    if (x == parent[x]) return x;
    return parent[x] = find_set(parent[x]);
  }

  void union_set(ll a, ll b) {
    ll s1 = find_set(a);
    ll s2 = find_set(b);
    if (s1 == s2) return;

    if (dsize[s2] > dsize[s1]) swap(s1, s2);
    parent[s2] = s1;
    dsize[s1] += dsize[s2];
  }
};
