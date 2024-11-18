#include <iostream>

using namespace std;

template<class T1, class T2>
class treapNode {
public:
	treapNode() {
		left = right = NULL;
	}
	treapNode(const T1& priority, const T2& name, treapNode<T1, T2>* l = NULL, treapNode<T1, T2>* r = NULL) {
		deathrate = priority;
		country = name;
		left = l;
		right = r;
	}
	T1 deathrate;
	T2 country;
	treapNode<T1, T2>* left, * right;
};

template<class T1, class T2>
class treap {
public:
	treap() {
		root = NULL;
	}
	~treap() {
		clear();
	}
	void clear() {
		clear(root);
	}
	void clear(treapNode<T1, T2>* p) {
		if(p->left != NULL) clear(p->left);
		if (p->right != NULL) clear(p->right);
		p = NULL;
	}
	bool isEmpty() const {
		return root == 0;
	}

	virtual void visit(treapNode<T1, T2>* p) {
		cout << p->country << ", " << p->deathrate << "%" << endl;
	}
	void inorder(treapNode<T1, T2>* p) {
		if (p != NULL) {
			inorder(p->left);
			visit(p);
			inorder(p->right);
		}
	}
	void search(const T2& name) {
		for (treapNode<T1, T2>* p = root; p != NULL; ) {
			if (name == p->country) {
				visit(p);
				break;
			}
			else if (p->left == NULL && p->right == NULL && name != p->country) {
				cout << "찾으시는 국가가 없습니다." << endl;
				break;
			}
			else if (name > p->country) p = p->right;
			else p = p->left;
		}
	}

	void insert(const T1& priority, const T2& el) {
		treapNode<T1, T2>* p = root, * prev = 0, * tmp = 0;
		while (p != 0) {
			prev = p;
			if (el < p->country) p = p->left;
			else p = p->right;
		}
		if (root == 0) root = new treapNode<T1, T2>(priority, el);
		else if (el < prev->country) prev->left = new treapNode<T1, T2>(priority, el);
		else prev->right = new treapNode<T1, T2>(priority, el);

		root = rotation(root);
	}

	void erase() {
		treapNode <T1, T2>* r = root;
		treapNode <T1, T2>* p = root;
		T2& s = r->country;
		root->deathrate = -INFINITY;
		while (true) {
			root = rotation(root);
			if (r->left == NULL && r->right == NULL) {
				
				break;
			}
		}

		for (treapNode<T1, T2>* p = root; p != NULL; ) {
			if (p->left != NULL && s == p->left->country) {
				p->left = NULL;
				r = NULL;
				break;
			}
			else if (p->right != NULL && s == p->right->country) {
				p->right = NULL;
				r = NULL;
				break;
			}
			else if (p->left != NULL && s < p->country) p = p->left;
			else p = p->right;
		}
	}

	treapNode<T1, T2>* rotation(treapNode<T1, T2>* p) {
		if (p->left != NULL) p->left = rotation(p->left);
		if (p->right != NULL) p->right = rotation(p->right);
		if (p->left != NULL && p->deathrate < p->left->deathrate) p = rotateLeft(p);
		if (p->right != NULL && p->deathrate < p->right->deathrate) p = rotateRight(p);
		return p;
	}
	treapNode<T1, T2>* rotateLeft(treapNode<T1, T2>* p) {
		treapNode<T1, T2>* l = p->left;
		treapNode<T1, T2>* x = p->left->right;
		l->right = p;
		p->left = x;
		p = l;
		return p;
	}
	treapNode<T1, T2>* rotateRight(treapNode<T1, T2>* p) {
		treapNode<T1, T2>* r = p->right;
		treapNode<T1, T2>* y = p->right->left;
		r->left = p;
		p->right = y;
		p = r;
		return p;
	}

	treapNode<T1, T2>* root;
};

int main() {
	treap<double, string> coronaNation;
	coronaNation.insert(1.8, "USA");
	coronaNation.insert(1.2, "India");
	coronaNation.insert(2.8, "Brazil");
	coronaNation.insert(1.9, "France");
	coronaNation.insert(0.9, "Turkey");
	coronaNation.insert(2.4, "Russia");
	coronaNation.insert(2.8, "UK");
	coronaNation.insert(3.0, "Italy");
	coronaNation.insert(2.1, "Argentina");
	coronaNation.insert(2.4, "Germany");

	int num;
	string name;
	double dNum;

	while (true) {
		cout << "코로나바이러스 감영증-19 사망률 현황판입니다." << endl;
		cout << "목록보기: 1, 값 찾기: 2, 값 삭제: 3, 값 추가: 4, 종료: 5" << endl;
		cin >> num;
		
		switch (num) {
		case 1:
			cout << "~목록(이름순)~" << endl;
			coronaNation.inorder(coronaNation.root);
			break;
		case 2:
			cout << "찾으려는 국가의 이름을 적어주세요: ";
			cin >> name;
			coronaNation.search(name);
			break;
		case 3:
			cout << "가장 사망률이 높은 국가를 없앱니다." << endl;
			coronaNation.erase();
			break;
		case 4:
			cout << "국가의 이름을 적어주세요: ";
			cin >> name;
			cout << "사망률을 적어주세요: ";
			cin >> dNum;
			coronaNation.insert(dNum, name);
			break;
		case 5:
			cout << "종료합니다." << endl;
			return 0;
		}
	}
}