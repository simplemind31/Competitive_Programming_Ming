class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        if(nums[0]==nums[2]):
            return nums[0]
        if(nums[1]==nums[3]):
            return nums[1]
        if(nums[0]==nums[len(nums)-1]):
            return nums[0]
        if(len(nums)>4):
            if(nums[2]==nums[4]):
                return nums[2]
            if(nums[3]==nums[5]):
                return nums[3]
        for i in range(1,len(nums)):
            if(nums[i]==nums[i-1]):
                return nums[i]