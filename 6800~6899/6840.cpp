// 6840: Who is in the middle?
//
// - 문제
// In the story Goldilocks and the Three Bears, each bear had a bowl of porridge to eat while sitting at his/her favourite chair. What the story didn’t tell us is that Goldilocks moved the bowls around on the table, so the bowls were not at the right seats anymore. The bowls can be sorted by weight with the lightest bowl being the Baby Bear’s bowl, the medium bowl being the Mama Bear’s bowl and the heaviest bowl being the Papa Bear’s bowl. Write a program that reads in three weights and prints out the weight of Mama Bear’s bowl. You may assume all weights are positive integers less than 100.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  cout << a[1];
  return 0;
}