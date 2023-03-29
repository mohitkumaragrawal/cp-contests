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

sieve_t sv(400005, true, true);

vector<vector<int>> G;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);

  G.resize(300005 * 2);
  const int MX = n + 1;

  for (int i = 1; i <= n; ++i) {
    int val;
    cin >> val;

    a[i] = val;

    auto f = sv.fast_factorize(val);
    f.erase(unique(all(f)), f.end());

    for (int prime : f) {
      int v = prime + MX;
      G[i].push_back(v);
      G[v].push_back(i);
    }
  }

  int x, y;
  cin >> x >> y;

  if (x == y) {
    cout << "1\n";
    cout << x << '\n';
    return;
  }

  if (__gcd(a[x], a[y]) != 1) {
    cout << "2\n";
    cout << x << " " << y << '\n';
    return;
  }

  // now do bfs;

  map<int, int> parent;
  vector<bool> vis(300005 * 2, false);

  queue<int> q;

  q.push(x);
  vis[x] = true;
  parent[x] = -1;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (int child : G[curr]) {
      if (vis[child]) continue;

      q.push(child);
      vis[child] = true;
      parent[child] = curr;
    }
  }

  if (!vis[y]) {
    cout << "-1\n";
    return;
  }

  vector<int> ans;
  int it = y;

  while (it != x) {
    if (it < MX) {
      ans.push_back(it);
    }
    it = parent[it];
  }

  ans.push_back(x);
  reverse(all(ans));

  cout << ans.size() << "\n";
  for (int k : ans) {
    cout << k << " ";
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
