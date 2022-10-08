// 4446: ROT13
//
// - 문제
// 간달프는 여러 종족의 언어를 꽤 오랜 시간 동안 공부했다. 최근에 간달프는 해커들이 사용하는 언어인 ROT13을 공부했다. 이 언어는 영어와 문법이 같지만, 알파벳의 순서를 어떤 규칙을 이용해서 바꾸는 것이다.
// 모음은 총 6개가 있다.
// (a i y e o u)
// 모음은 각 위치에서 세 번째 오른쪽 위치에 있는 모음으로 바꾼다. 위의 수열은 사이클이라서 마지막과 첫 위치는 서로 붙어있는 것이다. 이때, 대소문자는 유지해야 한다.
// 자음도 모음과 비슷하게 바꾸면 된다.
// (b k x z n h d c w g p v j q t s r l m f)
// 자음은 각 위치에서 열번 위치에 있는 자음으로 바꾼다.
// 다음과 같은 문장 "One ring to rule them all." ROT13을 이용하면 "Ita dotf ni dyca nsaw ecc."으로 바꿀 수 있다.
// ROT13으로 쓴 문장이 주어졌을 때, 원래 영어로 쓴 문장으로 바꾸는 프로그램을 작성하시오.
//
// - 입력
// 입력은 여러 줄로 이루어져 있다. 각 줄은 100글자 이내의 문장이고, ROT13으로 쓰여진 문장이다. 이 문장의 각 글자는 ASCII 문자 공백(32) 부터 ~(126)까지이다.
//
// - 출력
// 각 줄에 대해서 ROT13을 영어로 바꾼 문장을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  string a1 = "aiyeou", a2 = "AIYEOU", b1 = "bkxznhdcwgpvjqtsrlmf", b2 = "BKXZNHDCWGPVJQTSRLMF";
  while (getline(cin, str)) {
    string ans = "";
    for (char elem : str) {
      if (a1.find(elem) != string::npos) {
        int index = a1.find(elem) + 3;
        if (index >= 6)
          index -= 6;
        ans += a1[index];
      } else if (a2.find(elem) != string::npos) {
        int index = a2.find(elem) + 3;
        if (index >= 6)
          index -= 6;
        ans += a2[index];
      } else if (b1.find(elem) != string::npos) {
        int index = b1.find(elem) + 10;
        if (index >= 20)
          index -= 20;
        ans += b1[index];
      } else if (b2.find(elem) != string::npos) {
        int index = b2.find(elem) + 10;
        if (index >= 20)
          index -= 20;
        ans += b2[index];
      } else {
        ans += elem;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}