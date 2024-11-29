#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int pre[60], obj[60], post[60];


void insert(int top, int tmp) {
	if (obj[top] > obj[tmp]) {
		if (pre[top] == top) pre[top] = tmp;
		else insert(pre[top], tmp);		
	}
	else {
		if (post[top] == top) post[top] = tmp;
		else insert(post[top], tmp);
	}

}


void output(int i) {
	if (pre[i] != i) output(pre[i]);
	cout << i << "...." << obj[i] << endl;
	if (post[i] != i) output(post[i]);
}	
	
	/*
	if (pre[i] == i) { cout << i << "...."<< obj[i] << endl; }
	else {
		output(pre[i]);
	}
	if (post[i] == i) { cout << i << "...." << obj[i] << endl; }
	else {
		output(post[i]);
	}*/ // pre[i]�� post[i] ��� i�� ��� �� �� �ߺ��Ǿ� ��� ��. (Binary tree ���ϴܺ�) ����, 





int main() {
	string line;
	int count = 0;

	ifstream file("sorttest1.txt"); // example.txt ������ ����. ������ ����. 
	if (file.is_open()) {
		while (getline(file, line)) {
			obj[count++] = stoi(line); // line�� string�̱� ������ int�� �ٲ� �ʿ�
			
		}
		file.close(); // ������ ������ �ݴ´�. 
	}
	else {
		cout << "Unable to open file";
		return 1;
	}
	for (int i = 0; i < count; i++) {
		pre[i] = i;
		post[i] = i;
	}

	for (int i = 1; i < count; i++) {
		insert(0, i);

	}

	output(0);

	

	return 0;
}