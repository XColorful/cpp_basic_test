#include <iostream>
#include <string>

using namespace std;

void valSize();
void arrayTest();
void structTest();
void pointerTest();
void newTest();
void classTest();
void tryTest();

int main(int argc, char* argv[]) {
	system("chcp 65001");
	valSize();
	arrayTest();
	structTest();
	pointerTest();
	newTest();
	classTest();
	tryTest();
}

void valSize() {
	cout << "short " << sizeof(short) << SHRT_MAX << "\n";
	cout << "int " << sizeof(int) << INT_MAX << "\n";
	cout << "long " << sizeof(long) << LONG_MAX << "\n";
	cout << "long long " << sizeof(long long) << LLONG_MAX << "\n";
	cout << "float " << sizeof(float) << "\n";
	cout << "double " << sizeof(double) << "\n";
	cout << "char " << sizeof(char) << "\n";
	cout << "string " << sizeof(string) << "\n";
	return;
}

void arrayTest() {
	int integers[] = { 1,2,3 };
	integers[2] = 4;
	for (int integer : integers) cout << integer;
	cout << endl;
	return;
}

void structTest() {
	struct inflatable {
		char name[20];
		float volume;
		double price;
	};
	inflatable bouquet = {
		"sunflowers", 0.20, 12.49
	};
	inflatable choice;
	cout << "bouquet: " << bouquet.name << " for $";
	cout << bouquet.price << endl;
	choice = bouquet;
	cout << "choice: " << choice.name << " for $";
	cout << choice.price << endl;

	struct word {
		char e[50];
		string c;
	};
	word eng1 = {
		"test-word", "中文"
	};
	cout << eng1.e << eng1.c;
	cout << endl;
	for (char cha : eng1.e) {
		cout << cha << " ";
	}
	cout << endl;
	union one4all {
		int int_val;
		long long_val;
		double double_val;
	};
	one4all pail;
	pail.int_val = 15;
	cout << pail.int_val << endl;
	pail.double_val = 1.38;
	cout << pail.int_val << endl; // 此时显示的不是原先的int_val
	cout << pail.double_val << endl;
	cout << pail.long_val << endl; // 此时也会错误识别
}

void pointerTest() {
	int updates = 6;
	int* p_updates;
	p_updates = &updates;
	cout << "Values: updates = " << updates;
	cout << ", *p_updates = " << *p_updates << endl;
	cout << "Addresses: &updates = " << &updates;
	cout << ", p_updates = " << p_updates << endl;
	int* testVal = &updates;
	cout << "Address: " << testVal << ", Value: " << *testVal << endl;
	*p_updates += 1;
	cout << "Now: " << updates << endl;
	return;
}

void newTest() {
	int* pt = new int;
	*pt = 1001;
	cout << "add: " << pt << ", val: " << *pt << endl;
	delete pt;
	double* p3 = new double[3];
	p3[0] = 0.2;
	cout << "p3[1]:" << p3[1] << endl; // 此时还未设置值，显示不正确
	return;
}

void classTest() {
	class word {
	//private: //可以显示地说明，也可以隐式
		std::string e;
		string c;
	public:
		string getPair();
		void convert(string e, string c) {
			return;
		}
		string convert(string eng) {
			e = eng;
			return e;
		}
	};
	return;
}

void tryTest() {
	try {
		int a = 1;
		int b = 0;
		//int c = a / b;
		throw runtime_error("Division by zero not allowed");
	}
	catch(...) {
		cout << "successfully catched!" << endl;
		return;
	}
	return;
}
