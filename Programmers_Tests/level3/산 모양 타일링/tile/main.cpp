#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    // tops�� ù° �׺��� ��. 1�ϰ�� 4, 0�ϰ�� 3.  �̰��� a1�̶� ����.
    // ��° ���� ��. 1�� ���, 4*a1 - 1. 0�� ��� 3*a1 - 1. �̰��� a2.
    // ��° ���� ��. 1�� ��� 4*a2 - a1, 0�� ��� 3* a2- a1. �̰��� a3.
    // �Ǻ���ġ�� �����. n��° ���� a(n)�̶� �� ���, n��° tops�� 1�� ��� 4*a(n-1) - a(n-2), 0�� ��� 3*a(n-1) - a(n-2)�� �ϸ� �ȴ�.
    unsigned long long num_of_cases;   
    unsigned long long temp1, temp2=1; // ���� a(n-1), a(n-2)�� ������ ����.
            
    if (tops[0]) num_of_cases = 4;
    else num_of_cases = 3;
    if (n == 1) return num_of_cases;
    temp1 = num_of_cases;

    for (int i = 1; i < n; i++) {
        if (tops[i]) {
            num_of_cases = 4 * temp1 - temp2;
            temp2 = temp1%10007;
            temp1 = num_of_cases%10007;
        }
        else {
            num_of_cases = 3 * temp1 - temp2;
            temp2 = temp1%10007;
            temp1 = num_of_cases%10007;
        }
        if (((4 * temp1) < temp2 ) || ((3 * temp1) < temp2 ) ) {
            temp1 += 10007;
        }        
    }

    answer = num_of_cases % 10007;
    return answer;
}


int main() {
    int n;
    vector<int> tops;
    
    n = 4;
    tops = { 1,1,0,1 };
    cout << "���� 149, �� : " << solution(n, tops) << '\n';

    n = 2;
    tops = { 0,1 };
    cout << "���� 11, �� : " << solution(n, tops) << '\n';

    n = 10;
    tops = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    cout << "���� 7704, �� : " << solution(n, tops) << '\n';

    cout << "\n���⼭ ���ʹ� ������ �׽�Ʈ ���Դϴ�.\n";
    n = 100000;
    cout << "ũ��: " << n << '\n';
    tops.clear();
    for (int i = 0; i < n; i++) {
        tops.push_back(1);
    }
    cout << solution(n, tops) << '\n';
   
       
    
    return 0;
}