#include <iostream>
using namespace std;




int main() {
	int testcase;
		cin >> testcase;
		
		int x1, y1, x2, y2; //�����, ������ ��ǥ


	for (int i = 0; i < testcase; i++) { //�׽�Ʈ ���̽� �ݺ���

		cin >> x1 >> y1 >> x2 >> y2;
		
		int systems; //�༺�� ����
		cin >> systems;
		
		int sum = 0;


		for (int i = 0; i < systems; i++) {

			int cx, cy, sr;
			cin >> cx >> cy >> sr;
			
			int xc1 = x1 - cx;
			int xc2 = x2 - cx;
			int yc1 = y1 - cy;
			int yc2 = y2 - cy;
			int ssr = sr * sr;


			if (
				((xc1*xc1 + yc1*yc1) <= ssr) != ((xc2*xc2 + yc2*yc2) <= ssr)
				) sum++;
			
				
				//inorout(x1, y1, cx, cy, sr) != inorout(x2, y2, cx, cy, sr)) sum++;


		}
		printf("%d\n", sum);
	}
	
	

	return 0;
}