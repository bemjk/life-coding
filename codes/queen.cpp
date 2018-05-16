#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int n, r, queen[20]; //판 크기, 솔루션갯수, 퀸 위치

void chk(int x, int y) //해당 좌표에서 탐색.
{
	for (int i = 1; i < x; i++)	 //대각선좌표면 리턴[백트랙]?
		if (y == queen[i] || abs(queen[i] - y) == abs(x - i))
			return;		
	if (x == n) {			 // 마지막 열에 도달 하면 
		if (r < 3) {
			for (int i = 1; i <= n; i++)	// queen의 좌표들 출력 하여 리턴
				cout << queen[i] << " ";
			cout << endl;
		}
		
		r++;							//3개 출력  
		return;
	}
	for (int i = 1; i <= n; i++) {
		queen[x + 1] = i;          // 해당 열의 행의 좌표를 받아온다. 
		chk(x + 1, i);			//다음 chk 수행하여 그다음 자리 구함.
	}
}

int main() {  
	cin >> n;  // 체스판 크기 입력
	for (int i = 1; i <= n; i++) { //첫열 한자리씩 확인.
		queen[1] = i;
		chk(1, i);
	}
	cout << r << endl;
	return 0;
}