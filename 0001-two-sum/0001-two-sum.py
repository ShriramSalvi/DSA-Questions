class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        ans = [-1,-1]
        dict = {}

        for i in range(len(nums)):
            if dict.get(target-nums[i]) is None:
                dict[nums[i]]=i
            else:
                ans[0]=i
                ans[1]=dict[target-nums[i]]
        
        return ans

             