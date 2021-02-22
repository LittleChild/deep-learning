#include<iostream>
#include<deque>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ret;
    if (nums.size() == 0) return ret;
    deque<int> q;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!q.empty() && nums[q.back()] < nums[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        if (k == i - q.front())
        {
            q.pop_front();
        }
        if (i >= k - 1)
        {
            ret.push_back(nums[q.front()]);
        }
 
    }
    return ret;
}
};

int main(){

}