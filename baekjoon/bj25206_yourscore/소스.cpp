#include <iostream>
#include <cstring>
#include <string>
using namespace std;



int main() {
	string word;
	float scoretime[20];
	float n_subject = 0; //�����

	for (int q = 0; q < 20; q++) {
		getline(cin, word);
		int size = word.size();
		int index = 0;
		int time; //����
		float score; //����

		//����ã��
		for (int i = 0; i < size; i++) {
			if (word[i] == ' ') { index = (i + 1); break; }
		}

		
		//���� ��� �Է�
		if (word[index] == '1') time = 1;
		else if (word[index] == '2') time = 2;
		else if (word[index] == '3') time = 3;
		else if (word[index] == '4') time = 4;
		else time = 5;
		
		n_subject += time;

		index += 4;
		
		//���� �Է�
		if (word[index] == 'A') {
			if (word[index + 1] == '+') score = 4.5;
			else (score = 4.0);
		}
		else if (word[index] == 'B') {
			if (word[index + 1] == '+') score = 3.5;
			else (score = 3.0);
		}
		else if (word[index] == 'C') {
			if (word[index + 1] == '+') score = 2.5;
			else (score = 2.0);
		}
		else if (word[index] == 'D') {
			if (word[index + 1] == '+') score = 1.5;
			else (score = 1.0);
		}
		else if (word[index] == 'F') { score = 0; }
		else { score = 0; n_subject -= time; } //P�� ��� ��� ����

		scoretime[q] = score * (float)time;
	}

	//���� ��� �� ���
	float sum = 0; //����
	for (int q = 0; q < 20; q++) {
		sum += scoretime[q];
	}
	cout << (sum / n_subject) << '\n';

	return 0;

}