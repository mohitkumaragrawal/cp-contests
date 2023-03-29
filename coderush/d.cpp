#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll a[1000006], n;

ll max_sum() {
  ll cleft[n], cright[n];
  fill(cleft, cleft + n, 0LL);
  fill(cright, cright + n, 0LL);
  stack<ll> q;

  for (ll i = 0; i < n; i++) {
    while (q.size() != 0 && a[q.top()] <= a[i]) {
      cleft[i] += cleft[q.top()] + 1;
      q.pop();
    }
    q.push(i);
  }

  while (q.size() != 0) q.pop();

  for (ll i = n - 1; i >= 0; i--) {
    while (q.size() != 0 && a[q.top()] < a[i]) {
      cright[i] += cright[q.top()] + 1;
      q.pop();
    }
    q.push(i);
  }

  while (q.size() != 0) q.pop();
  ll ans = 0;
  for (ll i = 0; i < n; i++) ans += (cleft[i] + 1) * (cright[i] + 1) * a[i];

  return ans;
}

ll min_sum() {
  ll cleft[n], cright[n];
  fill(cleft, cleft + n, 0LL);
  fill(cright, cright + n, 0LL);
  stack<ll> q;

  for (ll i = 0; i < n; i++) {
    while (q.size() != 0 && a[q.top()] >= a[i]) {
      cleft[i] += cleft[q.top()] + 1;
      q.pop();
    }
    q.push(i);
  }

  while (q.size() != 0) q.pop();

  for (ll i = n - 1; i >= 0; i--) {
    while (q.size() != 0 && a[q.top()] > a[i]) {
      cright[i] += cright[q.top()] + 1;
      q.pop();
    }
    q.push(i);
  }

  while (q.size() != 0) q.pop();
  ll ans = 0;
  for (ll i = 0; i < n; i++) ans += (cleft[i] + 1) * (cright[i] + 1) * a[i];

  return ans;
}

void solve() {
  cin >> n;
  for (ll i = 0; i < n; ++i) cin >> a[i];

  cout << max_sum() - min_sum() << endl;
}

int main() { solve(); }
