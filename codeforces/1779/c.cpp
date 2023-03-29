#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

// MISTAKE:
// used set, which removed the duplicate elements :)
// solution:
//  use multiset: when you are querying for maximum or minimum value on the
//  processed elements; careful when using multiset::erase method as it erase
//  all the occurence of that element; instead use
//  multiset::erase(multiset::find(element)) thing
//
//  GOOD THING: I had the right idea;

void solve() {
  ll n, m;
  cin >> n >> m;

  ll a[n];
  for (ll i = 0; i < n; ++i) cin >> a[i];

  m--;
  ll ops = 0;
  ll sum = 0;

  multiset<ll, greater<ll>> mx_set;

  for (ll i = m; i > 0; --i) {
    sum += a[i];
    mx_set.insert(a[i]);

    if (sum > 0) {
      ops++;

      ll mx = *mx_set.begin();
      sum -= 2 * mx;

      mx_set.erase(mx_set.find(mx));
      mx_set.insert(-mx);
    }
  }

  ll sum2 = sum;

  multiset<ll> mn_set;

  for (ll i = m + 1; i < n; ++i) {
    sum2 += a[i];
    mn_set.insert(a[i]);

    if (sum2 < sum) {
      ops++;

      ll mn = *mn_set.begin();
      sum2 -= 2 * mn;
      mn_set.erase(mn_set.find(mn));
      mn_set.insert(-mn);
    }
  }

  cout << ops << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
