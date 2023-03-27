// 27920: 카드 뒤집기
//
// - 문제
// 1부터 N까지 서로 다른 정수가 적혀있는 카드를 N장 가지고 있다. 각 카드에는 앞면과 뒷면이 존재한다. 카드의 앞면에는 숫자가 적혀있고, 뒷면에는 카드의 무늬가 그려져 있다.
// N장의 카드를 원하는 순서대로 앞면이 보이도록 일렬로 배열한다. 이제 아래의 규칙에 따라 카드를 뒤집을 것이다.
// 맨 먼저 한 장의 카드를 골라 뒷면으로 뒤집는다.
// 가장 마지막으로 뒤집은 카드에 적힌 번호를 x라 하자.
// 마지막으로 뒤집은 카드에서 왼쪽으로 x장 떨어진 앞면 카드 또는 오른쪽으로 x장 떨어진 앞면 카드를 뒤집는다. 만약 해당하는 카드가 없으면 뒤집는 과정을 종료한다.
// 2번 단계가 종료될 때까지 뒤집는 과정을 반복한다.
// 카드의 장수 N이 주어질 때, 모든 카드를 뒤집을 수 있도록 배열할 수 있는지 알고 싶다. 따라서 모든 카드를 뒤집을 수 있는 배치가 존재하는지 여부를 출력하고, 그러한 배치가 존재한다면 카드를 배열하는 방법과 뒤집는 순서를 출력해야 한다.
//
// - 입력
// 첫 번째 줄에 카드의 장수 N이 주어진다. (1 ≤ N ≤ 200,000) 
//
// - 출력
// 첫 번째 줄에 모든 카드를 뒤집을 수 있도록 배열할 수 있는지를 출력해야 한다. 만약 가능하다면 YES, 불가능하다면 NO를 출력해야 한다.
// 만약 모든 카드를 뒤집을 수 있도록 배열할 수 있다면, 두 번째 줄에 카드의 배열 b_1, b_2, ..., b_n을 출력한다. b_i는 i번째 카드에 적혀있는 숫자를 의미한다.
// 이후 세 번째 줄에 카드를 뒤집는 순서 c_1, c_2, ..., c_n을 출력한다. c_i는 i번째로 뒤집을 카드의 위치를 의미한다.
// 만약 가능한 배열 방법 또는 뒤집는 순서가 여러 가지일 경우 가능한 하나만 출력하면 된다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  cout << "YES\n";
  if (n % 2) {
    for (int i = n - 1; i > 1; i -= 2)
      cout << i << ' ';
    cout << n << ' ';
    for (int i = 1; i < n; i += 2)
      cout << i << ' ';
    cout << '\n';
  } else {
    for (int i = n - 1; i > 0; i -= 2)
      cout << i << ' ';
    cout << n << ' ';
    for (int i = 2; i < n; i += 2)
      cout << i << ' ';
    cout << '\n';
  }
  int odd = 1, even = n;
  for (int i = 1; i <= n; i++) {
    if (i % 2) {
      cout << odd << ' ';
      odd++;
    } else {
      cout << even << ' ';
      even--;
    }
  }
  return 0;
}