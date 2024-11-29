#include <iostream>
using namespace std;

int Qunit, flowunit, tempunit;
string Qunitchar, flowunitchar, tempunitchar;
bool quitprogram = 0;
double Qcal_v = 0, flow_v = 0, deltaT_v = 0;
bool Qloop = 0, floop = 0, tloop = 0; //void unit_setting() ���� ���

//Q ���� ���� �Լ�
void Q_unit_set(int x) {
	switch (x) {
	case 1 :
		Qunitchar = "kW";
		cout << "���õ� ���� : " << Qunitchar << '\n';
		break;
	case 2:
		Qunitchar = "BTU/h";
		cout << "���õ� ���� : " << Qunitchar << '\n';
		break;
	case 3:
		Qunitchar = "kcal/h";
		cout << "���õ� ���� : " << Qunitchar << '\n';
		break;
	case 0:
		cout << "���α׷��� �����մϴ�. \n";
		quitprogram = 1;
		break;
	default :
		cout << "1, 2, 3 �Ǵ� 0�� �Է��Ͻʽÿ�. \n";
		Qloop = 1;
		break;
	}	
}

//���� ���� ���� �Լ�
void flow_unit_set(int x) {
	switch (x) {
	case 1:
		flowunitchar = "LPM";
		cout << "���õ� ���� : " << flowunitchar << '\n';
		break;
	case 2:
		flowunitchar = "LPS";
		cout << "���õ� ���� : " << flowunitchar << '\n';
		break;
	case 3:
		flowunitchar = "CFM";
		cout << "���õ� ���� : " << flowunitchar << '\n';
		break;
	case 4:
		flowunitchar = "CMH";
		cout << "���õ� ���� : " << flowunitchar << '\n';
		break;
	case 5:
		flowunitchar = "GPM";
		cout << "���õ� ���� : " << flowunitchar << '\n';
		break;
	case 0:
		cout << "���α׷��� �����մϴ�. \n";
		quitprogram = 1;
		break;
	default:
		cout << "1, 2, 3, 4, 5 �Ǵ� 0�� �Է��Ͻʽÿ�. \n";
		floop = 1;
		break;
	}
}

//�µ� ���� ���� �Լ�
void temp_unit_set(int x) {
	switch (x) {
	case 1:
		tempunitchar = "��C";
		cout << "���õ� ���� : " << tempunitchar << '\n';
		break;
	case 2:
		tempunitchar = "��F";
		cout << "���õ� ���� : " << tempunitchar << '\n';
		break;
	case 3:
		tempunitchar = "K";
		cout << "���õ� ���� : " << tempunitchar << '\n';
		break;
	case 0:
		cout << "���α׷��� �����մϴ�. \n";
		quitprogram = 1;
		break;
	default:
		cout << "1, 2, 3 �Ǵ� 0�� �Է��Ͻʽÿ�. \n";
		tloop = 1;
		break;
	}
}

//���� ���� �Լ�
void unit_setting() {
	
	cout << "\n<������ ���� �Է�>\n";

	do {
		Qloop = 0;
		cout << "\n<Q (�ð��� ����) ����> \n";
		cout << "1. kW		2. BTU/h		3. kcal/h		0. ���α׷� ����\n";
		cin >> Qunit;
		if (Qunit == 0) quitprogram = 1;
		if (!quitprogram) { Q_unit_set(Qunit); }
	} while (Qloop);

	do {
		floop = 0;
		if (!quitprogram) {
			cout << "\n<���� ����> \n";
			cout << "1. LPM		2. LPS		3. CFM		4. CMH		5. GPM		0. ���α׷� ���� \n";
			cin >> flowunit;
			if (Qunit == 0) quitprogram = 1;
		}
		if (!quitprogram) flow_unit_set(flowunit);
	} while (floop);

	do {
		tloop = 0;
		if (quitprogram != 1) {
			cout << "\n<�µ� ����> \n";
			cout << "1. ��C		2. ��F		3. K		0. ���α׷� ����  \n\n";
			cin >> tempunit;
			if (Qunit == 0) quitprogram = 1;
		}
		if (quitprogram != 1) temp_unit_set(tempunit);
	} while (tloop);
		
}

