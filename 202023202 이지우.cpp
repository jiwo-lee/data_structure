#include<iostream>
using namespace std;

class BaseClass {
public:
	void f(const char *s = "unknown") {
		cout << "Function f() in BaseClass called from " << s << endl;
	}
protected:
	void g(const char *s = "unknown") {
		cout << "Function g() in BassClass called from " << s << endl;
	}
private:
	void h(const char *s = "unknown") {
		cout << "Function h() in BaseClass\n";
	}
};

class Derived1Lavel1 : public virtual BaseClass {
public: 
	void f(const char *s = "unknown") {
		cout << "Function f() in BassClass called from " << s << endl;
		g("Derived1Level1");
		h("Derived1Level1");
	}
	void h (const char* s = "unknown") {
		cout << "Function h() in BassClass called from " << s << endl;
	}
};

int main() {
	Derived1Lavel1 test;
	test.f("main");
	test.h("main");
}