#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        // 统计次数
        int count = 0;
        for(int i = 1; i <= n; i *= 10){
            // 计算高位和低位
            int a = n / i, b = n % i;
            count += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
        }
        return count;
    
    }
};
int main(){
    Solution s;
    int re=s.NumberOf1Between1AndN_Solution(13);
    cout<<re;
    return 0;
}