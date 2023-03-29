#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

struct sieve_t {
  sieve_t(ll n, bool gen_primes = false, bool gen_sieve = false) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; ++i) {
      for (ll j = i * i; j <= n; j += i) is_prime[j] = false;
    }
    if (gen_primes) {
      for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) primes.push_back(i);
      }
    }
    if (gen_sieve) {
      sieve.assign(n + 1, -1);
      for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) {
          sieve[i] = i;
          if ((ll)i * i <= n) {
            for (ll j = i * i; j <= n; j += i) {
              if (sieve[j] == -1) sieve[j] = i;
            }
          }
        }
      }
    }
  }
  // requires gen_fact; works only upto sz;
  vector<ll> fast_factorize(ll k) {
    vector<ll> res;
    while (k > 1) {
      ll p = sieve[k];
      res.push_back(p);
      k /= p;
    }
    return res;
  }
  // requies gen_primes; works upto sz*sz;
  vector<ll> factorize(ll k) {
    vector<ll> res;
    for (ll p : primes) {
      if (p * p > k) break;
      while (k % p == 0) {
        k /= p;
        res.push_back(p);
      }
    }
    if (k > 1) res.push_back(k);
    return res;
  }
  vector<bool> is_prime;
  vector<ll> primes;
  vector<ll> sieve;
};

sieve_t sv(sqrt(1e9 + 20), true, false);

vector<ll> find_divisors(ll n) {
  vector<ll> pf = sv.factorize(n);
  vector<ll> res;

  for (ll i = 0; i < (1 << pf.size()); ++i) {
    ll cur = 1;
    for (ll j = 0; j < pf.size(); ++j) {
      if (i & (1 << j)) cur *= pf[j];
    }
    res.push_back(cur);
  }

  res.erase(unique(all(res)), res.end());
  return res;
}

#ifdef _DEBUG
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n), b(n);
  for (ll i = 0; i < n; ++i) cin >> a[i] >> b[i];

  map<ll, ll> dp;

  vector<ll> pre(n + 1, 1e18);
  pre[0] = 1;

  bool fixed_d = false;
  ll d = -1;

  ll G = -1;

  for (ll i = 1; i < n; ++i) {
    if (fixed_d) {
      if (d * b[i - 1] % b[i] == 0) {
        d = (d * b[i - 1]) / b[i];

        if (a[i] % d == 0) {
          pre[i] = pre[i - 1];
        } else {
          fixed_d = false;
          pre[i] = pre[i - 1] + 1;
        }

      } else {
        fixed_d = false;
        pre[i] = pre[i - 1] + 1;
      }
      continue;
    }

    ll n1 = a[i - 1] * b[i - 1];
    ll n2 = a[i] * b[i];

    ll g = __gcd(n1, n2);

    if (g % b[i] == 0 && g % b[i - 1] == 0) {
      pre[i] = pre[i - 1];
      fixed_d = true;

      ll d1 = g / b[i];
      ll d2 = g / b[i - 1];

      // d = __gcd(d1, d2);
      // d = d1 / d;
      //
      d = d1;
      G = __gcd(d1, d2);
    } else {
      pre[i] = pre[i - 1] + 1;
    }
  }

  ll ans = pre[n - 1];
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
