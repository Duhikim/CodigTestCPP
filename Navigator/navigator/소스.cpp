#include <iostream>
#include <windows.h> //windows.h ��� �߰�
#pragma comment(lib, "Winmm.lib") //winmm.lib �߰�
using namespace std;

//
// project4������ ��� data�� array�������� ó��������
// project5������ plc data�� pointer�� ����غ��� ��
// 
// �ѱ����� �ʿ��� �⺻data�� ��û ������(1,000,000�̻�?)
// �������� ���� ã�� �� �˻��ؾ� �� ����� ����
// ��û ���� �� �����Ƿ� �Ź� ���� �ʱ�ȭ �� �ʿ� ����
//
bool debug	//= true;
			= false;
// 77 ������ ����
const int plc_max = 77;

//
// �� �������� �� �� �ִ� ������� �׸��� �װ� ���� �Ÿ�(meter)��
// ��� list ������ ���� ���� �ʰ� ����
//
struct street {
	int neibor; // �����ִ� �̿�
	int dist;	// �װ����� �Ÿ�
};
const street ways[] = {
	{	35,	157	},{	 1,	39	},{	21,	160	},	// ���� list�� ù��° �������� �� �� �ִ� ��{35th ����, 157m} ��� 3�� data
	{	 0,	41	},{	 2,	194	},{	 3,	205	},{	 6,	207	},
	{	 1,	188	},{	 6,	139	},{	 7,	135	},{	40,	84	},
	{	26,	95	},{	 5,	154	},{	 6,	183	},{	 1,	166	},
	{	26,	150	},{	44,	153	},{	 5,	38	},
	{	 4,	40	},{	10,	161	},{	 6,	125	},{	 3,	146	},
	{	 1,	204	},{	 3,	176	},{	 5,	146	},{	10,	165	},{	11,	205	},{	 9,	160	},{	 7,	133	},{	 2,	179	},
	{	 2,	136	},{	 6,	146	},{	 9,	138	},{	 8,	55	},
	{	40,	167	},{	 7,	50	},{	63,	167	},
	{	 6,	155	},{	11,	114	},{	63,	71	},{	 7,	135	},
	{	 5,	120	},{	44,	106	},{	11,	141	},{	 6,	160	},
	{	 6,	174	},{	10,	127	},{	12,	58	},{	 9,	144	},
	{	11,	58	},{	45,	165	},{	64,	153	},
	{	17,	100	},{	16,	59	},{	14,	93	},
	{	13,	101	},{	15,	59	},{	28,	304	},
	{	14,	59	},{	16,	94	},{	20,	53	},
	{	13,	53	},{	17,	97	},{	19,	52	},{	15,	92	},
	{	18,	52	},{	16,	93	},{	13,	105	},
	{	17,	53	},{	23,	50	},{	19,	85	},
	{	16,	56	},{	18,	89	},{	22,	56	},{	20,	96	},{	33,	326	},
	{	15,	56	},{	19,	89	},{	21,	58	},
	{	20,	54	},{	22,	90	},{	26,	55	},{	 0,	155	},
	{	19,	50	},{	23,	92	},{	25,	51	},{	21,	101	},
	{	18,	51	},{	24,	57	},{	22,	97	},
	{	23,	52	},{	41,	358	},{	25,	97	},
	{	22,	52	},{	24,	96	},{	42,	277	},{	26,	90	},
	{	21,	55	},{	25,	97	},{	 4,	170	},{	 3,	85	},
	{	28,	145	},{	30,	52	},{	31,	169	},
	{	14,	359	},{	29,	52	},{	27,	132	},
	{	28,	52	},{	34,	53	},{	30,	145	},
	{	27,	51	},{	29,	139	},{	33,	54	},{	31,	130	},
	{	27,	174	},{	30,	140	},{	32,	59	},
	{	31,	50	},{	33,	143	},{	37,	55	},
	{	30,	56	},{	19,	360	},{	34,	149	},{	36,	56	},{	32,	127	},
	{	29,	53	},{	35,	59	},{	33,	145	},
	{	34,	58	},{	 0,	170	},{	40,	54	},{	36,	129	},
	{	33,	53	},{	35,	141	},{	66,	289	},{	39,	52	},{	37,	142	},
	{	32,	56	},{	36,	129	},{	38,	51	},
	{	37,	57	},{	39,	149	},{	60,	335	},
	{	36,	56	},{	40,	131	},{	38,	142	},
	{	35,	50	},{	 2,	88	},{	 8,	153	},{	39,	132	},
	{	24,	327	},{	49,	54	},{	 4,	104	},
	{	25,	294	},{	41,	113	},{	47,	57	},{	43,	50	},
	{	42,	50	},{	46,	52	},{	44,	58	},
	{	 4,	179	},{	43,	56	},{	45,	54	},{	10,	106	},
	{	44,	50	},{	46,	53	},{	57,	111	},{	12,	158	},
	{	43,	53	},{	47,	59	},{	55,	59	},{	45,	58	},
	{	42,	59	},{	48,	53	},{	53,	57	},{	46,	52	},
	{	49,	52	},{	51,	59	},{	47,	59	},
	{	41,	59	},{	50,	113	},{	48,	50	},
	{	49,	106	},{	59,	120	},{	52,	57	},
	{	48,	53	},{	52,	54	},{	53,	57	},
	{	51,	52	},{	50,	53	},{	54,	53	},
	{	47,	51	},{	51,	52	},{	54,	58	},{	55,	59	},
	{	53,	57	},{	52,	51	},{	59,	53	},{	56,	59	},
	{	46,	56	},{	53,	59	},{	56,	51	},
	{	55,	53	},{	54,	51	},{	57,	54	},{	72,	302	},
	{	45,	117	},{	56,	55	},{	58,	50	},
	{	57,	57	},{	59,	100	},{	74,	300	},
	{	54,	54	},{	50,	125	},{	58,	115	},
	{	38,	341	},{	61,	150	},{	68,	51	},
	{	62,	56	},{	66,	50	},{	60,	159	},
	{	63,	100	},{	65,	51	},{	61,	50	},
	{	 8,	179	},{	 9,	80	},{	64,	51	},{	62,	114	},
	{	63,	59	},{	12,	166	},{	73,	102	},{	65,	102	},
	{	62,	57	},{	64,	101	},{	72,	110	},{	66,	56	},
	{	61,	59	},{	36,	295	},{	65,	58	},{	71,	103	},{	67,	52	},
	{	66,	57	},{	70,	108	},{	68,	117	},
	{	60,	56	},{	67,	101	},{	69,	104	},
	{	68,	111	},{	70,	102	},{	76,	137	},
	{	67,	104	},{	71,	51	},{	76,	59	},{	69,	54	},
	{	66,	100	},{	72,	56	},{	70,	54	},
	{	65,	100	},{	56,	332	},{	73,	115	},{	75,	57	},{	71,	51	},
	{	64,	110	},{	74,	57	},{	72,	110	},
	{	73,	51	},{	58,	333	},{	75,	113	},
	{	72,	50	},{	74,	110	},{	76,	105	},
	{	70,	57	},{	75,	107	},{	69,	130	}
};

