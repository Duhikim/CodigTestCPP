#include <iostream>
#include <istream>
#include <string>
using namespace std;

int main() {
	char alphabet[5][20] = { 0 };
	//int size[5];
	
	for (int i = 0; i < 5; i++) {cin >> alphabet[i];} // �Է�

	
	//������ ����
	/*
	for (int i = 0; i < 5; i++) {
		int temp = 0;
		for (int j = 0; alphabet[i][j] != '\0'; j++) {
			temp++;
		} size[i] = temp;
	}*/
	
	//������ �������� ���
	/*
	for (int j = 0; j < 20; j++) {
		for (int i = 0; i < 5; i++) {
			if(j< size[i]) cout << alphabet[i][j];
		}
	} */

	//�׳� ���
	for (int j = 0; j < 20; j++) {
		for (int i = 0; i < 5; i++) {
			if (alphabet[i][j]) cout << alphabet[i][j];
		}
	}
	
	

	return 0;
}