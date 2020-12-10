#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cash[3]={0};
        for(int i = 0; i<bills.size();i++){
            if (bills[i]==5){
                cash[0]++;
            }
            else if(bills[i]==10){
                cash[1]++;
                if(cash[0])
                    cash[0]--;
                else
                    return false;
            }
            else
            {
                cash[2]++;
                if(cash[1]){
                    cash[1]--;
                    if(cash[0])
                        cash[0]--;
                    else
                        return false;
                }
                else{
                    if(cash[0]>=3)
                        cash[0]-=3;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};
int main(){
    vector<int>A={5,5,10,10,20};
    Solution s;
    cout<<s.lemonadeChange(A);
    return 0;
}