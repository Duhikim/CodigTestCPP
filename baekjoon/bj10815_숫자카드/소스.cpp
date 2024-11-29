/*
����
���� ī��� ���� �ϳ��� ������ �ִ� ī���̴�. ����̴� ���� ī�� N���� ������ �ִ�. 
���� M���� �־����� ��, �� ���� �����ִ� ���� ī�带 ����̰� ������ �ִ��� �ƴ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ����̰� ������ �ִ� ���� ī���� ���� N(1 �� N �� 500,000)�� �־�����. ��° �ٿ��� ���� ī�忡 �����ִ� ������ �־�����. 
���� ī�忡 �����ִ� ���� -10,000,000���� ũ�ų� ����, 10,000,000���� �۰ų� ����. �� ���� ī�忡 ���� ���� �����ִ� ���� ����.

��° �ٿ��� M(1 �� M �� 500,000)�� �־�����. ��° �ٿ��� ����̰� ������ �ִ� ���� ī������ �ƴ����� ���ؾ� �� M���� ������ �־�����, 
�� ���� �������� ���еǾ��� �ִ�. �� ���� -10,000,000���� ũ�ų� ����, 10,000,000���� �۰ų� ����

���
ù° �ٿ� �Է����� �־��� M���� ���� ���ؼ�, �� ���� ���� ���� ī�带 ����̰� ������ ������ 1��, �ƴϸ� 0�� �������� ������ ����Ѵ�.
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool debug = //true;
			false;
int N, M;
int* mycard;

bool find_card(int num, int start, int size) {
	if (size == 1) {
		if (num == mycard[start]) return 1; return 0;
	}
	if (size == 2) {
		if (num == mycard[start] || num == mycard[start+1]) return 1; return 0;
	}
	// ((if size > 2))
	if (num == mycard[start + size / 2]) return 1;
	if (num < mycard[start + size / 2]) {
		return find_card(num, start, size / 2);
	}
	if (num > mycard[start + size / 2]) {
		return find_card(num, start + size / 2, size - size / 2);
	}
	return 0;
}

int main() {
	cin >> N;
	mycard = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> mycard[i];
	}

	sort(mycard, mycard+N);
	if (debug) { for (int i = 0; i < N; i++) { cout << mycard[i] << " "; } cout << '\n'; }
	

	cin >> M;
	
	for (int i = 0; i < M; i++) {
		int givennum;
		cin >> givennum;
		bool is_it = find_card(givennum, 0, N);
		cout << is_it << " ";
	}
	cout << '\n';

	delete[] mycard;
	
	return 0;
}

