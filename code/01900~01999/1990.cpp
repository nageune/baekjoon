// 1990: 소수인팰린드롬
//
// - 문제
// 151은 소수이면서 동시에 팰린드롬이기 때문에 소수인 팰린드롬이다. 팰린드롬이란 앞으로 읽어나 뒤로 읽으나 같은 수를 말한다. 예를 들어 1234는 앞으로 읽으면 1234지만, 뒤로 읽으면 4321이 되고 이 두 수가 다르기 때문에 팰린드롬이 아니다. 두 정수 a, b가 주어졌을 때, a이상 b이하인 소수인 팰린드롬을 모두 구하는 프로그램을 작성하시오.
//
// - 입력
// 입력은 첫째 줄에 공백으로 구분된 두 자연수 a, b가 주어진다. 단 5 ≤ a < b ≤ 100,000,000 이다.
//
// - 출력
// 첫째 줄부터 차례로 증가하는 순서대로 한 줄에 한개씩 소수인 팰린드롬을 출력한다. 마지막 줄에는 -1을 출력한다.

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i))
      return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  vector<int> palindrome;
  for (int i = 1; i <= 10000; i++) {
    string s = to_string(i);
    string num = s;
    for (int j = s.size() - 2; j >= 0; j--)
      num += s[j];
    palindrome.push_back(stoi(num));
    num = s;
    for (int j = s.size() - 1; j >= 0; j--)
      num += s[j];
    palindrome.push_back(stoi(num));
  }
  sort(palindrome.begin(), palindrome.end());
  int a, b;
  cin >> a >> b;
  for (int i : palindrome)
    if (i >= a && i <= b && isPrime(i))
      cout << i << '\n';
  cout << -1;
  return 0;
}