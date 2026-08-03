class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(!firstList.size() || !secondList.size())return {};

        int firstPointer=0; // for firstList
        int secondPointer=0; // for secondList;

        vector<vector<int>>ans;

        while(firstPointer<firstList.size() && secondPointer<secondList.size()){

            int lower1= firstList[firstPointer][0];
            int lower2= secondList[secondPointer][0];
            int upper1= firstList[firstPointer][1];
            int upper2 = secondList[secondPointer][1];
            
            if(upper2<lower1){
                secondPointer++;
                continue;
            }
            if(upper1<lower2){
                firstPointer++;
                continue;
            }
           ans.push_back({max(lower1,lower2),min(upper1,upper2)});

           if(upper1<=upper2) firstPointer++;
           else secondPointer++;
           }

           return ans;
    }
};