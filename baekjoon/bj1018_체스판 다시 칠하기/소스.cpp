#include <iostream>
using namespace std;

int main() {
	bool debug = //true;
				false;
	do {

		int N, M;
		char color[51][51] = { 0, };
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> color[i][j];
			}
		}

		if (debug) {
			cout << '\n' << "   "; for (int j = 0; j < M; j++) cout << j + 1 << " "; cout << '\n';
			for (int i = 0; i < N; i++) {
				if (i<9)cout <<"0"<< i + 1 << " ";
				else cout << i + 1 << " ";
				for (int j = 0; j < M; j++) {
					cout << color[i][j] << " ";
				} cout << '\n';
			} cout << '\n';
		}

		int minimum_count = -1;
		int minimum_count2 = -1;


		//N���� ��, M���� ��. 8 <= N,M <= 50
		//���� ������ 1�� 1���� ���� N-7�� M-7���� �����ϴ� �� ����.
		//���������� W�� �� ��, B�� �� ��. W����: ��x�� ���� Ȧ���� ��� W. B����: ��x�� ���� Ȧ���� ��� B.

		for (int i = 0; i < N - 7; i++) {
			for (int j = 0; j < M - 7; j++) { //�������� Ž��
				int count_temp = 0;
				for (int k = 0; k < 8; k++) { //������������ 8��
					for (int l = 0; l < 8; l++) { //������������ 8��
						if ((((i + k + 1) % 2) && ((j + l + 1) % 2)) || (!((i + k + 1) % 2) && (!((j + l + 1) % 2)))) { if (color[i + k][j + l] == 'B') count_temp++; } //Ȧ����, Ȧ����or ¦����, ¦������ ����, ������ W����, Ȧ���� B�� temp++
						if (((i + k + 1) % 2 && !((j + l + 1) % 2)) || !((i + k + 1) % 2) && (j + l + 1) % 2) { if (color[i + k][j + l] == 'W') count_temp++; } //Ȧ����, ¦����or ¦����, Ȧ������ ����, ������ W����, ¦���� W�� temp++
					}

				} if (minimum_count<0 || count_temp < minimum_count) minimum_count = count_temp;
				if (debug) cout << i + 1 << ", " << j + 1 << "���� �����Ͽ� ùĭ�� W�� �Ǿ�� �� ���� minimum_count �� " << minimum_count << '\n';

				count_temp = 0;
				for (int k = 0; k < 8; k++) { //������������ 8��
					for (int l = 0; l < 8; l++) { //������������ 8��
						if ((((i + k + 1) % 2) && ((j + l + 1) % 2)) || (!((i + k + 1) % 2) && (!((j + l + 1) % 2)))) { if (color[i + k][j + l] == 'W') count_temp++; } //Ȧ����, Ȧ����or ¦����, ¦������ ����, ������ B����, Ȧ���� W�� temp++
						if (((i + k + 1) % 2 && !((j + l + 1) % 2)) || (!((i + k + 1) % 2) && (j + l + 1) % 2)) { if (color[i + k][j + l] == 'B') count_temp++; } //Ȧ����, ¦����or ¦����, Ȧ������ ����, ������ B����, ¦���� B�� temp++
					}

				} if (minimum_count<0 || count_temp < minimum_count) minimum_count = count_temp;
				if (debug && minimum_count2<0 || count_temp < minimum_count2) minimum_count2 = count_temp;
				if (debug) cout << i + 1 << ", " << j + 1 << "���� �����Ͽ� ùĭ�� B�� �Ǿ�� �� ���� minimum_count2�� " << minimum_count2 << '\n';
			}
		}

		cout << minimum_count << '\n';

	} while (debug);

	return 0;

}