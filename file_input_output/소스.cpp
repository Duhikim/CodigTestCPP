#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//���� Ű���� �Է� -> ���� ���� -> 16���� �ڵ�� ��� -> �ƽ�Ű �ڵ� ���

char ifname[80];
string contents[1000];

void fileinput() {
	cout << "���ϸ��� �Է��Ͻÿ�. \n";
	cin >> ifname;
}




int main() {
	
	
	fileinput();
	ifstream ifs;
	ifs.open(ifname);
	if (!ifs) {
		cerr << "Input Error!" << endl;
	}
	else {
		cout << "������ ���������� ���Ƚ��ϴ�. \n";
		
		ofstream ofs("temporary.txt", ios::out);
		if (ofs.fail()) {
			cerr << "Output Error!" << endl;
		}
		else {
			string line;
			int count = 0;
			while (getline(ifs, line)) {
					contents[count++] = line;
					if (count >= 1000) break;
									
			}
			int opcount = 0;
			while (opcount < count) {
				ofs << contents[opcount++] << '\n';
			}

			ofs.close();
		}


		ifs.close();
	}

	

	return 0;
}