#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll lcm(ll a, ll b) {
  return (a * b) / __gcd(a, b);
}

void solve() {
  int N;
  cin >> N;

  vector<ll> A(N);

  for (auto& i: A) cin >> i;

  vector<ll> B(N+1);

  B[0] = A[0];
  for (int i = 1; i < N; ++i) {
    B[i] = lcm(A[i], A[i-1]);
  }
  B[N] = A[N-1];

  bool success = true;

  for (int i = 0; i < N; ++i) {
    int g = __gcd(B[i], B[i+1]);
    if (g != A[i]) {
      success = false;
      break;
    }
  }

  if (success) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) solve(); 
}