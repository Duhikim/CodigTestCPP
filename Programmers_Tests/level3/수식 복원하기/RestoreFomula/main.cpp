#include <string>
#include <vector>
#include <iostream>

using namespace std;

int GetBase(const vector<string>& expressions, vector<string>& answer, int& basebase) {
    // 1. ������ ���Ŀ� ������ ���� ū ���ں��� ũ��.
    // 2. ���� Ȥ�� �������� �ڸ��� �Ѿ� ������ �ִ� ������ ���, ������� 6+5 = 13, 33-6 = 24, 22+20 = 102, 13+17 = 32, ������ Ȯ���ȴ�.
    // 3. ������ Ȯ������ �ʴ� ��쵵 ����. �׶� 0�� Return�ϵ��� �Ѵ�.    
    int a, b, c, ind=-1;
    bool plus = true;
    for (string fomula : expressions) {        
        if (fomula[fomula.size() - 1] == 'X') {
            answer.push_back(fomula);
        }
    }

    for (string fomula : expressions) {        
        if (fomula[fomula.size() - 1] == 'X') {
            continue;
        }
        for (int i = 2; i < fomula.size(); i++) {
            if (fomula[i] == '+') { plus = true; break; }
            if (fomula[i] == '-') { plus = false; break; }
        }
        
        size_t idx = 0, idx2 = 0;        
        a = stoi(fomula, &idx); idx += 3;
        b = stoi(fomula.substr(idx), &idx2); idx += (idx2+3);
        c = stoi(fomula.substr(idx), &idx);
        
        int c_dec = plus ? a + b : a - b;
        int diff = abs(c - c_dec);
        if (diff == 0) continue;
        if (diff < 9) return (10 - diff); //������� �ϸ� ���� ���ڸ� ���� ������ ����. ������ �� ���ڸ��� �Ѿ�� ��� üũ�ؾ���.
        
        if(c_dec % 10 != c % 10) return (c_dec % 10) ? c_dec % 10 - c % 10 : 10 - c % 10;
        else {
            return (c_dec / 10 + 10 - c / 10);
        }
        
    }

    //�� �������� ��ã�� ���, Ȥ�� �Ŀ� 8�� ���ԵǾ� ������ 9���� Ȯ��. ���� ��� �ִ� ���� �̿��� �ּ� ���� basebase�� ���Ѵ�.
    basebase = 2;
    for (string fomula : expressions) {
        for (char num : fomula) {
            if (num == '8') return 9;
            if (num >= '0' && num <= '9' &&
                num - '0' >= basebase) {
                basebase = num - '0' + 1;
            }
        }
    }
    return 0;
}

void ConvertText(vector<string>& answer, int base, int basebase) {
    int a, b, c;
    bool plus = true;
    for (string& fomula : answer) {
        for (int i = 2; i < fomula.size(); i++) {
            if (fomula[i] == '+') { plus = true; break; }
            if (fomula[i] == '-') { plus = false; break; }
        }

        size_t idx = 0;
        a = stoi(fomula, &idx);
        idx += 3;
        b = stoi(fomula.substr(idx), &idx);        

        int a_dec, b_dec, c_dec;
        string c_str = "";
        if (base) {  
            a_dec = a % 10 + (a / 10) % 10 * base;
            b_dec = b % 10 + (b / 10) % 10 * base;
            c_dec = plus ? a_dec + b_dec : a_dec - b_dec;
            c_str += (char)((c_dec / (base * base)) % base + '0');
            c_str += (char)((c_dec / base) % base + '0');
            c_str += (char)(c_dec % base + '0');                       
        }
        else {
            // 1. �� �ڸ��� ���ڰ� a�� b���� ũ�ų� ���� ��� �״�� ���� �ϸ� ��. (ex 54 - 23�� ������ ���� ���� 31�̴�.)            
            // 2. ���ϱ��� ���, �� �ڸ��� ���ڳ��� ������ �� �ּ��������� ������ �״�� ���ϸ� ��. (�ּ� ������ 7�� �� 23+11 �� ���� ������� 34�̴�.)
            if (plus) {
                if ((a % 10 + b % 10 < basebase) && ((a / 10) % 10 + (b / 10) % 10) < basebase) {
                    c_dec = a + b;
                    c_str += (char)((c_dec / 10) % 10 + '0');
                    c_str += (char)(c_dec % 10 + '0');
                }
                else { c_str += '?'; }
            }
            else {
                if ((a % 10 >= b % 10) && ((a / 10) % 10 >= (b / 10) % 10)) {
                    c_dec = a - b;
                    c_str += (char)((c_dec / 10) % 10 + '0');
                    c_str += (char)(c_dec % 10 + '0');
                }
                else { c_str += '?'; }
            }
        }
        while (c_str[0] == '0' && c_str.size()>1) { c_str.erase(0, 1); }
        fomula.erase(fomula.size() - 1, 1);
        fomula += c_str;
    }
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;       
    int basebase = 0;
    int base = GetBase(expressions, answer, basebase);  
    if (base) cout << '(' << base << "���� ���)\n";
    else cout << "(������ �� �� ����. �ּ� ���� : " << basebase <<")\n";
   
    ConvertText(answer, base, basebase);

    return answer;
}

int main() {
    vector<string> expressions;

    expressions = {
        "14 + 3 = 17", "13 - 6 = X", "51 - 5 = 44"
    };
    cout << "Result : \n";
    for (auto& str : solution(expressions)) {
        cout << str << '\n';
    }cout << '\n';

    expressions = {
       "1 + 1 = 2", "1 + 3 = 4", "1 + 5 = X", "1 + 2 = X"
    };
    cout << "Result : \n";
    for (auto& str : solution(expressions)) {
        cout << str << '\n';
    }cout << '\n';

    expressions = {
       "10 - 2 = X", "30 + 31 = 101", "3 + 3 = X", "33 + 33 = X"
    };
    cout << "Result : \n";
    for (auto& str : solution(expressions)) {
        cout << str << '\n';
    }cout << '\n';

    expressions = {
       "2 - 1 = 1", "2 + 2 = X", "7 + 4 = X", "5 - 5 = X"
    };
    cout << "Result : \n";
    for (auto& str : solution(expressions)) {
        cout << str << '\n';
    }cout << '\n';

    expressions = {
       "2 - 1 = 1", "2 + 2 = X", "7 + 4 = X", "8 + 4 = X"
    };
    cout << "Result : \n";
    for (auto& str : solution(expressions)) {
        cout << str << '\n';
    }cout << '\n';


}