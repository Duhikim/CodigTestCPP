#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
/*
class Photon_Cannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;
public:
	Photon_Cannon(int x, int y);
	Photon_Cannon(const Photon_Cannon& pc);

	void show_status();
};

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
	cout << "���� ������ ȣ��! \n";
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
}
Photon_Cannon::Photon_Cannon(int x, int y) {
	cout << "������ ȣ��! \n";
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
}
void Photon_Cannon::show_status() {
	cout << "Photon Cannon \n";
	cout << " Location : ( " << coord_x << " , " << coord_y << " ) \n";
	cout << " HP : " << hp << '\n';
}
*/

class Marine {
	static int total_marine_num;
	const static int i = 0;

	int hp;							// ���� ü��
	int coord_x, coord_y;			// ���� ��ġ
	bool is_dead;

	const int default_damage;

public:
	Marine();						// ������
	Marine(int x, int y);			// x, y ��ǥ�� ���� ����
	Marine(int x, int y, int default_damage);

	int attack() const;			// �������� ����
	Marine& be_attacked(int damage_earn);	//�Դ� ������
	void move(int x, int y);				// ���ο� ��ġ

	void show_status();						// ���¸� �����ش�.
	static void show_total_marine();
	~Marine() { total_marine_num--; }
	
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
	cout << "��ü ���� �� : " << total_marine_num << '\n';
}

Marine::Marine()
	: hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
	total_marine_num++;
}
Marine::Marine(int x, int y) 
	: hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false) {
	total_marine_num++;
}
Marine::Marine(int x, int y, int default_damage)
	: hp(50), 
	coord_x(x), coord_y(y), 
	default_damage(default_damage), 
	is_dead(false) {
	total_marine_num++;
}
void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
int Marine::attack() const { return default_damage; }

Marine& Marine::be_attacked(int damage_earn){
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;

	return *this;
}
void Marine::show_status() {
	cout << " *** Marine ***\n";
	cout << " Location : ( " << coord_x << ", " << coord_y << ") \n";
	cout << " HP : " << hp << '\n';
	cout << " ���� �� ���� �� : " << total_marine_num << '\n';
}


int main() {
	
	Marine marine1(2, 3, 5);
	marine1.show_status();
	
	Marine marine2(3, 5, 10);
	marine2.show_status();

	cout << '\n' << "���� 1�� ���� 2�� �� �� ����! " << '\n';
	marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();

	return 0;
}