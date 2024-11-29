#include <iostream>
using namespace std;

/*
����
�迭�� �����ϴ� ���� ����. ���� �־�����, �� ���� �� �ڸ����� ������������ �����غ���.
�Է�
ù° �ٿ� �����Ϸ��� �ϴ� �� N�� �־�����. N�� 1,000,000,000���� �۰ų� ���� �ڿ����̴�.
���
ù° �ٿ� �ڸ����� ������������ ������ ���� ����Ѵ�.
*/


int N;
int numbers[10];
int Size;

int make_number_array(int n) {
	int size = 0;
	for (int i = 0; n > 0; i++) {
		numbers[i] = n % 10; n /= 10; size++;
	}
	return size;
}

void sorting(int* array, int size) {
	int temp;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (array[i] < array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

int main() {
	cin >> N;
	Size = make_number_array(N);
	sorting(numbers, Size);
	for (int i = 0; i < Size; i++) {
		cout << numbers[i];
	}
	cout << '\n';
	return 0;
}