#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int array_size = 60;
//�ִ밪 ���ϱ�
int maximum(int array[]) {
	int max = array[0];
	for (int i = 1; i < array_size; i++) {
		max = (array[i] > max) ? array[i] : max;
	}
	return max;
}
//�ּҰ� ���ϱ�
int minimum(int array[]) {
	int min = array[0];
	for (int i = 1; i < array_size; i++) {
		min = (array[i] > min) ? array[i] : min;
	}
	return min;
}

//������
void dividing(int n, int array[], int max, int min, int count) {
	
	
	if (max==min)
	if (n <= (max + min) / 2) { dividing(n, array, (max + min) / 2, min); }
	else { dividing(n, array, max, max - (max + min) / 2); }
}


int main() {
	string line;
	int numbers[array_size];
	int count = 0;

	ifstream file("sorttest1.txt"); // example.txt ������ ����. ������ ����. 
	if (file.is_open()) {
		while (getline(file, line)) {
			numbers[count++] = stoi(line); // line�� string�̱� ������ int�� �ٲ� �ʿ�

		}
		file.close(); // ������ ������ �ݴ´�. 
	}
	else {
		cout << "Unable to open file";
		return 1;
	}
	int* pIndex;
	pIndex = new int[count];
	for (int i = 0; i < count; i++) { pIndex[i] = i; }


	int* pSorted;
	pSorted = new int[count];


	int max = maximum(numbers);
	int min = minimum(numbers);
	



	delete[] pSorted;
	return 0;
}