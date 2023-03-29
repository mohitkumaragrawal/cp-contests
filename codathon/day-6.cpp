#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

struct sieve_t {
  sieve_t(int n, bool gen_primes = false, bool gen_sieve = false) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
      for (int j = i * i; j <= n; j += i) is_prime[j] = false;
    }
    if (gen_primes) {
      for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) primes.push_back(i);
      }
    }
    if (gen_sieve) {
      sieve.assign(n + 1, -1);
      for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
          sieve[i] = i;
          if ((ll)i * i <= n) {
            for (int j = i * i; j <= n; j += i) {
              if (sieve[j] == -1) sieve[j] = i;
            }
          }
        }
      }
    }
  }
  // requires gen_fact; works only upto sz;
  vector<int> fast_factorize(int k) {
    vector<int> res;
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
    for (int p : primes) {
      ll prime = p;
      if (prime * prime > k) break;
      while (k % prime == 0) {
        k /= prime;
        res.push_back(prime);
      }
    }
    if (k > 1) res.push_back(k);
    return res;
  }
  vector<bool> is_prime;
  vector<int> primes;
  vector<int> sieve;
};

sieve_t sv(1e6 + 20, true, true);
ll calc_cost(vector<ll> a, ll k) {
  for (auto& x : a) x = x % k;
  ll cost = 0;
  ll prev = -1;

  for (ll i = 0; i < a.size(); ++i) {
    if (a[i] == 0) continue;
    if (prev == -1) {
      prev = i;
      continue;
    }

    ll to_sub = -a[prev];
    ll to_add = k - a[prev];

    ll transfer;
    if (abs(to_sub) < to_add) {
      transfer = to_sub;
    } else {
      transfer = to_add;
    }

    cost += abs(transfer) * (i - prev);

    a[i] = (k + a[i] - transfer) % k;

    if (a[i] == 0)
      prev = -1;
    else
      prev = i;
  }

  return cost;
}

const ll INF = 1e18;

ll find_cost(vector<ll> a) {
  ll sum = 0;
  for (ll x : a) sum += x;

  auto factors = sv.factorize(sum);
  factors.erase(unique(all(factors)), factors.end());

  ll cost = INF;
  for (auto f : factors) {
    cost = min(cost, calc_cost(a, f));
  }

  if (cost == INF) return -1;
  return cost;
}

void solve() {
  ll n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<ll> cartoons(all(a));
  auto cost = find_cost(cartoons);

  cout << cost << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
