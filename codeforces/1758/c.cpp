#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#define __dis cout << "\033[1;31m* (" << __LINE__ << "):\033[0m "
#define LOG(x) __dis << x << endl
#define __m(x) #x "=" << x << "\t"
#define DEBUG(x) __dis << __m(x) << endl
#define DEBUG2(x, y) __dis << __m(x) << __m(y) << endl
#define DEBUG3(x, y, z) __dis << __m(x) << __m(y) << __m(z) << endl
#define DEBUG4(x, y, z, w) __dis << __m(x) << __m(y) << __m(z) << __m(w) << end
#else
#define endl '\n'
#define LOG(X)
#define DEBUG(X)
#define DEBUG2(x, y)
#define DEBUG3(x, y, z)
#define DEBUG4(x, y, z, w)
#endif

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
      sieve[j] = i;
    }
  }
}

// void solve() {
//   ll n, x;
//   cin >> n >> x;
//
//   vector<ll> ans(n + 1);
//   for (ll i = 1; i <= n; ++i) {
//     ans[i] = i;
//   }
//
//   if (n % x != 0) {
//     cout << "-1\n";
//     return;
//   }
//
//   ans[n] = 1;
//   ans[1] = x;
//
//   vector<ll> indices;
//   indices.push_back(x);
//
//   ll fact = n / x;
//   while (fact > 1) {
//     indices.push_back(indices.back() * sieve[fact]);
//     fact /= sieve[fact];
//   }
//
//   for (ull i = 0; i < indices.size() - 1; ++i) {
//     ans[indices[i]] = indices[i + 1];
//   }
//
//   for (ll i = 1; i <= n; ++i) {
//     cout << ans[i] << " ";
//   }
//   cout << endl;
// }

void solve() {
  ll n, x;
  cin >> n >> x;

  ll arr[n + 5];
  for (ll i = 1; i <= n; ++i) arr[i] = i;

  arr[1] = x;
  arr[n] = 1;

  if (n % x) {
    cout << "-1\n";
    return;
  }

  if (x == n) {
    for (ll i = 1; i <= n; ++i) cout << arr[i] << " \n"[i == n];
    return;
  }

  arr[x] = n;
  ll prev_idx = x;

  for (ll i = x + 1; i < n; ++i) {
    if (n % i) continue;

    DEBUG2(i, prev_idx);

    if (i % prev_idx == 0) {
      swap(arr[prev_idx], arr[i]);
      prev_idx = i;
    }
  }

  for (ll i = 1; i <= n; ++i) cout << arr[i] << " \n"[i == n];
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  // init_sieve();

  ll T;
  cin >> T;
  while (T--) solve();
}