//
// ���� ����Ǵ� data ����
//
const struct place_data {
	string		name;		// �����̸�
	int 			w_start;	// �� ���� ����Ǵ� ��(ways)�� ���� ��
	int			w_nr;		// �׸��� ����� ���� ����
};
const place_data plc[plc_max] = {
	{"Cir01",  0, 3},	{"Cir02",  3, 4},	{"Cir03",  7, 4},	{"Cir04", 11, 4},
	{"Cir05", 15, 3},	{"Cir06", 18, 4},	{"Cir07", 22, 8},	{"Cir08", 30, 4},
	{"Cir09", 34, 3},	{"Cir10", 37, 4},	{"Cir11", 41, 4},	{"Cir12", 45, 4},
	{"Cir13", 49, 3},
	{"NE01",  52, 3},	{"NE02",  55, 3},	{"NE03",  58, 3},	{"NE04",  61, 4},
	{"NE05",  65, 3},	{"NE06",  68, 3},	{"NE07",  71, 5},	{"NE08",  76, 3},
	{"NE09",  79, 4},	{"NE10",  83, 4},	{"NE11",  87, 3},	{"NE12",  90, 3},
	{"NE13",  93, 4},	{"NE14",  97, 4},
	{"NW01", 101, 3},	{"NW02", 104, 3},	{"NW03", 107, 3},	{"NW04", 110, 4},
	{"NW05", 114, 3},	{"NW06", 117, 3},	{"NW07", 120, 5},	{"NW08", 125, 3},
	{"NW09", 128, 4},	{"NW10", 132, 5},	{"NW11", 137, 3},	{"NW12", 140, 3},
	{"NW13", 143, 3},	{"NW14", 146, 4},
	{"SE01", 150, 3},	{"SE02", 153, 4},	{"SE03", 157, 3},	{"SE04", 160, 4},
	{"SE05", 164, 4},	{"SE06", 168, 4},	{"SE07", 172, 4},	{"SE08", 176, 3},
	{"SE09", 179, 3},	{"SE10", 182, 3},	{"SE11", 185, 3},	{"SE12", 188, 3},
	{"SE13", 191, 4},	{"SE14", 195, 4},	{"SE15", 199, 3},	{"SE16", 202, 4},
	{"SE17", 206, 3},	{"SE18", 209, 3},	{"SE19", 212, 3},
	{"SW01", 215, 3},	{"SW02", 218, 3},	{"SW03", 221, 3},	{"SW04", 224, 4},
	{"SW05", 228, 4},	{"SW06", 232, 4},	{"SW07", 236, 5},	{"SW08", 241, 3},
	{"SW09", 244, 3},	{"SW10", 247, 3},	{"SW11", 250, 4},	{"SW12", 254, 3},
	{"SW13", 257, 5},	{"SW14", 262, 3},	{"SW15", 265, 3},	{"SW16", 268, 3},
	{"SW17", 271, 3} };

