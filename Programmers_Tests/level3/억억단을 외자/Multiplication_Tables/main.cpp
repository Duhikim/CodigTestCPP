#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;    
    
    int number = 0;
    int min_of_s = *min_element(starts.begin(), starts.end());

    // ���̺��� ����� �ݺ� Ƚ���� �������� ������ ������ ��. 
    // ������ starts�� ��ҵ�� ���ؼ� ���������� first���ڸ� ��. 
    // first ���ڰ� starts�� ��ҿ� e ���̸� second ���ڸ� push_back.

    vector<pair<int, int>> num_time;

    for (int i = 1; i <= e; i++) {
        for (int j = 1; j <= e; j++) {
            number = i * j;
            if (number > e) break;
            if (number < min_of_s) continue;
            //vector�� first�� �ش� ���ڰ� �ִ��� Ž��
            auto iter = find_if(num_time.begin(), num_time.end(), 
                [number](const pair<int, int>& p) {return p.first == number; });
            if (iter == num_time.end()) {
                num_time.push_back({ number, 1 });
            }
            else {
                iter->second++;
            }
        }
    }
    //�ι�° ��Ҹ� �������� ������ ����.
    sort(num_time.begin(), num_time.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
        });
    
    for (int s : starts) {
        for (const pair<int, int>& p : num_time) {
            if (p.first >= s) {
                answer.push_back(p.first);
                break;
            }
        }
    }  
    
    return answer;
}

int main() {
    int e;
    vector<int> starts;
    vector<int> expected;
    vector<int> results;

    e = 8;
    starts = { 1, 3, 7 };
    expected = { 6, 6, 8 };
    results = solution(e, starts);
    if (expected == results) cout << "Correct!" << '\n';
    else cout << "Wrong.." << '\n';

    return 0;
}