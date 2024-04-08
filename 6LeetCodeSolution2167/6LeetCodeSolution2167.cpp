#include <string>
#include <iostream>
#include <vector>

using namespace std;

//这个双指针还是有问题，还得是DP
//class Solution {
//public:
//    int minimumTime(string s) {
//        int i = 0;
//        int num = 0;
//        int j = s.length() - 1;
//        for (; i < j;) {
//            if (s[i] == '0') {
//                if (i+1 < j)
//                    break;
//                i += 1;
//                if (s[i] == '1') {
//                    num += 2;
//                    i += 1;
//                    continue;
//                }
//            }
//            else {
//                num += 1;
//                i += 1;
//            }
//        }
//        for (; i < j;) {
//            if (s[j] == '0') {
//                if (i < j-1)
//                    break;
//                j -= 1;
//                if (s[j] == '1') {
//                    num += 2;
//                    j -= 1;
//                    continue;
//                }
//            }
//            else {
//                num += 1;
//                j -= 1;
//            }
//        }
//        if (i == j) {
//            if (s[i] == '0')
//                return num;
//            else
//                return num + 1;
//        }
//        for (; i < j;) {
//            if (s[i] == '1')
//                num += 2;
//            i += 1;
//        }
//        return num;
//    }
//};
//还得是大佬 灵茶山艾府
//class Solution {
//public:
//    int minimumTime(string s) {
//        int n = s.length();
//        vector<int> suf(n + 1);
//        for (int i = n - 1; i >= 0; --i)
//            suf[i] = s[i] == '0' ? suf[i + 1] : min(suf[i + 1] + 2, n - i);
//        int ans = suf[0], pre = 0;
//        for (int i = 0; i < n; ++i)
//            if (s[i] == '1') {
//                pre = min(pre + 2, i + 1);
//                ans = min(ans, pre + suf[i + 1]);
//            }
//        return ans;
//    }
//};
//大佬 灵茶山艾府 给出的优化版本
class Solution {
public:
    int minimumTime(string s) {
        int n = s.length(), ans = n, pre = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') pre = min(pre + 2, i + 1);
            ans = min(ans, pre + n - 1 - i);
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution result;
    cout << "test 1: 1100101, expect:5, output: ";
    cout << result.minimumTime("1100101") << endl;
    cout << "test2: 010110, expect:5, output: ";
    cout << result.minimumTime("010110") << endl;
    return 0;
};