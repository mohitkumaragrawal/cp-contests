#include <bits/stdc++.h>
using namespace std;

#define long long long

ostream& operator<<(ostream& out, vector<long>& v) {
  for (long i : v) {
    out << i << " ";
  }
  return out;
}

// binary_search me while (high >= low) condition hota hai (high > low) ni hota

long binary_search(vector<long>& arr, long req) {
  long low = 0, high = arr.size() - 1;

  if (arr.back() < req) return -1;

  long ans = arr.size() - 1;
  while (high >= low) {
    long mid = low + (high - low) / 2;

    if (arr[mid] >= req) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

// longs are not guranteed to be 64 bit; but long longs are;

int main() {
  int T;
  cin >> T;

  while (T--) {
    long N, M;
    cin >> N >> M;

    vector<long> A(N);
    for (long& i : A) cin >> i;

    vector<long> ones, twos;
    for (long i = 0; i < N; ++i) {
      long cost;
      cin >> cost;
      if (cost == 1) {
        ones.push_back(A[i]);
      } else {
        twos.push_back(A[i]);
      }
    }

    // sort in reverse order;

    sort(ones.begin(), ones.end(), greater<long>());
    sort(twos.begin(), twos.end(), greater<long>());

    vector<long> s1, s2;

    // ones and twos might be empty; push 0 so that it won't affect the answer;

    if (ones.empty()) {
      ones.push_back(0);
    }
    if (twos.empty()) {
      twos.push_back(0);
    }

    s1.resize(ones.size());
    s1[0] = ones[0];
    for (int i = 1; i < ones.size(); ++i) {
      s1[i] = s1[i - 1] + ones[i];
    }

    s2.resize(twos.size());
    s2[0] = twos[0];
    for (int i = 1; i < twos.size(); ++i) {
      s2[i] = s2[i - 1] + twos[i];
    }

    // be careful for what we check;

    if (s1.back() + s2.back() < M) {
      cout << -1 << endl;
      continue;
    }

    long ans = 1e+7;
    // there might be a case when we selected no element from ones :)
    for (int i = 0; i <= s1.size(); ++i) {
      long freed = (i == 0) ? 0 : s1[i - 1];
      long cost = i;
      long req = M - freed;

      if (req > 0) {
        auto idx = binary_search(s2, req);

        if (idx == -1) continue;
        cost += (idx + 1) * 2;
      }

      ans = min(ans, cost);
    }
    cout << ans << endl;
  }
}