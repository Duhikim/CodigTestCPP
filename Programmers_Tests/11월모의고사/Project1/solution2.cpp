//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//void Search(int Start, int Target, int currentDataSize, vector<vector<int>>& cables, vector<bool>& visited, int& min);
//
//int main() {
//	/*************
//	ù° �ٿ� ���ž �� N�� ���̺� �� M �Է�.
//	��° �ٿ� ������ ���� �����ϴ� ���ž�� ��ȣ S, �����͸� �޴� ���ž�� ��ȣ E �Է�.
//	���� M���� �ٿ� ai, bi, ki�� ������ �ΰ� �־���. 
//		ai�� bi�� �����ϴ� ���̺��� ������ ���� �Ѱ谡 ki��� �ǹ�
//	2<= N <= 200 000
//	1 <= M <= 300 000
//	1 <= S,E <= N; S!=E
//	1 <= ai, bi <= N; ai != bi
//	1 <= k1 <= 200 000
//	�Է°��� ��� ����.
//
//	S���� E�� ũ�� 1¥�� �����͸� ���� �� ���� �������� �ּ� ũ�⸦ ���. �Ұ��� �Ѱ�� -1 ���.
//	***************/
//
//	int N, M, S, E;
//	cin >> N >> M >> S >> E;
//	
//	vector<vector<int>> cables;
//	for (int i = 0; i < M; i++) {
//		vector<int> temp(3);
//		cin >> temp[0] >> temp[1] >> temp[2];
//		cables.push_back(temp);
//	}
//	vector<bool> visited(N+1, false);
//	int min = -1;
//	Search(S, E, 1, cables, visited, min);
//	cout << min << '\n';
//
//	return 0;
//}
//
//void Search(int Start, int Target, int currentDataSize, vector<vector<int>>& cables, vector<bool>& visited, int& min) {
//	if (Start == Target) {
//		if (min == -1 || currentDataSize < min)
//			min = currentDataSize;
//		return;
//	}
//	for (int i = 0; i < cables.size(); i++) {
//		// ���� ���� ������ ����� ���̺� �뷮���� �۰ų� ���ƾ� ��.
//		if (currentDataSize <= cables[i][2]) {
//			if (cables[i][0] == Start
//				&& visited[cables[i][1]] == false) {
//				visited[cables[i][1]] = true;
//				Search(cables[i][1], Target, currentDataSize + 1, cables, visited, min);
//				visited[cables[i][1]] = false;
//			}
//			else if (cables[i][1] == Start
//				&& visited[cables[i][0]] == false) {
//				visited[cables[i][0]] = true;
//				Search(cables[i][0], Target, currentDataSize + 1, cables, visited, min);
//				visited[cables[i][0]] = false;
//			}
//		}
//		else continue;
//	}
//}