//���ϰ��� �ϴ� ���� ���� �Լ�
int which_value;
void which_you_want() {
	cout << "\n���ϰ��� �ϴ� ������ �Է��Ͻÿ�.\n";
	cout << "1. Q (�ð��� ����)		2. M (��������)		3. deltaT (�µ���)		9. ���� �缳��		0. ���α׷� ����\n";
	cin >> which_value;
	switch (which_value) {
	case 1:
		cout << "Q (�ð��� ����)�� �����ϼ̽��ϴ�. \n\n";
		break;
	case 2:
		cout << "M (���� ����)�� �����ϼ̽��ϴ�. \n\n";
		break;
	case 3:
		cout << "deltaT (�µ���)�� �����ϼ̽��ϴ�. \n\n";
		break;
	case 9:
		cout << "������ �ٽ� �����մϴ�. \n\n";
		unit_setting();
		break;
	case 0:
		cout << "���α׷��� �����մϴ�. \n";
		quitprogram = 1;
		break;
	default:
		cout << "1, 2, 3, 9 �Ǵ� 0�� �Է��Ͻʽÿ�. \n";
		which_you_want();
		break;
	}
	
}

//���� ���� �Լ�
int material;
double specific_h;
double density;
void choose_material() {
	cout << "\n����ȯ �ϴ� ������ � �����Դϱ�? Ȥ�� ���� ���� �Է��Ͻʽÿ�. \n";
	cout << "1. ��		2. ����		3. ��/�е� ���� �Է�		9. ���� �缳��		0. ���α׷� ���� \n";
	cin >> material;
	switch (material) {
	case 1:
		specific_h = 4.1868; //���� �� �Է� 4.1868 [kJ / K*kg]
		density = 1; //���� �е� �Է�. 1kg/liter
		break;
	case 2:
		specific_h = 1.004832; //������ �� �Է� 1.004832 [kJ / K*kg]
		density = 1.29/1000; //������ �е� �Է�. 1.29 g/liter
		break;
	case 3:
		cout << "���� �Է��� �ֽʽÿ�. ���� [kcal/kg����C] \n";
		cin >> specific_h;
		cout << "�е��� �Է��� �ֽʽÿ�. ���� [kg/m^3] \n";
		cin >> density;
		break;
	case 9:
		cout << "������ �ٽ� �����մϴ�. \n\n";
		unit_setting();
		break;
	case 0:
		cout << "���α׷��� �����մϴ�. \n";
		quitprogram = 1;
		break;
	default:
		cout << "1, 2, 3, 9 �Ǵ� 0�� �Է��Ͻʽÿ�. \n";
		choose_material();
		break;
	}
}

//���� �Է�
double Qcal() {
	cout << "\n�ð��� ������ �Է��Ͻʽÿ�. " << Qunitchar << '\n';
	double temp;
	cin >> temp;
	return temp;
}

//���� �Է�
double flow() {
	cout << "\n������ ������ �Է��Ͻʽÿ�. " << flowunitchar << '\n';
	double temp;
	cin >> temp;
	return temp;
}
//�µ��� �Է�
double deltaT() {
	cout << "\n���ⱸ �µ����� �Է��Ͻʽÿ�. " << tempunitchar << '\n';
	double temp;
	cin >> temp;
	return temp;
}

//Q ���� ȯ��
double coordQ(double x) {
	switch (Qunit) {
	case 1: // kW = kJ/s
		return x;
	case 2: //BTU/h
		return (x * 2.928751 / 10000);
	case 3: //kcal/h
		return (x * 1.162222 / 1000);		
	}
}

//���� ���� ȯ��
double coordflow(double x) {
	switch (flowunit) {
	case 1: //LPM
		return (x / 60);
	case 2: //LPS
		return x;		
	case 3: //CFM
		return (x * 0.4719474);
	case 4: //CMH
		return (x * 0.2777778);
	case 5: //GPM
		return (x * 6.30902 / 100);
	}
}

//�µ��� ���� ȯ��
double coordtemp(double x) {
	switch (tempunit) {
	case 1: // ����
		return x;
	case 2: // ȭ��
		return (x / 1.8);
	case 3: //�̺�
		return x;
	}
}

// Q ���
double calcQ(double f, double t) {
	return specific_h * density * f * t;
}
// ���� ���
double calcflow(double q, double t) {
	return q / (specific_h * density * t);
}
// �µ��� ���
double calctemp(double q, double f) {
	return q / (specific_h * density * f);
}

