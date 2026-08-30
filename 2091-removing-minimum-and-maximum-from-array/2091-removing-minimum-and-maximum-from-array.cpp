class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
       if(nums.size()==1)return 1;
       if(nums.size()<=3)return 2;

      int size = nums.size();

      // trying side removal

      int minElement = nums[0];
      int minIdx=0;

      for(int i=1; i<nums.size();i++){

        if(nums[i]<minElement){
            minElement = nums[i];
            minIdx=i;
        }
      }

      int maxElement = nums[0];
      int maxIdx=0;

      for(int i=1; i<nums.size();i++){
        if(nums[i]>maxElement){
            maxElement = nums[i];
            maxIdx=i;
        }
      } 

      
      int Minleft = abs(0-minIdx)+1;
      int MinRight = abs(size-minIdx);
    
      cout<<Minleft<<" "<<MinRight;

      int Maxleft = abs(0-maxIdx)+1;
      int Maxright = abs(size-maxIdx);


      int sideRemoval =  min(Minleft,MinRight) + min(Maxleft,Maxright);


      // left follow up;

      int leftFollowUp = max(maxIdx,minIdx)+1;

      // right follow up;

      int rightFollowUp = size - min(minIdx,maxIdx);

      return min(leftFollowUp,min(rightFollowUp,sideRemoval));
    }
};