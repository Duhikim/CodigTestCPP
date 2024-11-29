#include <iostream>
using namespace std;
/*
����
�¶��� ������ ������ ������� ���̿� �̸��� ������ ������� �־�����. 
�̶�, ȸ������ ���̰� �����ϴ� ������, ���̰� ������ ���� ������ ����� �տ� ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �¶��� ���� ȸ���� �� N�� �־�����. (1 �� N �� 100,000)
��° �ٺ��� N���� �ٿ��� �� ȸ���� ���̿� �̸��� �������� ���еǾ� �־�����. 
���̴� 1���� ũ�ų� ������, 200���� �۰ų� ���� �����̰�, �̸��� ���ĺ� ��ҹ��ڷ� �̷���� �ְ�, ���̰� 100���� �۰ų� ���� ���ڿ��̴�.
�Է��� ������ ������ �־�����.

���
ù° �ٺ��� �� N���� �ٿ� ���� �¶��� ���� ȸ���� ���� ��, ���̰� ������ ������ ������ �� �ٿ� �� �� ���̿� �̸��� �������� ������ ����Ѵ�.
*/


int N;
struct members_data {
	int age;
	string name;
	};
members_data* member;

int main() {
	cin >> N;
	member = new members_data[N];
	for (int i = 0; i < N; i++) {
		cin >> member[i].age >> member[i].name;
	}
	for (int n = 1; n <= 200; n++) {
		for (int i = 0; i < N; i++) {
			if (member[i].age == n) cout << member[i].age << " " << member[i].name << '\n';
		}
	}
	return 0;
}



/*

int N;
struct members_data {
	int index;
	int age;
	string name;
	int pointer;
};
members_data* member;
 

int merge(int index1, int index2) {
	if ((member[index1].pointer == index1) && (member[index2].pointer == index2)) {
		if ((member[index1].age < member[index2].age) || ((member[index1].age == member[index2].age) && (index1 < index2))) { member[index1].pointer = index2; return index1; }
		member[index2].pointer = index1; return index2;
	}
	if (member[index1].pointer == index1) {
		if ((member[index1].age < member[index2].age) || ((member[index1].age == member[index2].age) && (index1 < index2))) { member[index1].pointer = index2; return index1; }
		member[index2].pointer = merge(index1, member[index2].pointer); return index2;
	}
	if (member[index2].pointer == index2) {
		if ((member[index1].age > member[index2].age) || ((member[index1].age == member[index2].age) && (index1 > index2))) { member[index2].pointer = index1; return index2; }
		member[index1].pointer = merge(member[index1].pointer, index2);
	}

	if ((member[index1].age < member[index2].age) || ((member[index1].age == member[index2].age) && (index1 < index2))) {
		member[index1].pointer = merge(member[index1].pointer, index2); return index1;
	}
	member[index2].pointer = merge(index1, member[index2].pointer); return index2;
}

int dividing(int firstindex, int size) {
	if (size == 1) { return firstindex; }
	if (size == 2) {
		if (member[firstindex].age > member[firstindex + 1].age) { member[firstindex + 1].pointer = firstindex; return firstindex + 1; }
		else { member[firstindex].pointer = firstindex + 1; return firstindex; }	//���̰� ���� ��� firstindex�� �׻� firstindex+1���� ���� �´�.	
	}
	if (size > 2) {
		int one = dividing(firstindex, size / 2);
		int two = dividing(firstindex + size / 2, size - size / 2);
		return merge(one, two);
	}
}

int main() {
	cin >> N;
	member = new members_data[N];
	for (int i = 0; i < N; i++) {
		cin >> member[i].age >> member[i].name;
		member[i].index = i;
		member[i].pointer = i;
	}

	int smallest_member = dividing(0, N);

	while (1) {
		cout << member[smallest_member].age << " " << member[smallest_member].name << '\n';
		if (member[smallest_member].pointer == smallest_member) return 0;
		smallest_member = member[smallest_member].pointer;
	}

}
*/