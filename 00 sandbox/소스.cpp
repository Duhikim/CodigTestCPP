#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int main() {
    vector<int> test = { 1,2,3,4,5,6,7,8,9 }; // �� �����ʹ� �������� ������ ����ȴ�.

    deque<int&> refVector = {};
    refVector.push_back(test[8]);
    cout << "���� ���Ϳ� � ���� �����Ͽ���. (����) refVector[0] = " << refVector[0] << '\n';
    test[8] = 19;
    cout << "���� �������� ���� 9���� 19�� �����Ͽ���. refVector[0] = " << refVector[0] << '\n';
    int& a = refVector.back();
    cout << "int& a�� refVector�� ��(������)�� �����Ѵ�." << '\n';
    int b = refVector.back();
    cout << "int b�� refVector�� ��(������)�� �����Ѵ�." << '\n';
    return 0;
}