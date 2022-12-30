#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

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
  vector<int> factorize(int k) {
    vector<int> res;
    for (int p : primes) {
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
  vector<int> primes;
  vector<int> sieve;
};

sieve_t sv(200005, true, true);
bool even_div[200005];

void solve() {
  ll x = 0;
  for (ll i = 2; i <= 100; ++i) {
    if (even_div[i]) {
      cout << i << " ";
    }
    x++;
  }
  cout << endl;
  cout << x << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  even_div[0] = false;
  even_div[1] = false;

  for (ll i = 2; i <= 200000; ++i) {
    auto pf = sv.fast_factorize(i);
    map<int, int> mp;
    for (auto x : pf) mp[x]++;

    bool res = false;
    for (auto pr : mp) {
      if (pr.second & 1) {
        res = true;
        break;
      }
    }

    even_div[i] = res;
  }

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
