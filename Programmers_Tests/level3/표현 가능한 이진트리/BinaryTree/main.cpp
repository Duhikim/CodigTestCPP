#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <cmath>
#define ll long long

using namespace std;

void Search(string& binary_num, int start, int size, int& ans) {
    if (size == 1 || !ans) return;

    if (binary_num[start + size / 2] == '0') {
        for (int i = start; i < start+size; i++) {
            if (binary_num[i] == '1') {
                ans = 0;
                return;
            }
        }         
        return;
    }
    else if(size>3) {
        Search(binary_num, start + (size / 2) + 1, size / 2, ans);
        Search(binary_num, start, size / 2, ans);                    
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer(numbers.size());
    
    for (int i = 0; i < numbers.size(); i++) {
        ll num = numbers[i];
        
        int n = 0; // num�� 2������ �ٲ��� �� �ڸ���
        while (pow(2,++n) < num) { }
        //n�� 1, 3, 5, 7, 15�� ���� 2^N-1 ������ ���ڿ��� �Ѵ�. �׺��� ���� ��� �տ� 0�� ä���� �����. ä�� �ڸ����� m�̶� ��
        int m = 0;
        while (pow(2, ++m)-1 < n) { }
        m = pow(2, m) - 1;        
      
        string binary_num = "";
        for (int i = 0; i < m; i++) {
            binary_num += (num % 2) ? "1" : "0"; // 2���� ��Ʈ���� �Ųٷ� ������ �������
            num /= 2;
        }     
        int ans=1;
        Search(binary_num, 0, m, ans);
        answer[i] = ans;       
    }

    return answer;
}

int main() {
    vector<long long> numbers;
    
    numbers = { 7, 42, 5, 63, 111, 95, 15, 1031, 1031 + 128, 70, 3836, 597, 19880516 };
    cout << "���� �� : { 1, 1, 0, 1, 1, 0, 1, 0, 0  }, \n��� �� : { ";
    for (int& num : solution(numbers)) {
        cout << num << "  ";
    }
    cout << "}\n";

   


}