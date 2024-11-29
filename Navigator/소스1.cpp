#include <iostream>

using namespace std;

// �������� ��Ī, 77 place�� ����
const int place_max = 77;
const string names[] = {	// place_max entries
	"Cir01",	"Cir02",	"Cir03",	"Cir04",	"Cir05",	"Cir06",	"Cir07",	"Cir08",
	"Cir09",	"Cir10",	"Cir11",	"Cir12",	"Cir13",										// 13
	"NE01",		"NE02",		"NE03",		"NE04",		"NE05",		"NE06",		"NE07",		"NE08",
	"NE09",		"NE10",		"NE11",		"NE12",		"NE13",		"NE14",								// 14
	"NW01",		"NW02",		"NW03",		"NW04",		"NW05",		"NW06",		"NW07",		"NW08",
	"NW09",		"NW10",		"NW11",		"NW12",		"NW13",		"NW14",								// 14
	"SE01",		"SE02",		"SE03",		"SE04",		"SE05",		"SE06",		"SE07",		"SE08",
	"SE09",		"SE10",		"SE11",		"SE12",		"SE13",		"SE14",		"SE15",		"SE16",
	"SE17",		"SE18",		"SE19",																	// 19
	"SW01",		"SW02",		"SW03",		"SW04",		"SW05",		"SW06",		"SW07",		"SW08",
	"SW09",		"SW10",		"SW11",		"SW12",		"SW13",		"SW14",		"SW15",		"SW16",
	"SW17"																							// 17, total 77
};
// ������ ������ index
int start_i, end_i;
//
// names�ȿ��� 'str'�� index�� ã�� routine
// ���� �� place_max�� return
//
int find_index_in_names(const string str) {
	int start_ind = 0;
	int end_ind = place_max - 1;
	while (true) {
		int temp_ind = end_ind - start_ind; // temp_ind = ������ ���� - 1
		if (temp_ind == 0) {	// ������ �̸��� ���� �Ѱ�
			if (str == names[start_ind])	return start_ind;
			else							return place_max;
		}
		if (temp_ind == 1) {	// ������ �̸��� �ΰ�
			if (str == names[start_ind])	return start_ind;
			if (str == names[end_ind])		return end_ind;
			else							return place_max;
		}
		// ���� ����� 3�� �̻�
		temp_ind = start_ind + temp_ind / 2; // temp_ind = ���� �߰��� 
		if (str > names[temp_ind]) start_ind = temp_ind + 1;
		else                       end_ind = temp_ind;
	}
}

