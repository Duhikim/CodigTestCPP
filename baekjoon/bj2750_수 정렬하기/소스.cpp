#include <iostream>
using namespace std;

// N���� ���ڰ� �־����� ��, �̸� ������ ������ ����.
// ù° �ٿ� ���� ���� N(1 �� N �� 1,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���� �־�����. �� ���� ������ 1,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.
// ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.

int main() {
	int N;
	cin >> N;
	int* pArray;
	pArray = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> pArray[i];
	}

	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (pArray[j] < pArray[i]) {
				temp = pArray[i];
				pArray[i] = pArray[j];
				pArray[j] = temp;
			}
		}		
	}
	for (int i = 0; i < N; i++) {
		cout << pArray[i] << '\n';
	}
	return 0;
}