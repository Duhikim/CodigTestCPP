#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool debug = //true;
            false;

long long circle(int r);
long long on_the_line(int r);

long long solution(int r1, int r2) {
    long long answer = 0;

    answer = circle(r2) - circle(r1) + on_the_line(r1);

    return answer;
}

long long circle(int r) {
    long long counter = 0;

    for (int i = 1; i < r; i++) {        
        counter += (int)sqrt(pow(r, 2) - pow(i, 2));
    }
    counter = (counter + r) * 4 + 1;

    if (debug) printf("�������� %d�� ���� ����(�����ڸ� ����)�� �ִ� �������� ������ %d �Դϴ�.\n", r, counter);
    return counter;
}
long long on_the_line(int r) {
    long long counter = 0;

    for (int i = 1; i < r; i++) {
        if (((int)sqrt(pow(r, 2) - pow(i, 2))) == (sqrt(pow(r, 2) - pow(i, 2)))) counter++;
    }
    counter = counter * 4 + 4;

    if (debug) printf("�������� %d�� ���� �����ڸ��� �ִ� �������� ������ %d �Դϴ�.\n", r, counter);
    return counter;
}

int main() {
    int r1=5, r2=6;
    //cin >> r1 >> r2; //1 �� r1 < r2 �� 1,000,000
    printf("�������� r1 : %d, r2 : %d �� �� �� ������ ���� ���� ������ %d �� �Դϴ�.", r1, r2, solution(r1, r2));

    return 0;
}