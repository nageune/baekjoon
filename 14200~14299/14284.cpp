// 14284: 간선 이어가기 2
//
// - 문제
// 정점 n개, 0개의 간선으로 이루어진 무방향 그래프가 주어진다. 그리고 m개의 가중치 간선의 정보가 있는 간선리스트가 주어진다. 간선리스트에 있는 간선 하나씩 그래프에 추가해 나갈 것이다. 이때, 특정 정점 s와 t가 연결이 되는 시점에서 간선 추가를 멈출 것이다. 연결이란 두 정점이 간선을 통해 방문 가능한 것을 말한다.
// s와 t가 연결이 되는 시점의 간선의 가중치의 합이 최소가 되게 추가하는 간선의 순서를 조정할 때, 그 최솟값을 구하시오.
//
// - 입력
// 첫째 줄에 정점의 개수 n, 간선리스트의 간선 수 m이 주어진다.(2≤n≤5000,1≤m≤100,000)
// 다음 m줄에는 a,b,c가 주어지는데, 이는 a와 b는 c의 가중치를 가짐을 말한다. (1≤a,b≤n,1≤c≤100,a≠b)
// 다음 줄에는 두 정점 s,t가 주어진다. (1≤s,t≤n,s≠t)
// 모든 간선을 연결하면 그래프는 연결 그래프가 됨이 보장된다.
//
// - 출력
// s와 t가 연결되는 시점의 간선의 가중치 합의 최솟값을 출력하시오,

#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, s, t;
  cin >> n >> m;
  vector<pair<int, int>> graph[5001];
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  cin >> s >> t;
  vector<int> dist(5001, INF), visited(5001, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  dist[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    int curr;
    do {
      curr = pq.top().second;
      pq.pop();
    } while (!pq.empty() && visited[curr]);
    if (visited[curr])
      break;
    visited[curr] = 1;
    for (auto &p : graph[curr]) {
      int next = p.first, d = p.second;
      if (dist[next] > dist[curr] + d) {
        dist[next] = dist[curr] + d;
        pq.push({dist[next], next});
      }
    }
  }
  cout << dist[t] << '\n';
  return 0;
}