// Q ���
void outputQ(double q) {
	switch (Qunit) {
	case 1: // kW = kJ/s
		cout << "\n------------------------------------------------------\n";
		cout << "�ð��� ������" << q << " " << Qunitchar << "�Դϴ�.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 2: //BTU/h
		cout << "\n------------------------------------------------------\n";
		cout << "�ð��� ������" << (q / 2.928751 * 10000) << " " << Qunitchar << "�Դϴ�.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 3: //kcal/h
		cout << "\n------------------------------------------------------\n";
		cout << "�ð��� ������" << (q / 1.162222 * 1000) << " " << Qunitchar << "�Դϴ�.\n";
		cout << "------------------------------------------------------\n";
		break;
	}
}

// ���� ���
void outputflow(double f) {
	switch (flowunit) {
	case 1: //LPM
		cout << "\n------------------------------------------------------\n";
		cout << "������" << f*60 << " " << flowunitchar << "�Դϴ�.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 2: //LPS
		cout << "\n------------------------------------------------------\n";
		cout << "������" << f << " " << flowunitchar << "�Դϴ�.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 3: //CFM
		cout << "\n------------------------------------------------------\n";
		cout << "������" << (f / 0.4719474) << " " << flowunitchar << "�Դϴ�.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 4: //CMH
		cout << "\n------------------------------------------------------\n";
		cout << "������" << (f / 0.2777778) << " " << flowunitchar << "�Դϴ�.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 5: //GPM
		cout << "\n------------------------------------------------------\n";
		cout << "������" << (f / 6.30902 * 100) << " " << flowunitchar << "�Դϴ�.\n";
		cout << "------------------------------------------------------\n";
		break;
	}
}
 
// �µ��� ���
void outputtemp(double t) {
	switch (tempunit) {
	case 1: // ����
		cout << "\n------------------------------------------------------\n";
		cout << "���ⱸ �µ�����" << t << " " << tempunitchar << "�Դϴ�.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 2: // ȭ��
		cout << "\n------------------------------------------------------\n";
		cout << "���ⱸ �µ�����" << t*1.8 << " " << tempunitchar << "�Դϴ�.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 3: //�̺�
		cout << "\n------------------------------------------------------\n";
		cout << "���ⱸ �µ�����" << t << " " << tempunitchar << "�Դϴ�.\n";
		cout << "------------------------------------------------------\n";
		break;
	}
}

//��� ������ �⺻������ ȯ���Ͽ� ����Ѵ�. Q [kW/h], c[kJ/K kg], m [kg/s], T [K], flow[LPS]
int main() {
	bool programend = 0;
	bool partloop = 0;

	printf("Q = C x M x deltaT ���� (ver 1.01)\n\n"); //ver1.01 March 20, 2024


	while (!programend) {
		if (!partloop) unit_setting(); // ���� ����

		if (quitprogram) return 0;
		which_you_want(); // ���ϰ��� �ϴ� ���� ����

		if (quitprogram) return 0;
		choose_material(); // ���� �Է�

		if (quitprogram) return 0;
		if (which_value != 1)	Qcal_v = Qcal();
		if (which_value != 2)	flow_v = flow();
		if (which_value != 3)	deltaT_v = deltaT();


		if (quitprogram) return 0;

		//����� ���� ���� ȯ��
		if (which_value != 1)	Qcal_v = coordQ(Qcal_v);
		if (which_value != 2)	flow_v = coordflow(flow_v);
		if (which_value != 3)	deltaT_v = coordtemp(deltaT_v);
		//���
		if (which_value == 1)	Qcal_v = calcQ(flow_v, deltaT_v);
		if (which_value == 2)	flow_v = calcflow(Qcal_v, deltaT_v);
		if (which_value == 3)	deltaT_v = calctemp(Qcal_v, flow_v);

		//��� ���� ȯ�� �� ���
		if (which_value == 1)	outputQ(Qcal_v);
		if (which_value == 2)	outputflow(flow_v);
		if (which_value == 3)	outputtemp(deltaT_v);


		if (quitprogram) return 0;
		bool questionloop = 0;
		do {
			questionloop = 0;
			cout << "\n\n�ٽ� �Ͻðڽ��ϱ�?\n";
			cout << "1. ���� ������ �ٽ� ���		2. ���� �缳��		0. ���α׷� ����\n";
			int endoption;
			cin >> endoption;
			switch (endoption) {
			case 1:
				partloop = 1;
				break;
			case 2:
				partloop = 0;
				break;
			case 0:
				return 0;
			default:
				cout << "1, 2 Ȥ�� 0�� �Է��Ͻʽÿ�.\n";
				questionloop = 1;
				break;
			}
		} while (questionloop);


	}

}