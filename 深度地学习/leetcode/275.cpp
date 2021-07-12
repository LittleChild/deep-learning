class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        for(auto i:citations){
            if(i<n)
                n--;
            else
                break;
        }
        return n;
    }
};
