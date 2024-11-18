#include <iostream>
#include <string>
#include <list>

using namespace std;

template<class T>
class LLStack {
public:
	LLStack() {}
	void clear() {
		lst.clear();
	}
	bool isEmpty() const {
		return lst.empty();
	}
	T& topEL() {
		return lst.back();
	}
	T pop() {
		T el = lst.back();
		lst.pop_back();
		return el;
	}
	void push(const T& el) {
		lst.push_back(el);
	}
private:
	list<T> lst;
};

int main(void) {
	LLStack<int> stack1;
	LLStack<int> stack2;
	LLStack<int> result;
	string a, b;
	int ten = 0;

	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		stack1.push(a[i] - '0');
	}
	
	cin >> b;
	 for (int i = 0; i < b.size(); i++) {
		stack2.push(b[i] - '0');
	} 

	for (int i = 0; ; i++) {
		int num = 0;
		if (stack1.isEmpty() && stack2.isEmpty()) {
			result.push(ten);
			break;
		}
		else if (stack1.isEmpty()) num = stack2.pop() + ten;
		else if (stack2.isEmpty()) num = stack1.pop() + ten;
		else num = stack1.pop() + stack2.pop() + ten;
		result.push(num % 10);
		ten = num / 10;
	} 

	for (int i = 0; ; i++) {
		if (result.isEmpty()) break;
		cout << result.pop();
	}
}