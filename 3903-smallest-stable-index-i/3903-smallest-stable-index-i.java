class Solution {
    public int firstStableIndex(int[] nums, int k) {
        
        int size = nums.length;

        int leftMax[] = new int[size];
        int rightMin[] = new int[size];

        int leftMaxElement = Integer.MIN_VALUE;

        for(int i=0; i<size ;i++){
            leftMaxElement = Math.max(leftMaxElement , nums[i]);
            leftMax[i] = leftMaxElement;
        }

        int rightMinElement = Integer.MAX_VALUE;
        for(int i=size-1; i>=0 ; i--){
           rightMinElement = Math.min(rightMinElement , nums[i]);
           rightMin[i] = rightMinElement;
        }
        int diff = 0;
         for(int i=0; i<size ;i++){
           diff = leftMax[i] - rightMin[i];
           if(diff <= k){
            return i;

           }
         }
      return -1;
    }
}