class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        
         

        unordered_map<int,int>mp;

        for(int i=0; i<digits.size();i++){
        for(int j=0; j<digits.size();j++){
         if(j==i)continue;
        for(int k=0; k<digits.size();k++){
            if(k==j || k==i)continue;

            int digit1=digits[i];
            int digit2 = digits[j];
            int digit3 = digits[k];

            int tempNumber =0;

            tempNumber += (digit1*100);
            tempNumber += (digit2*10);
            tempNumber += (digit3);
            
            
            if(tempNumber> 99 && tempNumber%2 == 0)mp[tempNumber];
        }
        }
        }
     
     vector<int>ans;

     for(auto it:mp)ans.push_back(it.first);

     sort(ans.begin(),ans.end());

     return ans;

    }
};