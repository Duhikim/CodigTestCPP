#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;
bool debug = true;
             //false;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);

    set<int> all_numbers;
    for (const auto& v1 : edges) {
        all_numbers.insert(v1[0]);
        all_numbers.insert(v1[1]);
    }
    map<int, int> find_index;
    int index = 0;
    for (const auto& num1 : all_numbers) {
        find_index.insert({ num1, index++ });
    }
    
    vector<vector<int>> all_data;
    vector<int> ea_data(4, 0); // {0�� ��ȣ, 1Leaving ��, 2Entering ��, 3�߽������� �޾Ҵ���(booló�� ����� ����)}
    for (const auto& v1 : all_numbers) {
        ea_data[0] = v1;
        all_data.push_back(ea_data);
    }

    for (const auto& v1 : edges) {
        all_data[find_index[v1[0]]][1]++;
        all_data[find_index[v1[1]]][2]++;
    }

    int center_point=0;
    for (const auto& v1 : all_data) {
        if (v1[1] > 1 && !v1[2]) { //Leaving�� 2 �̻��̸� Entering�� 0�� ��� �߽����̴�.
            center_point = v1[0];
            break;
        }
    }

    int total_qty = 0;
    for (const auto& v1 : edges) {
        if (v1[0] == center_point) {
            all_data[find_index[v1[1]]][3] = 1;
            total_qty++;
        }
    }

    int amount_doughnut = 0;
    int amount_column = 0;
    int amount_eightshape = 0;
    
    for (const auto& v1 : all_data) {
        if (!v1[1]) { 
            amount_column++; //Leaving�� 0�� ����Ʈ�� ���� ���� ��� �׷����� ���� ����.
        } 
        if ((v1[1] == 2) && ((v1[2] == 2) || ((v1[2] == 3) && (v1[3])))) { //(Leaving�� 2 �̸鼭,) && ((Entering�� 2 �̰ų�,) || (Entering�� 3�̸� && �߽����� 1�̰ų�))
            amount_eightshape++;        
        }
    }
    amount_doughnut = total_qty - (amount_column + amount_eightshape);
    
    answer[0] = center_point;
    answer[1] = amount_doughnut;
    answer[2] = amount_column;
    answer[3] = amount_eightshape;
    return answer;
}


int main() {
    vector<vector<int>> edges1 = { 
        {2, 3}, {4, 3}, 
        {1, 1}, {2, 1} }; 
    if (debug) {
        for (auto num : solution(edges1)) {
            cout << num << " , ";
        } cout << '\n' << '\n';
    }
    // ��밪 {2, 1, 1, 0} (������ ���� ��ȣ, ������ ��� ��, ���� ��� ��, 8�� ��� ��)

    vector<vector<int>> edges2 = {
        {4, 11}, {1, 12}, {8, 3}, {12, 7}, {4, 2}, 
        {7, 11}, {4, 8}, {9, 6}, {10, 11}, {6, 10}, 
        {3, 5}, {11, 1}, {5, 3}, {11, 9}, {3, 8}
    };
    if (debug) {
        for (auto num : solution(edges2)) {
            cout << num << " , ";
        } cout << '\n' << '\n';
    }
    // ��밪 {4, 0, 1, 2} (������ ���� ��ȣ, ������ ��� ��, ���� ��� ��, 8�� ��� ��)


}