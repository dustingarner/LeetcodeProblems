class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        goal = 0
        set_bits = 0
        while(num2 != 0):
            if num2%2:
                set_bits += 1
            num2 >>= 1
        temp_num1 = num1 >> 1
        max_val = 1
        while(temp_num1>0):
            max_val *= 2
            temp_num1 >>= 1
        while(set_bits>0 and max_val>0):
            if max_val&num1:
                goal += max_val
                set_bits -= 1
            max_val >>= 1
        addend = 1
        while(set_bits>0):
            if num1%2 == 0:
                goal += addend
                set_bits -= 1
            addend *= 2
            num1 >>= 1
        return goal
        
