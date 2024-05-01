class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        last0=0
        for i in range(len(nums)):
            if nums[i]!=0:
                nums[last0]=nums[i]
                last0+=1
        

        for i in range(last0,len(nums)):
            nums[i]=0