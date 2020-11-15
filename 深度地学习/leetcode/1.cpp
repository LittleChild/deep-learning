#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    Solution s;
    vector<int>re;
    vector<int>nums={2,7,11,15};
    re=s.twoSum(nums,9);
    for(int i=0;i<re.size();i++){
        cout<<re[i]<<endl;
    }
    return 0;
}