class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()>nums2.size() && nums1.size()>nums2.size()*6)return -1;
        if(nums2.size()>nums1.size() && nums2.size()>nums1.size()*6)return -1;

        int sum1=0;
        int sum2=0;

        for(int i:nums1)sum1+=i;
        for(int i:nums2)sum2+=i;

        int differnce=abs(sum1-sum2);
        if(differnce==0)return 0;
        
        if(sum2>sum1){
            vector<int>temp=nums2;
            nums2=nums1;
            nums1=temp;
        }

        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
         
         int count=0;
        
         int right=nums1.size()-1;
         int left=0; // for nums2

         while(right>=0 && left<nums2.size() && differnce>0){

            if(
             abs(nums1[right]-1)>abs(nums2[left]-6)){
                differnce-=abs(nums1[right]-1);
                right--;
            }
            else{
                differnce-=abs(nums2[left]-6);
                left++;
            }
            cout<<differnce<<" ";
            count++;
         }

         while(left<nums2.size() && differnce>0){
             differnce-=abs(nums2[left]-6);
             left++;
             count++;
         }

         while(right>=0 && differnce>0){
             differnce-=abs(nums1[right]-1);
              right--;
              count++;
         }
        return count;
    }
};