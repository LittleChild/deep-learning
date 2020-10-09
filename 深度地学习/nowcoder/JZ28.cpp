#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        




        return 0;
        // int l=numbers.size();
        // map<int,int>dic;
        // for(int i=0;i<l;i++){
        //     dic[numbers[i]]++;
        // }
        // map<int,int>::iterator it=dic.begin();
        // for(it;it!=dic.end();it++){
        //     if(it->second>(l/2))
        //         return it->first;
        // }
        // return 0;
    
    }
};
int main(){
    vector<int> numbers={1,2,3,2,2,2,5,4,2};
    Solution s;
    int re=s.MoreThanHalfNum_Solution(numbers);
    cout<<re;
    return 0;
}