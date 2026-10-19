class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
      maxi=0
      c=0
      for i in range (len(nums)):
           if (nums[i]==1):
             c=c+1
           if(nums[i]==0):
             c=0
           maxi=max(maxi,c)

      return maxi
        