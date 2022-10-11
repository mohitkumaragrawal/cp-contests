#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int N;
  cin >> N;
  
  vector<int> A(N), B(N);
  for (int& i: A) cin >> i;
  for (int& i: B) cin >> i;

  int op = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] != B[i]) ++op;
  }

  int tmp = 1;
  sort(all(A));
  sort(all(B));

  for (int i = 0; i < N; ++i) {
    if (A[i] != B[i]) ++tmp;
  }
  op = min(op, tmp);
  cout << op << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) solve(); 
}