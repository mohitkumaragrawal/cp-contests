#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int N;
  cin >> N;

  vector<ll> A(N);
  for (auto& i : A) cin >> i;

  ll ans = 0;

  deque<ll> b;
  for (int i = 0; i < N; ++i) {
    ll el = A[i];

    while (b.size() >= el) {
      b.pop_front();
    }
    b.push_back(el);
    ans += b.size() ;
  } 

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  
}