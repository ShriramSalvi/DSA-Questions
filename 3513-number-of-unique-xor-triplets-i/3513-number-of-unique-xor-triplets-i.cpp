class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        if(nums.size()==1)return 1;
        if(nums.size()==2)return 2;  
        int max = *max_element(nums.begin(),nums.end());
        
        int count=0;

        while(max){
            max/=2;
            count++;
        }
     
     return  pow(2,count);
    }
};