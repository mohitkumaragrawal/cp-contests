#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll sieve[200005];
void init_sieve() {
  for (ll i = 0; i < 100005; ++i) {
    sieve[i] = i;
  }

  for (ll i = 2; i * i < 100005; ++i) {
    if (sieve[i] != i) continue;
    for (ll j = i * i; j < 100005; j += i) {
      if (sieve[j] == j) sieve[j] = i;
    }
  }
}

void solve() {
  ll n, x;
  cin >> n >> x;

  vector<ll> ans(n + 1);
  for (ll i = 1; i <= n; ++i) {
    ans[i] = i;
  }

  if (n % x != 0) {
    cout << "-1\n";
    return;
  }

  ans[n] = 1;
  ans[1] = x;

  vector<ll> indices;
  indices.push_back(x);

  ll fact = n / x;
  while (fact > 1) {
    indices.push_back(indices.back() * sieve[fact]);
    fact /= sieve[fact];
  }

  for (ull i = 0; i < indices.size() - 1; ++i) {
    ans[indices[i]] = indices[i + 1];
  }

  for (ll i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  init_sieve();

  ll T;
  cin >> T;
  while (T--) solve();
}
