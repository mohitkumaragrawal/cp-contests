#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T, typename ComparatorFn = less<T>>
// using ordered_set = tree<T, null_type, ComparatorFn, rb_tree_tag,
//                          tree_order_statistics_node_update>;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll MOD = 1e9 + 7;

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

ll perm_sum[10000];

void solve() {
  ll N, S;
  cin >> N >> S;

  ll b_sum = 0, b_max = 1;
  for (ll i = 0; i < N; ++i) {
    ll x;
    cin >> x;

    b_sum += x;
    b_max = max(b_max, x);
  }

  ll psum = b_sum + S;

  if (perm_sum[psum] >= b_max) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  for (ll i = 0; i < 10000; ++i) perm_sum[i] = -1;
  for (ll i = 1; i < 10000; ++i) {
    ll sum = i * (i + 1);
    sum /= 2;

    if (sum >= 10000) break;
    perm_sum[sum] = i;
  }
  ll T;
  cin >> T;
  while (T--) solve();
}
