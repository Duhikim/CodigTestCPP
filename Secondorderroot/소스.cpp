#include <iostream>
#include <cmath>
using namespace std;

float calcroot(float a, float b, float c); //���� ���� ��� �Լ� ����


int main() {
	bool endmainloop = false; //end main loop�� true�� �Ǹ� ���α׷� ����.
	bool azeroloop = true; //a�� 0�ϰ�� a�� �ٽ� �Է�.
	float a, b, c;
	float ans1=0, ans2=0;

	while (endmainloop == false) {
		while (azeroloop) {
			cout << "2�� ������ ax^2 + bx + c = 0�� ���Ͽ� \n";
			cout << "0�� �ƴ� �Ǽ� a�� ���� �Է��Ͻÿ�. \n";
			cin >> a;
			if (a == 0) {
				cout << "0�� �ƴ� �Ǽ��� �Է��Ͻÿ�.\n";
				
			}
			else {
				azeroloop = false;
				cout << "�Ǽ� b�� ���� �Է��Ͻÿ�. \n";
				cin >> b;
				cout << "�Ǽ� c�� ���� �Է��Ͻÿ�. \n";
				cin >> c;
			}

		}
			
		azeroloop = true;

		
		calcroot(a, b, c);		//���� ���� �Լ�

		bool endqstloop = false;

		while (endqstloop==false) { //���α׷� ���� �ǻ� Ȯ��

			char endqst;
			cout << "�ٽ� �Ͻðڽ��ϱ�? (y / n) \n";
			cin >> endqst;

			if ((endqst == 'n') || (endqst == 'N')) { endqstloop = true; endmainloop = true; }
			else if ((endqst == 'y') || (endqst == 'Y')) { endqstloop = true; }
			else {
				cout << "y Ȥ�� n�� ���� �Է��Ͻʽÿ�. \n";
			}

			}

	}


	return 0;
}

float calcroot(float a, float b, float c) { //���� ���� �Լ� ����
	//ans1 = (-b+(b^2-4ac)^0.5)/2a
	//ans1 = (-b-(b^2-4ac)^0.5)/2a
	//b^2-4ac => 0 > �Ǽ���, < 0 �����
	//-b/2a +- disc/2a*i

	float ans1, ans2;

	float disc = pow(b, 2) - (4 * a * c);
	
	if (disc >=  0) {
		ans1 = (0 - b + pow(disc, 0.5)) / (2 * a);
		ans2 = (0 - b - pow(disc, 0.5)) / (2 * a);
		cout << "2�� ������" << a << "x^2 + " << b << "x + " << c << " = 0 �� �Ǳ��� " << ans1 << " �� " << ans2 << "�Դϴ�. \n\n";
	}
	else {
		float tmp = pow(0 - disc, 0.5) / (2 * a);
		ans1 = (0 - b) / (2 * a);

		cout << "2�� ������" << a << "x^2 + " << b << "x + " << c << " = 0 �� ����� " << ans1 << "+"<< tmp << "*i" <<" �� " << ans1 << "-" << tmp << "*i" << "�Դϴ�. \n\n";

	}

	return 0;


}
