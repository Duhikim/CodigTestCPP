#include <iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	int counter = 0;

	for (int i = 0; i * 3 <= N; i++) {
		for (int j = 0; (i * 3 + j * 5) <= N; j++) {
			if (i * 3 + j * 5 == N) {
				//if (debug) { cout << "i : " << i << '\n' << "j : " << j << '\n' << "i * 3 + j * 5 = " << i * 3 + j * 5 << '\n'; }
				cout << i + j << '\n'; return 0;
			}

		}
	} cout << -1 << '\n';

	return 0;
}

// �������� 3kg¥���� 5kg¥���� ����.
// N ų�α׷��� ����� �� �ִ��� ���� ������ ���.