//
// navi algorithm�� ���Ǵ� data����
//
struct wor_pnt { // means working point data
	int		plc_ind;		// ������ index
	int		come_from;		// ��� �������� �Գ�
	int		go_to;			// ���� ���� ��
	bool	in_f_chain;     // front chain�� �ִ���?
	wor_pnt* pre_pnt;		// front chain���� ��
	wor_pnt* post_pnt;		// front chain���� ��
	int		dist_f_start;	// ���������� ���� �Ÿ�
};
int			used_pnt = 0;		// navi�� ���� pnt ����
wor_pnt		w_pnt[plc_max]{};	// working point data��, used_pnt�� �� ����
wor_pnt*	plc2pnt[plc_max]{};	// plc�� w_pnt ���ῡ �ʿ��� pointer��
int			start_i, end_i;		// ������ ������ index
wor_pnt*	chain_start;		// front chain�� ������ ����Ŵ

// program���۽� plc2pnt�� ��� nullptr�� ä��
void init_plc2pnt() {for (int i = 0; i < plc_max; i++) plc2pnt[i] = nullptr;}
// ������� ���������� �Էµ� �� ��
// ���� ����� plc2pnt data�� �ʱ�ȭ(nullptr)
// chain_start w_pnt[0] ���� ����
void plc_init() {
	for (int i = 0; i < used_pnt; i++) plc2pnt[w_pnt[i].plc_ind] = nullptr;
	// �����(plc[0]) data
	plc2pnt[start_i] = chain_start = &w_pnt[0];
	w_pnt[0] = { start_i, start_i, 0, true, nullptr, nullptr, 0 };
	used_pnt = 1;
}

//
// plc�ȿ��� �־��� �̸�('str')�� index�� ã�� routine.
// plc[].name�� ���� �� plc_max�� return
//
int find_index_in_names(const string str) {
	int start_ind	= 0;
	int end_ind		= plc_max - 1;
	while (true) {
		int temp_ind = end_ind - start_ind; // temp_ind = ������ ���� - 1
		if (temp_ind == 0) {	// ������ �̸��� ���� �Ѱ�
			if (str == plc[start_ind].name)	return start_ind;
			else							return plc_max;
		}
		if (temp_ind == 1) {	// ������ �̸��� �ΰ�
			if (str == plc[start_ind].name)	return start_ind;
			if (str == plc[end_ind].name)	return end_ind;
			else							return plc_max;
		}
		// ���� ����� 3�� �̻�
		temp_ind = start_ind + temp_ind / 2; // temp_ind = ���� �߰��� 
		if (str > plc[temp_ind].name)	start_ind = temp_ind + 1;
		else							end_ind = temp_ind;
	}
}

/* data �����ϸ�
const int plc_max = 77,  77 ������ ����
struct street {int neibor; int dist;};
const  street ways[plc_max]{}
struct wor_pnt{ // working point
	int		plc_ind;	int come_from;		int go_to;
	bool	in_f_chain;	wor_pnt* pre_pnt;	wor_pnt* post_pnt;
	int		dist_f_start;};
wor_pnt		w_pnt[plc_max]{}
wor_pnt*	plc2pnt[plc_max]{};	// plc�� w_pnt ���ῡ �ʿ��� data��
struct place_data {string	name; int w_start; int w_nr;};
place_data plc[plc_max]
int		start_i, end_i;
int		used_pnt = 0;
wor_pnt* chain_start;
*/

