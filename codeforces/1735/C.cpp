#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int parent[26];
int dsu_size[26];

int find_set(int x) {
  if (x == parent[x]) return x;
  return parent[x] = find_set(parent[x]);
}

void union_set(int a, int b) {
  int p1 = find_set(a);
  int p2 = find_set(b);

  if (p1 == p2) return;
  if (dsu_size[p1] < dsu_size[p2]) swap(p1, p2);

  parent[p2] = p1;
  dsu_size[p1] += dsu_size[p2];
}

void solve() {
  iota(begin(parent), end(parent), 0);
  fill(begin(dsu_size), end(dsu_size), 1);

  int N;
  cin >> N;
  string str;
  cin >> str;

  char mp[26] = {0};
  vector<char> res(N);

  bool in[26] = {false}, out[26] = {false};

  for (int i = 0; i < N; ++i) {
    char c = str[i];

    if (mp[c - 'a'] == 0) {
      int key = c - 'a';
      int test = 0;

      while (test < 26) {
        if (in[test]) {
          test++;
          continue;
        }

        if (out[test]) {
          // check if in same cc;
          int s1 = find_set(test);
          int s2 = find_set(key);
          if (s1 == s2) {
            if (dsu_size[s1] < 26) {
              test++;
              continue;
            } else {
              // can form a cycle here;
              out[key] = true;
              in[test] = true;
              mp[key] = test + 'a';
              union_set(key, test);
              break;
            }
          } else {
            // can link key -- test;
            out[key] = true;
            in[test] = true;
            mp[key] = test + 'a';
            union_set(key, test);
            break;
          }

          continue;
        }

        if (test == key) test++;

        out[key] = true;
        in[test] = true;
        mp[key] = test + 'a';
        union_set(key, test);
        break;
      }
    }
    res[i] = mp[c - 'a'];
  }

  string res_str(res.begin(), res.end());
  cout << res_str << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}