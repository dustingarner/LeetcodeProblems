class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        final_xor = 0
        for i in nums:
            final_xor = final_xor^i
        
        counter = 0
        while(k or final_xor):
            if k%2!=final_xor%2:
                counter += 1
            k//=2
            final_xor//=2

        return counter      
