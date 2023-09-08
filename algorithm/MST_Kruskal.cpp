#include <bits/stdc++.h>
using namespace std;

int V, E, ans = 0;
vector<pair<int, pair<int, int>>> edge;
vector<int> p;

int find(int x) {
  if (p[x] != x)
    p[x] = find(p[x]);
  return p[x];
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x < y)
    p[y] = x;
  else
    p[x] = y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> V >> E;
  p.resize(V + 1);
  iota(p.begin(), p.end(), 0);
  while (E--) {
    int u, v, w;
    cin >> u >> v >> w;
    edge.push_back({w, {u, v}});
  }
  sort(edge.begin(), edge.end());
  for (auto [weight, path] : edge)
    if (find(path.first) != find(path.second)) {
      ans += weight;
      merge(path.first, path.second);
    }
  cout << ans;
  return 0;
}
// O(ElogE)