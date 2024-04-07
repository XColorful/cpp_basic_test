#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unicode/unistr.h>  // ICU库的头文件
#include <unicode/ustream.h> // ICU库的头文件
#include <string>
#include <locale.h>

int RANDOM_NUMBER;
int TRY_TOTAL = 6;


using namespace icu;
// 使用ICU库的UnicodeString类来存储字符串
UnicodeString INPUT_PROMPT = UnicodeString::fromUTF8("请输入一个整数：");
UnicodeString MSG_LOW = UnicodeString::fromUTF8("Too low, ye scurvy dog!");
UnicodeString MSG_HIGH = UnicodeString::fromUTF8("Too high, landlubber!");
UnicodeString MSG_HELLO1 = UnicodeString::fromUTF8("AHOY! I'm the Dread Pirate Roberts, and I have a secret!\n");
UnicodeString MSG_HELLO2 = UnicodeString::fromUTF8("It is a number from 1 to 100. I'll give you 6 tries.\n");

using namespace std;
int inputCheck(string userInput) {
    for (char c : userInput) {
        if (!isdigit(c)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    using namespace std;
    using namespace icu;

    std::srand(std::time(0));
    RANDOM_NUMBER = std::rand() % 100 + 1;  // 生成随机数


    cout << MSG_HELLO1;
    cout << MSG_HELLO2;

    int tryLeft = TRY_TOTAL;
    int guessNum = 0;
    string userInput;

    while (guessNum != RANDOM_NUMBER && tryLeft > 0) {
        cout << "What's yer guess? (" << tryLeft << " left)" << endl;
        cin >> userInput;
        if (inputCheck(userInput)) {
            cout << INPUT_PROMPT; // 乱码
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        };

        if (guessNum < RANDOM_NUMBER) {
            cout << MSG_LOW;
        }
        else if (guessNum > RANDOM_NUMBER) {
            cout << MSG_HIGH;
        };
        tryLeft -= 1;
    }

    if (guessNum == RANDOM_NUMBER) {
        cout << "Avast! Ye got it! Found my secret, ye did!\n";
    }
    else {
        cout << "No more guesses! Better luck next time, matey!\n";
        cout << "The secret number was " << RANDOM_NUMBER << "\n";

    }
    cout << "Leave your last comment" << endl;
    cin >> guessNum;
    return 0;
}