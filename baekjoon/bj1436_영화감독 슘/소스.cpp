#include <iostream>
#include <string>
using namespace std;

bool debug = //true;
			false;


//���ڸ� �Է¹޾� 666�� �ִ��� ã�� �Լ� (666�� ���ԵǾ� ������ �μ��� ����, �ƴϸ� 0�� ����)
int search(int num) { 
	int temp = num;
	while (temp) {
		if (temp % 10 == 6) {
			temp /= 10;
			if (temp % 10 == 6) {
				temp /= 10;
				if (temp % 10 == 6) { return num; }
				else temp /= 10;
			}
			else temp /= 10;
		}
		else temp /= 10;
	}
	return 0;
}


int main() {
	do {
		int N;
		cin >> N;
		int array[10000] = { 0, };
		int count = 0;

		for (int i = 666; count < N; i++) {
			int evil_num = search(i);
			if (evil_num) { //������ ���̸�
				count++;
				for (int j = 0; j < 10000; j++) {
					if (!array[j]) {
						array[j] = evil_num;//��� ��ĭ�� �߰�
						break;
					}
				}
			}
		}
		if (debug) {
			for (int i = 0; i < N; i++) { cout << array[i] << '\n'; }
		}
		if (!debug) cout << array[N - 1] << '\n';
	} while (debug);

	return 0;
}