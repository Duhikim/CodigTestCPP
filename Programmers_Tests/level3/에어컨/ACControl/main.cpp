#include <string>
#include <vector>
#include <iostream>

using namespace std;
void Search(vector<int>& onboard, int idx, int consumption, int cur_temp, vector<vector<int>>& Consumption, vector<int>& setting, int& answer) {
    
    if (idx == onboard.size()) {
        answer = min(consumption, answer);
        return;
    }
    if (onboard[idx] && (cur_temp<setting[1] || cur_temp >setting[2])) return;
    if (Consumption[idx][cur_temp] <= consumption) return;
    Consumption[idx][cur_temp] = consumption;
   
    
    // ����
    Search(onboard, idx + 1, consumption, min(setting[0], cur_temp + 1), Consumption, setting, answer);
    // ���� ����
    if(setting[4]<=setting[3])
    Search(onboard, idx + 1, consumption + setting[4], cur_temp, Consumption, setting, answer);
    // ����
    Search(onboard, idx + 1, consumption + setting[3], max(setting[1], cur_temp - 1), Consumption, setting, answer);
    
}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
 
    int answer = 10000000;
    vector<vector<int>> Consumption(1001, vector<int>(51, 10000000));
    
    int OA_temp = temperature;
    if (OA_temp < t1) OA_temp = t2 + (t1 - temperature);
    vector<int> setting = { OA_temp, t1, t2, a, b };

    Search(onboard, 0, 0, OA_temp, Consumption, setting, answer);
    
    return answer;
}


int main() {

    int temperature; // �ǿ� �µ� (-10~40)
    int t1, t2; // �ǳ� �µ� ���� (-10~40, temperature�� t1, t2 ���� ��)
    int a, b; // ������ �Һ� ����
    vector<int> onboard; // �°��� ž�� ���� �ð��� ��Ÿ���� �迭 (2<= �迭 ���� <= 1000)

    temperature = 28;
    t1 = 18;
    t2 = 26;
    a = 10;
    b = 8;
    onboard = { 0,0,1,1,1,1,1, 0, 0, 0 };
    cout << "��� �� 40, ��� �� : " << solution(temperature, t1, t2, a, b, onboard) << '\n';
    

    temperature = -10;
    t1 = -5;
    t2 = 5;
    a = 5;
    b = 1;
    onboard = { 0, 0, 0, 0, 0, 1, 0 };
    cout << "��� �� 25, ��� �� : " << solution(temperature, t1, t2, a, b, onboard) << '\n';
    

    temperature = 11;
    t1 = 8;
    t2 = 10;
    a = 10;
    b = 1;
    onboard = { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1 };
    cout << "��� �� 20, ��� �� : " << solution(temperature, t1, t2, a, b, onboard) << '\n';

    temperature = 11;
    t1 = 8;
    t2 = 10;
    a = 10;
    b = 100;
    onboard = { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0};
    cout << "��� �� 60, ��� �� : " << solution(temperature, t1, t2, a, b, onboard) << '\n';

    temperature = 13;
    t1 = 8;
    t2 = 10;
    a = 10;
    b = 6;
    onboard = { 0,0,0,0, 1, 1, 1, 1, 0, 1, 0 };
    cout << "��� �� 56, ��� �� : " << solution(temperature, t1, t2, a, b, onboard) << '\n';

    temperature = 11;
    t1 = 8;
    t2 = 10;
    a = 10;
    b = 100;
    onboard.clear();
    onboard.push_back(0);
    for (int i = 0; i < 1000; i++) {
        int random_no = rand() % 2;
        onboard.push_back(random_no);
    }   
    
    cout << "�� ���̽��� ���� �ӵ��� Ȯ���ϱ� �����̴�. �� : " << solution(temperature, t1, t2, a, b, onboard) << '\n';
    

    return 0;
}

