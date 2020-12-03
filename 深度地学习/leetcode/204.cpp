#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        int re=0;
        if(n<=2)
            return 0;
        n--;
        while(n>1)
        {
            for(int i=2;i*i<=n;i++){
                if(n%i==0){
                    re--;
                    break;
                }
            }
            re++;
            n--;
        }
        return re;
        

    }
};
int main(){
    vector<int>A={2,2};
    Solution s;
    cout<<s.countPrimes(10);
    return 0;
}