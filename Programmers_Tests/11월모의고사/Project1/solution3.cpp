//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//bool getPop(int UnitSize, int si, int sj, vector<vector<int>>& popByUnit, int thresHold);
//int main() {
//	/**********************
//	ù° �� �������� ũ�� N�� ���� S �Է�
//	���� N���� �ٿ� N���� ������ A[i][1], A[i][2], ... A[i][N] �Է�
//	i��° �ٿ��� j��°�� �־����� ���� i�� j���� �ش��ϴ� ĭ�� �����ϴ� �α� ��.
//	3 <= N <= 1000
//	0 <= S <= 10^9
//	0 <= A[i][j] <= 100
//	��� ���� ����
//	���� �� �ִ� K�� �ּڰ��� ����Ѵ�. ���� ��ü �α������� S�� ũ�ٸ� -1�� ���.
//	**********************/
//	int N, S;
//	cin >> N >> S;
//	int population = 0;
//	int min = S+1;
//	vector<vector<int>> popByUnit;
//	for (int i = 0; i < N; i++) {
//		vector<int> temp(N);
//		for (int j = 0; j < N; j++) {
//			cin >> temp[j];
//			population += temp[j];
//			if (temp[j] < min) min = temp[j];
//		}
//		popByUnit.push_back(temp);
//	}
//	if (S > population) {
//		cout << -1 << '\n';
//		return 0;
//	}
//	if (S <= min) {
//		cout << 1 << '\n';
//		return 0;
//	}
//	bool Success = false;
//	for (int Unit = 1; Unit <= N; Unit++) { // ��ȹ ũ�⸦ 1���� N���� �÷�����.
//		for (int i = 0; i <= N - Unit; i++) {
//			for (int j = 0; j <= N - Unit; j++) {
//				Success = getPop(Unit, i, j, popByUnit, S);
//				if (!Success) break;
//			}
//			if (!Success) break;
//		}
//		if (Success) {
//			cout << Unit << '\n';
//			return 0;
//		}
//	}
//
//	cout << "Bug Check" << '\n';
//	return 0;
//}
//
//bool getPop(int UnitSize, int si, int sj, vector<vector<int>>& popByUnit, int thresHold) {
//	int N = popByUnit.size();
//	int Pop = 0;
//	for (int i = si; i < si+UnitSize; i++) {
//		for (int j = sj; j < sj+UnitSize; j++) {
//			Pop += popByUnit[i][j];
//			if (Pop >= thresHold) return true;
//		}
//	}
//	return false;
//}