//
// �� ����(names[])���� �� �� �ִ� �������(names�� index) �׸��� �װ� ���� �Ÿ�(meter)��
// names list ������ ���� ���� �ʰ� ����(ways[]), 
// ���� �� ������ ����� ���� ways[]���� ���ϱ�����
// �� �Ʒ��ִ� name2ways �ʿ�
//
struct street {
	int next_place;
	int distance;
};
const street ways[] = {
	{	35,	157	},{	 1,	39	},{	21,	160	},					// "Cir01"���� �� �� �ִ� ��, 35(=="NW09") 157(�Ÿ�) ��� 3��
	{	 0,	41	},{	 2,	194	},{	 3,	205	},{	 6,	207	},		// "Cir02"���� �� �� �ִ� ��,  0(=="Cir01") ��� 4��
	{	 1,	188	},{	 6,	139	},{	 7,	135	},{	40,	84	},		// "Cir03"���� �� �� �ִ� ��,  1(=="Cir02") ��� 4��
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
	{	28,	145	},{	30,	52	},{	 3,	169	},
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
// ���� ways�� names�� ���� �������� �ʾұ⿡
// �� names[i]�� �ش��ϴ� ways�� �������� �� �� �ִ� ��(ways) ������ �ʿ�
// 
// name2ways��
// names�� index�� �ش��ϴ� ���� ways���� ã������ ����index �� ������ �˷��ִ� data
//
// ���� names[2]("Cir03")���� �� �� �ִ� ����
// name2way[2]�� {7,4}�̹Ƿ�(�Ʒ��� ������)  Cir03(index 2)�� �ش��ϴ� ways data��
//    ways[name2ways[2].w_start], �� ways[7]���� ������
//         name2ways[2].w_length, �� 4�� ���� ways[7], ways[8], ways[9], ways[10]
//

struct name_street {
	int w_start;
	int w_length;
};
const name_street name2ways[] = {
	{  0,3	},	{  3,4	},	{  7,4	},	{ 11,4	},	{ 15,3	},	{ 18,4	},	{ 22,8	},	{ 30,4	},
	{ 34,3	},	{ 37,4	},	{ 41,4	},	{ 45,4	},	{ 49,3	},	{ 52,3	},	{ 55,3	},	{ 58,3	},
	{ 61,4	},	{ 65,3	},	{ 68,3	},	{ 71,5	},	{ 76,3	},	{ 79,4	},	{ 83,4	},	{ 87,3	},
	{ 90,3	},	{ 93,4	},	{ 97,4	},	{101,3	},	{104,3	},	{107,3	},	{110,4	},	{114,3	},
	{117,3	},	{120,5	},	{125,3	},	{128,4	},	{132,5	},	{137,3	},	{140,3	},	{143,3	},
	{146,4	},	{150,3	},	{153,4	},	{157,3	},	{160,4	},	{164,4	},	{168,4	},	{172,4	},
	{176,3	},	{179,3	},	{182,3	},	{185,3	},	{188,3	},	{191,4	},	{195,4	},	{199,3	},
	{202,4	},	{206,3	},	{209,3	},	{212,3	},	{215,3	},	{218,3	},	{221,3	},	{224,4	},
	{228,4	},	{232,4	},	{236,5	},	{241,3	},	{244,3	},	{247,3	},	{250,4	},	{254,3	},
	{257,5	},	{262,3	},	{265,3	},	{268,3	},	{271,3	}
};

//
// �����ϸ�
//
// const int		place_max,	������ 77
// const string		names[],	���� �̸�
//
// struct street {next_place<int>, distance<int in meter>}
// const  street ways[], names�� ���� ������ (�̿�,�Ÿ�)list
// 
// struct name_street {int w_start;int w_length}
// const  name_street name2ways[], names index�� ways�� ���� ��
//
// ���� data�� ���¿� ���� �ٲ� Ȯ���� �����Ƿ�(���� ways.distance�� '�Ÿ�'���� �ƴ϶�
// ���� ���¿� ���� �ٲ�� ���� coast�� �� �� ����) const�� ���� ��
//

//
// ���� navigation algorithm��
// 
// �������� ���������Ͽ�
// 
// �� �� �ִ� �������� ã��
// front chain�� �ø��������� sort�Ͽ� �ְ� �������� 'ó������(touched)'���� �����ϰ�
// front chain�� ������ 'front chain��(in_front_chain)'���� ǥ����.
// 
// front chain�� ù���� ������� ���� ���� �۾��� ����ϸ� �� ������
// 'ó������', 'front chain��' �׸��� 'ó�� ����(not_touched)' ��
// �������� �����ϴ� ����(touched, ���� ���� �κ�), �������� ���(in_front_chain)
// �׸��� ���� ó�� ������(not_touched)���� �������� ���е�.
// 
// front chain�� ù��(�Ÿ��� ���� ª����)�� �������̸� �� algorithm�� ������
// 
// ���routine�� ���۵�
// 
// �� �������� �� �� �ִ� �������� ã�� front chain�� ���� ��
// �� �� �ִ� ������ 'touched'�� ���
// ���� ���� '���������� touched �������� �Ÿ�'��
// '���� ���Ǵ� �Ÿ�'���� ª�� �� �����Ƿ�
// ����(front_chain�� ���� �ʿ� ����) �ϰ�(���ȣ ����)
// 'not_touched'�� ��� front_chain�� ��ġ�� ã�� ���� �־���ϰ�
// 'in_front_chain'�� ��� ���� ���Ǵ� �Ÿ���
// ���� ���� �Ÿ��� ª�� ���
// front chain���� ���� ��
// ���� ���Ǵ� �Ÿ��� ���� front chain�� ����
//

//
// �׿� �ʿ��� data
//
enum   p_state {
	not_touched,	// place�� ó�� ���� �ʾ��� 
	in_front_chain,// place�� front chain�� ����
	touched
};		// place�� ó�� ����
struct p_data {
	p_state p_stat;			// status
	int		come_from;		// ��� �������� �Գ�, navi ��½� �ʿ�
	int		pre_chain;		// front chain���� ��
	int		post_chain;		// front chain���� ��
	int		dist_f_start;	// ���������� ���� �Ÿ�
};
p_data	plc[place_max]{};
p_data	chain_start;	// front chain�� ����, dummy struct p_data, only post_chain used

//
// const int		place_max,	������ 77
// const string		names[],	���� �̸�
//
// struct street {next_place<int>, distance<int in meter>}
// const  street ways[], names�� ���� ������ (�̿�,�Ÿ�)list
// 
// struct name_street {int w_start;int w_length}
// const  name_street name2ways[], names index�� ways�� ���� ��
//
// enum   p_state	{ not_touched, in_front_chain, touched };
// struct p_data	{ p_state p_stat;	int come_from; int	pre_chain; int post_chain; int	dist_f_start;};
// p_data plc [place_max], chain_start;
//
void plc_init() {
	for (int i = 0; i < place_max; i++) {
		plc[i].p_stat = not_touched;
		// plc[i].come_from = i;
		// plc[i].pre_chain = i;
		// plc[i].post_chain = i;
		// plc[i].dist_f_start = 0;
	}
	chain_start.post_chain = start_i;
	//
	plc[start_i].p_stat = in_front_chain;
	plc[start_i].come_from = start_i;
	plc[start_i].pre_chain = start_i;
	plc[start_i].post_chain = start_i;
	plc[start_i].dist_f_start = 0;
}

void insert_front_chain(int ind, int neighbor_ind, int new_dist_f_start) {
	int post_ind;
	while(post_ind = plc[ind].post_chain != ind) {
		if (new_dist_f_start <= plc[post_ind].dist_f_start) {
			// insert neighbor btw. post_ind and ind
			plc[neighbor_ind].pre_chain = ind;
			plc[neighbor_ind].post_chain = post_ind;
			plc[ind].post_chain = neighbor_ind;
			plc[post_ind].pre_chain = neighbor_ind;
			return;
		}
		ind = post_ind; // next in front chain
	}
	// front chain �� �� ���� ū ��� ���� ����
	plc[ind].post_chain = neighbor_ind;
	plc[neighbor_ind].post_chain = neighbor_ind;
	plc[neighbor_ind].pre_chain = ind;
	return;
}

void find_way() {
	// ind�� ó���ؾ� �� front chain�� ù ���� index
	// ind�� end_i�̸� ���� ã�� ��
	while (int ind = chain_start.post_chain != end_i) {
		// ind�� ����Ű�� �������� �� �� �ִ� ������ ����
		int ways_ind = name2ways[ind].w_start;
		int ways_end = name2ways[ind].w_length + ways_ind;
		int cur_dist_f_start = plc[ind].dist_f_start;
		for (; ways_ind < ways_end; ways_ind++) {
			// neighbor_ind�� ind�� ���� �� �� �ִ� ��
			int neighbor_ind = ways[ways_ind].next_place;
			int new_dist_f_start = ways[ways_ind].distance + cur_dist_f_start;
			// n_i_ptr neighbor_ind data�� ����Ű�� pointer
			p_data* n_i_ptr = &(plc[neighbor_ind]);
			p_state p_st;
			if ((p_st = n_i_ptr->p_stat) != touched) {
				// in_front_chain �Ǵ� not_touched
				if (p_st == not_touched) {
					n_i_ptr->p_stat = in_front_chain;
					n_i_ptr->come_from = ind;
					n_i_ptr->dist_f_start = new_dist_f_start;
					// insert neighbor_ind to front chain
					insert_front_chain(ind, neighbor_ind, new_dist_f_start);
				}
				else {
					// neighbor�� �̹� front chain�� ����
					if (new_dist_f_start < n_i_ptr->dist_f_start) {
						// ���ο� ���� �� ª���Ƿ� caine �� ������ ����
						int temp = n_i_ptr->pre_chain;
						if (n_i_ptr->post_chain == neighbor_ind) { // chain�� ���� ���� ��
							plc[temp].post_chain = temp;
						}
						else { // chain �߰�
							int temp2 = n_i_ptr->post_chain;
							plc[temp].post_chain = temp2;
							plc[temp2].pre_chain = temp;
						}
						// �� data�� chain�� ����
						n_i_ptr->come_from = ind;
						n_i_ptr->dist_f_start = new_dist_f_start;
						// insert neighbor_ind to front chain
						insert_front_chain(ind, neighbor_ind, new_dist_f_start);
					}
				}
			}
		}
	}
}

void disp_way() {
	// p_data plc�ȿ� come_from�� ������ start_i�� ����
	// ����Ϸ��� ������ �� �ٲ�� ��
	int father				= plc[end_i].come_from;
	int grand_father		= plc[father].come_from;
	int son					= end_i;
	plc[end_i].come_from	= end_i;
	while (father != son) {
		int temp = grand_father;
		plc[father].come_from = son;
		son = father;
		father = grand_father;
		grand_father = plc[temp].come_from;
	}
	if (start_i == end_i) cout << "������� ������ �����ϴ�." << endl;
	else {
		int index = start_i;
		cout << "��� �� : " << names[index] << "\n";
		index = plc[index].come_from;
		int next = plc[index].come_from;
		while (index != end_i) {
			cout << names[index] << "\t" << plc[index].dist_f_start << "m\n";
			index++;
		}
		cout << "����  " << names[index] << " ���� �Ÿ��� " << plc[index].dist_f_start << "m �Դϴ�.\n";
	}
}

int main() {
	string start_str, end_str; // ���� data, ���� �� ����
	while (true) {
		cout << "������� �Է��ϼ���." << endl;
		cin >> start_str;
		start_i = find_index_in_names(start_str);
		if (start_i < place_max) {
			while (true) {
				cout << "�������� �Է��ϼ���.\n";
				cin >> end_str;
				end_i = find_index_in_names(end_str);
				if (end_i < place_max) {
					find_way();
					disp_way();
					break; // �ι�° while�� ���� break
				}
			}
		}
		cout << "��� �ұ��(Y/N).\n";
		cin >> start_str;
		if (start_str[0] == 'N') break; // ù��° while�� ���� break
		if (start_str[0] == 'n') break; // ù��° while�� ���� break
	}
	return 0;
}