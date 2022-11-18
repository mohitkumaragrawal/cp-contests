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
#define DEBUG2(x, y)
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

ll N, M;

void solve() {
  cin >> N >> M;

  ll f2 = 0, f5 = 0;
  ll n = N;

  while (n % 2 == 0) {
    f2++;
    n /= 2;
  }

  while (n % 5 == 0) {
    f5++;
    n /= 5;
  }

  DEBUG2(f2, f5);

  ll old_round = min(f2, f5);

  ll k = 1;
  while (k <= M) {
    DEBUG2(f2, f5);
    if (f2 < f5) {
      if (k * 2 <= M) {
        k *= 2;
        f2++;
        DEBUG2(f2, f5);
        continue;
      } else {
        break;
      }
    }

    if (f5 < f2) {
      if (k * 5 <= M) {
        k *= 5;
        f5++;
        DEBUG2(f2, f5);
        continue;
      } else {
        break;
      }
    }

    if (k * 10 <= M) {
      k *= 10;
      f2++, f5++;
      DEBUG2(f2, f5);
    } else {
      break;
    }
  }

  ll left = (M / k);
  k *= left;

  ll final_round = min(f2, f5);
  if (old_round == final_round) {
    cout << N * M << endl;
  } else {
    cout << N * k << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
