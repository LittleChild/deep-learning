#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int l1=ring.length();
        int l2=key.length();
        int count=0;
        bool get=false;
        int it=0;
        for(int i=0;i<l2;i++){
            int left=0;
            int index=it;
            get=false;
            while (!get)
            {
                if(ring[index]==key[i]){
                    get=true;
                }
                else{
                    index++;
                    left++;
                    if(index>=l1)
                        index=0;
                }
            }
            // cout<<left<<endl;
            int right=0;
            int index2=it;
            get=false;
            while (!get)
            {
                if(ring[index2]==key[i]){
                    get=true;
                }
                else{
                    index2--;
                    right++;
                    if(index2<0)
                        index2=l1-1;
                }
            }
            if(right>left){
                it=index;
                count+=left;
            }
            else
            {
                it=index2;
                count+=right;
            }   
            // cout<<right<<endl;
            cout<<it<<endl;
        }
        return count+l2;
    }
};

int main(){
    Solution s;
    cout<<s.findRotateSteps("iotfo","fioot");
    return 0;
}