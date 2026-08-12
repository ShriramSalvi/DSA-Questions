class Solution {
    public int removeDuplicates(int[] nums) {
        
        ArrayList<Integer>temp = new ArrayList<>();
        
        temp.add(nums[0]);

        int right =1;
        
        while(right<nums.length){
            if(nums[right]!= temp.get(temp.size()-1)){
                temp.add(nums[right]);
            }
            right++;
        }
        
        
        for(int i=0; i<temp.size();i++){
            nums[i]=temp.get(i);
        }
        return temp.size();
    }
}