#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(map<int,int>::iterator it=m.begin;it!=m.end();it++){
            if(it->second>1)
                return false;
        }
        return true;
    }
};
int main(){
    return 0;
}