#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

// 돌 시뮬레이터:
// 총 세 개의 뽑기 판이 있다. 두 개는 뽑을수록 이득이며 나머지 하나는 뽑을 수록 마이너스.
// 따라서 두 개의 뽑기는 성공(1)하면 확률이 10씩 떨어지고 나머지 뽑기는 성공하면 확률이 올라간다.
class Dol {
  int dol[3][10];
  int prob, i, j, k;
  public:
  Dol();
  int PDol();
  void getProb(int tmp, int q);
  void choice(int tmp);
  void printDol(int m, int q);
};

// 생성자
Dol::Dol() {
  prob = 75;
  i=0;
  j=0;
  k=0;
}
// 확률에 따라 성공과 실패를 결정
int Dol::PDol() {
  if(rand()%100 < prob) return 1;
  else return 0;
}

//성패에 따라 확률을 변동
void Dol::getProb(int tmp, int q) {
  int a = 10;
  if(dol[tmp][q] == 1) { 
    if(prob != 5) {
      prob = prob - a;
    }
  }
  else {
    if(prob != 95) {
      prob = prob + a;
    }
  }
}

// 선택 함수
void Dol::choice(int tmp){
  if(tmp == 0){
    dol[tmp][i] = PDol();
    printDol(tmp, i);
    i++;
  }
  else if(tmp == 1){
    dol[tmp][j] = PDol();
    printDol(tmp, j);
    j++;
  }
  else{
    dol[tmp][k] = PDol();
    printDol(tmp, k);
    k++;
  }
}

//돌 상태 출력
void Dol::printDol(int m, int q){
  cout << "현재 돌 상태는 " << "\n";
  for(int n=0; n <= q; n++) {
    cout << dol[m][n] << " ";
  }
  cout << "\n";
  getProb(m, q);
  cout << "현재 확률은 " << prob << endl;
  cout << m <<" 남은 기회: " << 9 - q << endl;
}

int main() {
  int tmp;
  // 확률
  srand(time(0));
  // 돌: 3X10 배열
  class Dol D;
  Dol();

  // 뽑기 선택
  for(int n = 0; n < 30; n++) {
    cout << "원하는 곳을 선택하세요.(0~2)";
    cin >> tmp;
    D.choice(tmp);
  }

  //cout << "돌이 다음과 같이 나옴" << endl;
  
}
