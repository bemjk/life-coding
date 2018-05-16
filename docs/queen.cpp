#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int n, r, queen[20]; //�� ũ��, �ַ�ǰ���, �� ��ġ

void chk(int x, int y) //�ش� ��ǥ���� Ž��.
{
	for (int i = 1; i < x; i++)	 //�밢����ǥ�� ����[��Ʈ��]?
		if (y == queen[i] || abs(queen[i] - y) == abs(x - i))
			return;		
	if (x == n) {			 // ������ ���� ���� �ϸ� 
		if (r < 3) {
			for (int i = 1; i <= n; i++)	// queen�� ��ǥ�� ��� �Ͽ� ����
				cout << queen[i] << " ";
			cout << endl;
		}
		
		r++;							//3�� ���  
		return;
	}
	for (int i = 1; i <= n; i++) {
		queen[x + 1] = i;          // �ش� ���� ���� ��ǥ�� �޾ƿ´�. 
		chk(x + 1, i);			//���� chk �����Ͽ� �״��� �ڸ� ����.
	}
}

int main() {  
	cin >> n;  // ü���� ũ�� �Է�
	for (int i = 1; i <= n; i++) { //ù�� ���ڸ��� Ȯ��.
		queen[1] = i;
		chk(1, i);
	}
	cout << r << endl;
	return 0;
}