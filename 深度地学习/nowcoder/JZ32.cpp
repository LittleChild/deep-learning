#include<iostream>
#include<vector>
#include <string>
using namespace std;
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string re = "";
        int l = numbers.size();
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                if (biger(numbers[i], numbers[j])) {
                    int t = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = t;
                }
            }
            re += to_string(numbers[i]);
        }
        return re;
    }
    bool biger(int a, int b) {
        int abit = 1, bbit = 1;
        int m=a, n=b;
        while (m /= 10) {
            abit*=10;
        }
        while (n /= 10)
        {
            bbit*=10;
        }
        while (abit || bbit) {
            if (abit != 0) {
                m = a / abit;
                a %= abit;
                abit /= 10;
            }
               
            if (bbit != 0) {
                n = b / bbit;
                b %= bbit;
                bbit /= 10;
            }
            if (m>n)
                return true;
        }
        return false;
    }
};
int main() {
    vector<int>nums = { 3,32,321 };
    Solution s;
    string re=s.PrintMinNumber(nums);
    cout<<re;
    //int b = s.biger(123, 12);
    //cout << b;
    return 0;

}