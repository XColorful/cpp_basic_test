#include <string>
#include <iostream>
//#include <Windows.h> // 调用Windows API函数，修改当前进程的控制台输出
int main() {
	system("chcp 65001");
	//SetConsoleOutputCP(CP_UTF8); // 将当前进程的控制台输出改为uft-8
	using namespace std;
	string s2 = "中文2";
	cout << s2;
	
	return 0;
}