// insert_front_chain()�� ���ο���(�̿�)�� front chain�� ���� �� �� ȣ��
void insert_front_chain(wor_pnt* neib_pnt) {
	wor_pnt* cur_pnt = chain_start;
	wor_pnt* next_pnt;
	int neib_dist = neib_pnt->dist_f_start;
	// �켱 front chain���� neighbor�� ���� ��ġ�� ã��
	while ((next_pnt = cur_pnt->post_pnt) != nullptr) {
		// chain�� �� ���� ���� ���� �ְ�
		if (neib_dist <= next_pnt->dist_f_start) {
			// �� �� ���� new_dist�� ª�ų� ������
			// �� neighbor���� �Ÿ��� chain�� current point�� next point���̿� ���� �� ������
			cur_pnt->post_pnt = neib_pnt;
			next_pnt->pre_pnt = neib_pnt;
			neib_pnt->pre_pnt = cur_pnt;
			neib_pnt->post_pnt = next_pnt;
			return;
		}
		else cur_pnt = next_pnt;
	}
	// chain�� �� �� ���� ū ��� chain ���� ����, 
	cur_pnt->post_pnt  = neib_pnt;
	neib_pnt->pre_pnt  = cur_pnt;
	neib_pnt->post_pnt = nullptr;
	return;
	}

// chage_front_chain()�� �̹� �̿��� front chain�� �ְ�
// �� path�� �� ª�� front chain ������ ���� �� ��
void change_front_chain(wor_pnt* neib_pnt) {
	// �켱 neib_pnt�� front chain���� ����
	neib_pnt->pre_pnt->post_pnt = neib_pnt->post_pnt;
	if (neib_pnt->post_pnt != nullptr) // front chain�� �L�� �ƴϸ�
		neib_pnt->post_pnt->pre_pnt = neib_pnt->pre_pnt;
	// front chain�� ������ ���� ã�� ����
	insert_front_chain(neib_pnt);
	return;
}

// find_way() algorithm��
// 
// ������� front chain�� �ְ�
// 
// front chain�� ��������� ���ͰŸ��� ���� ª�� ��(chain_start)���� ����
// �� �� �ִ� �������� ã��
// front chain�� �ø��������� sort�Ͽ� �ְ�
// (���ÿ� plc2pnt[place index] w_pnt[]�� �ּұ���)
// ������ chain_start���� in_f_chain�� false�� ó���� chain start�� ���� ������
// 
// front chain�� ù���� ������� ���� ���� �۾��� ����ϸ� �� ������
// 'ó������		(w_pnt[].in_f_chain == false)',
// 'front chain��	(w_pnt[].in_f_chain == true)' �׸���
// 'ó�� ����		(plc[place index] == nullptr)'�� �������� ���е�.
// 
// front chain�� ù��(�Ÿ��� ���� ª����)�� ������(end_i)�̸� �� algorithm�� ������
// ���routine�� ���۵�
// 
// �� �������� �� �� �ִ� �������� ã�� front chain�� ���� ��
// �� �� �ִ� ������ 'ó������'�� ���
// ���� ���� ���������� 'ó������' �������� �Ÿ���
// '���� ���Ǵ� �Ÿ�'���� ª�� �� �����Ƿ�
// ����(front_chain�� ���� �ʿ� ����) �ϰ�(���ȣ ����)
// 'ó�� ����'�� ��� front chain�� ��ġ�� ã�� ���� �־���ϰ�
// 'front chain��'�� ��� ���� ���Ǵ� �Ÿ���
// ���� ���� �Ÿ����� ª�� ���
// front chain���� �´� ��ġ ã�� ����
//

