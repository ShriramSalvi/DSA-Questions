class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        int size = nums.length;
        Map<Integer,Integer> mp = new HashMap<>();

        for(int i=0;i<size;i++){
            
            Integer val = mp.get(target-nums[i]);

            if(val != null ){
                return new int[]{val,i};
            }
            mp.put(nums[i],i);
        }

        return new int[]{0,0};
    }
}