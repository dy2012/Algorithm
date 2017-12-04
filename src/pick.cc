// Yougth和Hrdv玩一个游戏，拿出n个石子摆成一圈，Yougth和Hrdv分别从其中取石子，谁先取完者胜，每次可以从中取一个或者相邻两个，Hrdv先取，输出胜利者的名字
// 输入：
// 输入包括多组测试数据
// 每组测试数据一个n，数据保证int范围内
//
// 输出：
// 输出胜利者的名字

#include <iostream>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
      if (n > 2) {
        cout << "Hrdv" << endl;
      } else {
        cout << "Yougth" << endl;
      }
  }
  return 0;
}
