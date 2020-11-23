#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x<10 && x>-10)
            return x;
        
        long long re=0;
        while (x)
        {
            int t=x%10;
            x=int(x/10);
            if(re*10+t>pow(2,31) || re*10+t<-1*pow(2,31))
                return 0;
            re=re*10+t;
            
        }
        return re;
        

    }
};

int main(){
    Solution s;
    cout<<s.reverse(1534236469);
    
    return 0;
}