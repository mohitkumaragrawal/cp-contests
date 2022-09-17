// #include <bits/stdc++.h>
// using namespace std;

// int find_seconds(int k, int m) {
//   k *= 2;

//   int low = 0;
//   int high = 10000;

//   int ans = high;
//   while (high >= low) {
//     int mid = (low + high) / 2;

//     int val = m * mid * (mid + 1);
//     if (val >= k) {
//       ans = mid;
//       high = mid - 1;
//     } else {
//       low = mid + 1;
//     }
//   }
//   return ans;
// }

// void dfs(int node, vector<vector<int>>& G, vector<int>& parent,
//          vector<bool>& visited) {
//   //
//   if (visited[node]) return;
//   visited[node] = true;

//   for (int child : G[node]) {
//     if (visited[child]) continue;

//     parent[child] = node;
//     dfs(child, G, parent, visited);
//   }
// }

// void populate_fq(int node, vector<int>& parent, vector<int>& en,
//                  vector<map<int, int>>& fq) {
//   //
//   if (node == -1) return;
//   if (!fq[node].empty()) return;

//   populate_fq(parent[node], parent, en, fq);

//   if (parent[node] != -1) {
//     fq[node] = fq[parent[node]];
//   }
//   if (en[node] > 0) {
//     fq[node][en[node]]++;
//   }
// }

// struct Query {
//   int X, T, K;
// };

// int main() {
//   int N;
//   cin >> N;

//   vector<int> en(N + 1, 0);
//   vector<int> ens;
//   for (int i = 1; i <= N; ++i) {
//     int el;
//     cin >> el;
//     if (el == 1) {
//       en[i] = 1;
//       ens.push_back(i);
//     }
//   }

//   vector<vector<int>> G(N + 1);
//   for (int i = 1; i < N; ++i) {
//     int u, v;
//     cin >> u >> v;
//     G[u].push_back(v);
//     G[v].push_back(u);
//   }

//   for (int en_nd : ens) {
//     for (int child : G[en_nd]) {
//       en[child]++;
//     }
//   }

//   vector<bool> visited(N + 1, false);
//   vector<int> parent(N + 1, -1);
//   dfs(1, G, parent, visited);

//   int Q;
//   cin >> Q;

//   vector<Query> q;

//   while (Q--) {
//     int X, T, K;
//     cin >> X >> T >> K;

//     q.push_back({X, T, K});

//     // vector<int> z;
//     // int nd = X;
//     // while (nd != -1) {
//     //   if (en[nd] > 0) {
//     //     z.push_back(en[nd]);
//     //   }
//     //   nd = parent[nd];
//     // }

//     // if (z.size() < T) {
//     //   cout << -1 << endl;
//     //   continue;
//     // }

//     // sort(z.begin(), z.end());
//     // int m = z[z.size() - T];
//     // cout << find_seconds(K, m) << endl;
//   }

//   vector<map<int, int, greater<int>>> fq(N + 1);

//   for (auto qr : q) {
//     populate_fq(qr.X, parent, en, fq);
//   }

//   for (auto qr : q) {
//   }
// }