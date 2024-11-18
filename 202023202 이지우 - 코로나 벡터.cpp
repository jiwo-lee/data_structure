#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct c_info {
	string country;
	int confirm;
	int dead;
	double dead_rate = ((double)dead / confirm) * 100; // ������� ��� �����ϹǷ� �Է¹��� �ʾƵ� ��.
}CINFO; //typedef�� ����ü�� ��Ī�� ������ ��Ī������ ���� ������ ������ ��. c++���� ��� ������ c���� ȣȯ���� ���� ���°��� ����.

class Corona_World {
public:
	Corona_World() {};
	Corona_World(const CINFO& input) {
		insert_data(input);
	};
	Corona_World(const vector<CINFO>& input_list) {
		m_data = input_list;
	};

	~Corona_World() {};

	bool insert_data(const CINFO&input);
	bool delete_data(string name);
	void print_info(int option); // 1�̸� ������ ��, 2�� Ȯ���� ��, 3�̸� ����� ��, 4�� ����� ��.

private:
	vector<CINFO> m_data;

	friend bool cmpConfirm(const CINFO& a, const CINFO& b);
	friend bool cmpDead(const CINFO& a, const CINFO& b);
	friend bool cmpDeadper(const CINFO& a, const CINFO& b);
	friend bool cmpCountry(const CINFO& a, const CINFO& b);
};

bool cmpConfirm(const CINFO& a, const CINFO& b) {
	return a.confirm > b.confirm;
}
bool cmpDead(const CINFO& a, const CINFO& b) {
	return a.dead > b.dead;
}
bool cmpDeadper(const CINFO& a, const CINFO& b) {
	return a.dead_rate > b.dead_rate;
}
bool cmpCountry(const CINFO& a, const CINFO& b) {
	return a.country < b.country;
}

bool Corona_World::insert_data(const CINFO& input) {
	m_data.push_back(input);
	return true;
}

bool Corona_World::delete_data(string name) {
	for (int i = 0; i < m_data.size(); i++) {
		if (m_data[i].country == name) {
			m_data.erase(m_data.begin() + i);
		}
	}
	return true;
}

void Corona_World::print_info(int option) {
	switch (option) {
	case 1:
		sort(m_data.begin(), m_data.end(), cmpCountry);
		for (int i = 0; i < m_data.size(); i++) {
			cout << m_data[i].country << ": " << m_data[i].confirm << "�� Ȯ��, " << m_data[i].dead << "�� ���, ������� " << m_data[i].dead_rate <<"%" << endl;
		}
		break;
	case 2:
		sort(m_data.begin(), m_data.end(), cmpConfirm);
		for (int i = 0; i < m_data.size(); i++) {
			cout << m_data[i].country << ": " << m_data[i].confirm << "�� Ȯ��, " << m_data[i].dead << "�� ���, ������� " << m_data[i].dead_rate << "%" << endl;
		}
		break;
	case 3:
		sort(m_data.begin(), m_data.end(), cmpDead);
		for (int i = 0; i < m_data.size(); i++) {
			cout << m_data[i].country << ": " << m_data[i].confirm << "�� Ȯ��, " << m_data[i].dead << "�� ���, ������� " << m_data[i].dead_rate << "%" << endl;
		}
		break;
	case 4:
		sort(m_data.begin(), m_data.end(), cmpDeadper);
		for (int i = 0; i < m_data.size(); i++) {
			cout << m_data[i].country << ": " << m_data[i].confirm << "�� Ȯ��, " << m_data[i].dead << "�� ���, ������� " << m_data[i].dead_rate << "%" << endl;
		}
		break;
	default:
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		break;
	}
}

int main() {
	cout << fixed;
	cout.precision(2);
	//�Ҽ��� �Ʒ� 2�ڸ��������� ��µǰ� ��.

	CINFO Default_DATA1 = { "USA", 31000000, 560000 };
	CINFO Default_DATA2 = { "Brazil", 13200000, 341000 };
	CINFO Default_DATA3 = { "India", 12900000, 167000 };
	CINFO Default_DATA4 = { "France", 4940000, 98065 };
	CINFO Default_DATA5 = { "Russia", 4550000, 99800 };
	CINFO Default_DATA6 = { "United Kingdom", 4370000, 127000 };
	CINFO Default_DATA7 = { "Italy", 3700000, 112000 };
	CINFO Default_DATA8 = { "Turkey", 3690000, 33201 };
	//�⺻���� ���� ������ 8���� ����ü ���·� ����.

	vector<CINFO> Corona_vector;
	Corona_vector.push_back(Default_DATA1);
	Corona_vector.push_back(Default_DATA2);
	Corona_vector.push_back(Default_DATA3);
	Corona_vector.push_back(Default_DATA4);
	Corona_vector.push_back(Default_DATA5);
	Corona_vector.push_back(Default_DATA6);
	Corona_vector.push_back(Default_DATA7);
	Corona_vector.push_back(Default_DATA8);
	//������ ����ü�� ������� ���Ϳ� �������.

	Corona_World Co_Nation(Corona_vector);
	//Co_Nation ��ü ����, ���� ���͸� �־� ��ü ���� m_data ���Ϳ� ��.

	int select1;
	int select2;
	int select3;
	int select4;
	string insertcountry;
	int insertconfirm;
	int insertdead;
	string deletecountry;

	cout << "COVID19 ������ Ȯ�� ��Ȳ���Դϴ�." << endl;
	
	while (true) {
		cout << "������ �Ͻðڽ��ϱ�?" << endl;
		cout << "����Ʈ ����: 1 / ����Ʈ ����: 2" << endl;
		cout << "�Է�: ";
		cin >> select1;

		if (select1 == 1) {
			cout << "������ ��: 1 / Ȯ���� ��: 2 / ����� ��: 3 / ����� ��: 4" << endl;
			cout << "�Է�: ";
			cin >> select2;
			
			Co_Nation.print_info(select2);
		}
		else if (select1 == 2) {
			cout << "����Ʈ �߰�: 1 / ����Ʈ ����: 2" << endl;
			cout << "�Է�: ";
			cin >> select3;
			
			if (select3 == 1) {
				cout << "�������� �Է����ּ���: ";
				cin >> insertcountry;
				cout << "Ȯ���� ���� �Է����ּ���:";
				cin >> insertconfirm;
				cout << "����� ���� �Է����ּ���: ";
				cin >> insertdead;

				CINFO Insert_DATA = {insertcountry, insertconfirm, insertdead};
				Co_Nation.insert_data(Insert_DATA);
				//����ü�� �ٷ� ��ü�� �Լ��� ���� ��ü�� m_data�� �������
			}
			else if (select3 == 2) {
				cout << "�����ϰ��� �ϴ� �������� �������� �Է����ּ���: ";
				cin >> deletecountry;

				Co_Nation.delete_data(deletecountry);
			}
			else {
				cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			}
		}
		else {
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		}

		cout << "\n" << endl;

		cout << "��� �Ͻðڽ��ϱ�?" << endl;
		cout << "���α׷��� �����Ϸ��� 1����, ��� �����Ϸ��� �ƹ� ���ڳ� �����ּ���." << endl;
		cout << "�Է�: ";
		cin >> select4;
		if (select4 == 1)
			break;

		cout << "\n\n" << endl;
	}

	return 0;
}