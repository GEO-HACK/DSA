def rotate(nums, k):
    n = len(nums)
    k = k%n#remainder of k when it is divided by n.

    nums[:]=nums[n-k:] +nums[:n-k]

nums=[1,2,3,4,5,5,6,6]
k = 13
rotate(nums,k)
print(nums)    
