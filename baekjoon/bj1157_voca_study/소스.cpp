#include <iostream>
using namespace std;

int main() {
	
	string word;
	cin >> word;

	int size = word.size();
	//int* pWord;
	//pWord = new int[size];
	int alphabet[26] = { 0 };

	/* //��� ���� �빮�ڷ� ����
	for (int i = 0; i < size; i++) {
		if (word[i] <= 122 && word[i] >= 97) word[i] -= 32;
	}*/

	for (int i = 0; i < size; i++) {
		if (word[i] >= 'a') { alphabet[word[i] - 'a']++; }
		else { alphabet[word[i] - 'A']++; }
	}
		

	int max = alphabet[0];
	int index = 0;
	
	

	for (int i = 1; i < 26; i++) {
		if (alphabet[i] > max) { 
			max = alphabet[i]; 
			index = i; 
		}
		else if (alphabet[i] == max) {	
			index = -1; 
		}
	}
	char ans = (char)(index + 65);
	if (index == -1) cout << "?\n";
	else { cout << ans << '\n'; }

	//�ҹ����� �ƽ�Ű �ڵ�� 97(a)~122(z), �빮�ڴ� �ҹ��ڿ��� -32 �ϸ� 65(A)~90(Z)

	//delete[] pWord;
	return 0;
}