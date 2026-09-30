class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int ans=0;

      for(int i=0; i<k; i++){
        ans+=cardPoints[i];
      }

      cout<<ans;

      int rightSum=0;
      int leftSum=0;
      int left=k-1;
      int right=cardPoints.size()-1;

      int finalans=ans;

      while(left>=0){
        rightSum += cardPoints[right];
        leftSum+=cardPoints[left];
        finalans = max((ans-leftSum+rightSum),finalans);
        left--;
        right--;
    
      }

      return finalans;  
    }
};