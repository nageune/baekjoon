// 1427: 소트인사이드
//
// - 문제
// 배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.
//
// - 입력
// 첫째 줄에 정렬하려고 하는 수 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.
//
// - 출력
// 첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  cin >> a;
  sort(a.begin(), a.end(), greater<>());
  cout << a << '\n';
  return 0;
}