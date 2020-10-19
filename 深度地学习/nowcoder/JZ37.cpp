#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
     int GetNumberOfK(vector<int> data ,int k) {
         return biSearch(data, k+0.5) - biSearch(data, k-0.5) ;
    }
private:
    int biSearch(const vector<int> & data, double num){
        int s = 0, e = data.size()-1;
        while(s <= e){
            int mid = (e - s)/2 + s;
            if(data[mid] < num)
                s = mid + 1;
            else if(data[mid] > num)
                e = mid - 1;
        }
        return s;
    }
};
int main(){
    vector<int> data={1,1,3,3,4,5,6,6,7,8,8,8,10};
    Solution s;
    cout<<s.GetNumberOfK(data,3);
    return 0;
}