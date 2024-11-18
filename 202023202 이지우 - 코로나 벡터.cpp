#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct c_info {
	string country;
	int confirm;
	int dead;
	double dead_rate = ((double)dead / confirm) * 100; // 사망률은 계산 가능하므로 입력받지 않아도 됨.
}CINFO; //typedef은 구조체의 별칭을 지어줘 별칭만으로 변수 선언이 가능케 함. c++에선 없어도 되지만 c와의 호환성을 위해 쓰는것이 좋음.

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
	void print_info(int option); // 1이면 국가명 순, 2면 확진자 순, 3이면 사망자 순, 4면 사망률 순.

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
			cout << m_data[i].country << ": " << m_data[i].confirm << "명 확진, " << m_data[i].dead << "명 사망, 사망률은 " << m_data[i].dead_rate <<"%" << endl;
		}
		break;
	case 2:
		sort(m_data.begin(), m_data.end(), cmpConfirm);
		for (int i = 0; i < m_data.size(); i++) {
			cout << m_data[i].country << ": " << m_data[i].confirm << "명 확진, " << m_data[i].dead << "명 사망, 사망률은 " << m_data[i].dead_rate << "%" << endl;
		}
		break;
	case 3:
		sort(m_data.begin(), m_data.end(), cmpDead);
		for (int i = 0; i < m_data.size(); i++) {
			cout << m_data[i].country << ": " << m_data[i].confirm << "명 확진, " << m_data[i].dead << "명 사망, 사망률은 " << m_data[i].dead_rate << "%" << endl;
		}
		break;
	case 4:
		sort(m_data.begin(), m_data.end(), cmpDeadper);
		for (int i = 0; i < m_data.size(); i++) {
			cout << m_data[i].country << ": " << m_data[i].confirm << "명 확진, " << m_data[i].dead << "명 사망, 사망률은 " << m_data[i].dead_rate << "%" << endl;
		}
		break;
	default:
		cout << "잘못 입력하셨습니다." << endl;
		break;
	}
}

int main() {
	cout << fixed;
	cout.precision(2);
	//소수점 아래 2자릿수까지만 출력되게 함.

	CINFO Default_DATA1 = { "USA", 31000000, 560000 };
	CINFO Default_DATA2 = { "Brazil", 13200000, 341000 };
	CINFO Default_DATA3 = { "India", 12900000, 167000 };
	CINFO Default_DATA4 = { "France", 4940000, 98065 };
	CINFO Default_DATA5 = { "Russia", 4550000, 99800 };
	CINFO Default_DATA6 = { "United Kingdom", 4370000, 127000 };
	CINFO Default_DATA7 = { "Italy", 3700000, 112000 };
	CINFO Default_DATA8 = { "Turkey", 3690000, 33201 };
	//기본으로 넣을 데이터 8개를 구조체 형태로 만듦.

	vector<CINFO> Corona_vector;
	Corona_vector.push_back(Default_DATA1);
	Corona_vector.push_back(Default_DATA2);
	Corona_vector.push_back(Default_DATA3);
	Corona_vector.push_back(Default_DATA4);
	Corona_vector.push_back(Default_DATA5);
	Corona_vector.push_back(Default_DATA6);
	Corona_vector.push_back(Default_DATA7);
	Corona_vector.push_back(Default_DATA8);
	//위에서 구조체로 만든것을 벡터에 집어넣음.

	Corona_World Co_Nation(Corona_vector);
	//Co_Nation 객체 생성, 위의 벡터를 넣어 객체 내의 m_data 벡터에 들어감.

	int select1;
	int select2;
	int select3;
	int select4;
	string insertcountry;
	int insertconfirm;
	int insertdead;
	string deletecountry;

	cout << "COVID19 전세계 확진 현황판입니다." << endl;
	
	while (true) {
		cout << "무엇을 하시겠습니까?" << endl;
		cout << "리스트 보기: 1 / 리스트 관리: 2" << endl;
		cout << "입력: ";
		cin >> select1;

		if (select1 == 1) {
			cout << "국가명 순: 1 / 확진자 순: 2 / 사망자 순: 3 / 사망률 순: 4" << endl;
			cout << "입력: ";
			cin >> select2;
			
			Co_Nation.print_info(select2);
		}
		else if (select1 == 2) {
			cout << "리스트 추가: 1 / 리스트 삭제: 2" << endl;
			cout << "입력: ";
			cin >> select3;
			
			if (select3 == 1) {
				cout << "국가명을 입력해주세요: ";
				cin >> insertcountry;
				cout << "확진자 수를 입력해주세요:";
				cin >> insertconfirm;
				cout << "사망자 수를 입력해주세요: ";
				cin >> insertdead;

				CINFO Insert_DATA = {insertcountry, insertconfirm, insertdead};
				Co_Nation.insert_data(Insert_DATA);
				//구조체를 바로 객체의 함수를 통해 객체의 m_data에 집어넣음
			}
			else if (select3 == 2) {
				cout << "삭제하고자 하는 데이터의 국가명을 입력해주세요: ";
				cin >> deletecountry;

				Co_Nation.delete_data(deletecountry);
			}
			else {
				cout << "잘못 입력하셨습니다." << endl;
			}
		}
		else {
			cout << "잘못 입력하셨습니다." << endl;
		}

		cout << "\n" << endl;

		cout << "계속 하시겠습니까?" << endl;
		cout << "프로그램을 종료하려면 1번을, 계속 실행하려면 아무 숫자나 눌러주세요." << endl;
		cout << "입력: ";
		cin >> select4;
		if (select4 == 1)
			break;

		cout << "\n\n" << endl;
	}

	return 0;
}