void find_way() {
	// front chain�� ù ���� index�� end_i�̸� ���� ã�� ��
	int s_ind; // front chain ù ����
	while ((s_ind = chain_start->plc_ind) != end_i) {
		// s_ind�� ����Ű�� �������� �� �� �ִ� ������ ����
		int ways_ind =			  plc[s_ind].w_start;
		int ways_end = ways_ind + plc[s_ind].w_nr;
		int cur_dist_f_start = chain_start->dist_f_start;
		if (debug) cout << plc[s_ind].name << " is top, dist " << cur_dist_f_start << endl;
		for (; ways_ind < ways_end; ways_ind++) {
			// neib_ind�� ind�� ���� �� �� �ִ� ��
			int			neib_ind		 = ways[ways_ind].neibor;
			int			new_dist_f_start = ways[ways_ind].dist + cur_dist_f_start;
			wor_pnt*	neib_pnt		 = plc2pnt[neib_ind];
			if (neib_pnt == nullptr) { // not checked(means 'not_touched' in project4), use new wor_pnt
				wor_pnt* temp_p = &w_pnt[used_pnt++]; // w_pnt �ϳ� �� ���
				plc2pnt[neib_ind]    = temp_p;
				temp_p->plc_ind      = neib_ind;
				temp_p->come_from    = s_ind;
				temp_p->in_f_chain   = true;
				temp_p->dist_f_start = new_dist_f_start;
				insert_front_chain(temp_p);
				if (debug) cout << " new " << plc[neib_ind].name << " is neighbor " << new_dist_f_start << endl;
			}
			else
			if (neib_pnt->in_f_chain) { // �̹� neib pnt�� front chain�� �ְ�
				if (neib_pnt->dist_f_start > new_dist_f_start) { // �� �Ÿ��� ª����
					neib_pnt->dist_f_start = new_dist_f_start;
					neib_pnt->come_from	   = s_ind;
					change_front_chain(neib_pnt);
					if (debug) cout << " new " << plc[neib_ind].name << " is neighbor " << new_dist_f_start << endl;
				}
			}
			
		}
		// s_ind ���� ó�� �Ǿ����Ƿ�
		// front chain���� ����
		chain_start->in_f_chain = false;
		if (debug) cout << " del " << plc[chain_start->plc_ind].name << endl;
		chain_start = chain_start->post_pnt;
	}
}

void disp_way() {
	// �켱 wor_pnt�ȿ� come_from�� ���κ��� �Դ��� ǥ�� �ϹǷ�
	// start_i�� ���� ����Ϸ��� ������ �� �ٲ���� ��
	wor_pnt* son	= plc2pnt[end_i];
	wor_pnt* father	= plc2pnt[son->come_from];
	son->go_to		= end_i;
	while (father != son) {
		father->go_to = son->plc_ind;
		son = father;
		father = plc2pnt[son->come_from];
	}
	// ���� ���� start_i�� ���� ���
	if (start_i == end_i) cout << "������� ������ �����ϴ�." << endl;
	else {
		int index = start_i;
		cout << "��� �� : " << plc[index].name << "\n";
		index = plc2pnt[index]->go_to;
		while (index != end_i) {
			cout << plc[index].name << "\t" << plc2pnt[index]->dist_f_start << "m\n";
			index = plc2pnt[index]->go_to;
		}
		cout << "����  " << plc[index].name << " ���� �Ÿ��� " << plc2pnt[index]->dist_f_start << "m �Դϴ�.\n";
	}
}

int main() {
	unsigned long time_s = timeGetTime();
	unsigned long time_e;
	int counter = 100;
	string start_str, end_str; // ���� data, ���� �� ����
	if (debug) time_s = timeGetTime();
	init_plc2pnt();
	while (true) {
		cout << "������� �Է��ϼ���." << endl;
		if (debug) start_str = "NW01";
		else
			cin >> start_str;
		start_i = find_index_in_names(start_str);
		if (debug) cout << start_str << start_i << endl;
		if (start_i < plc_max) {
			while (true) {
				cout << "�������� �Է��ϼ���.\n";
				if (debug) end_str = "Cir07";
				else
					cin >> end_str;
				end_i = find_index_in_names(end_str);
				if (debug) cout << end_str << end_i << endl;
				if (end_i < plc_max) {
					plc_init();
					find_way();
					disp_way();
					break; // �ι�° while�� ���� break
				}
				else {
					cout << "�������� �� á�����ϴ�.\n";
					break;
				}
			}
		}
		else {
			cout << "������� �� á�����ϴ�.\n";
		}
		cout << "��� �ұ��(Y/N).\n";
		if (debug) {
			if (--counter == 0) {
				time_e = timeGetTime();
				cout << time_e - time_s << "ms �ɷǽ��ϴ�\n";
				start_str[0] = 'N';
			}
			else {
				cout << counter << endl;
				start_str[0] = 'Y';
			}
		}
		else
			cin >> start_str;
		if (start_str[0] == 'N') break; // ù��° while�� ���� break
		if (start_str[0] == 'n') break; // ù��° while�� ���� break
	}
	return 0;
}