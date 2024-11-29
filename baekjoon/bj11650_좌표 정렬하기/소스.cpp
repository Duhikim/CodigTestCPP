#include <iostream>
using namespace std;
bool debug = //true;
			false;

/*
����
2���� ��� ���� �� N���� �־�����. ��ǥ�� x��ǥ�� �����ϴ� ������, x��ǥ�� ������ y��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է�
ù° �ٿ� ���� ���� N (1 �� N �� 100,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� i������ ��ġ xi�� yi�� �־�����. (-100,000 �� xi, yi �� 100,000) ��ǥ�� �׻� �����̰�, ��ġ�� ���� �� ���� ����.
���
ù° �ٺ��� N���� �ٿ� ���� ������ ����� ����Ѵ�
���� �Է�
5
3 4
1 1
1 -1
2 2
3 3
���� ���
1 -1
1 1
2 2
3 3
3 4
*/

struct coord {
	int index;
	int xcoord;
	int ycoord;
	int pre;
	int post;
};
int N;
coord* Coord;

int merge(int fst, int scd) {
	if ((Coord[fst].post == Coord[fst].index) && (Coord[scd].post == Coord[scd].index)) {
		if ((Coord[fst].xcoord > Coord[scd].xcoord) || ((Coord[fst].xcoord == Coord[scd].xcoord) && (Coord[fst].ycoord > Coord[scd].ycoord))) { Coord[scd].post = Coord[fst].index; 	return scd; }
		else { Coord[fst].post = Coord[scd].index; return fst; }
	}

	if (Coord[fst].post == Coord[fst].index) {
		if ((Coord[fst].xcoord < Coord[scd].xcoord) || ((Coord[fst].xcoord == Coord[scd].xcoord) && (Coord[fst].ycoord <= Coord[scd].ycoord))) { Coord[fst].post = Coord[scd].index; return fst; }
		else { Coord[scd].post = merge(fst, Coord[scd].post); return scd; }
	}

	if (Coord[scd].post == Coord[scd].index) {
		if ((Coord[fst].xcoord > Coord[scd].xcoord) || ((Coord[fst].xcoord == Coord[scd].xcoord) && (Coord[fst].ycoord > Coord[scd].ycoord))) { Coord[scd].post = Coord[fst].index; return scd; }
		else { Coord[fst].post = merge(Coord[fst].post, scd); return fst; }
	}

	if ((Coord[fst].xcoord < Coord[scd].xcoord) || ((Coord[fst].xcoord == Coord[scd].xcoord) && (Coord[fst].ycoord < Coord[scd].ycoord))) { Coord[fst].post = merge(Coord[fst].post, scd); return fst; }
	else { Coord[scd].post = merge(fst, Coord[scd].post); return scd; }


}

int slapchop(coord top, int size) {
	if (size == 1) return top.index;
	if (size == 2) {
		if ((top.xcoord > Coord[top.index + 1].xcoord)||((top.xcoord==Coord[top.index+1].xcoord) && (top.ycoord > Coord[top.index + 1].ycoord))) {
			Coord[top.index + 1].post = top.index; 
			if (debug) { cout << "index: " << top.index + 1 << "  xcoord: " << Coord[top.index+1].xcoord << "  ycoord: " << Coord[top.index + 1].ycoord << "   next index: " << Coord[top.index + 1].post << '\n'; }
			return (top.index + 1);
		}
		else {
			Coord[top.index].post = Coord[top.index+1].index; 
			if (debug) { cout << "index: " << top.index << "  xcoord: " << top.xcoord << "  ycoord: " << top.ycoord << "   next index: " << top.post << '\n'; }
			return (top.index);
		}
	}
	if (size > 2) {
		int first = slapchop(top, size / 2);
		int second = slapchop(Coord[top.index+(size / 2)], size - size / 2);
		return merge(first, second);
	}
}


int main() {
	
	cin >> N;
	Coord = new coord[N];
	
	for (int i = 0; i < N; i++) {
		cin >> Coord[i].xcoord >> Coord[i].ycoord;
		Coord[i].index = i;
		Coord[i].pre = i;
		Coord[i].post = i;
	}
	
	int smallest_index = slapchop(Coord[0], N);

	if (debug) {
		cout << "(�����)" << '\n' << "index / xcoord / ycoord / pre / post\n";
		for (int i = 0; i < N; i++) {
			cout << Coord[i].index << "     /   " << Coord[i].xcoord << "   /   " << Coord[i].ycoord << "     /  " << Coord[i].pre << " /   " << Coord[i].post << '\n';
		}
		cout << "(����� ��)" << '\n';

	}

	while (1) {
		cout << Coord[smallest_index].xcoord << " " << Coord[smallest_index].ycoord << '\n';
		if (smallest_index == Coord[smallest_index].post) break;
		smallest_index = Coord[smallest_index].post;
	}
	

	delete[] Coord;
	return 0;
}