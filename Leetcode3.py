class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        elif len(s) == 1:
            return 1
        
        max_length = 0
        low, high = 0, 0
        seen_letters = {s[0]: True}

        for indi, i in enumerate(s):
            if indi == 0:
                continue
            if high == len(s) - 1:
                break
            high += 1
            if not s[high] in seen_letters:
                seen_letters[s[high]] = True
                temp_length = high - low + 1
                max_length = temp_length if temp_length > max_length else max_length
                continue
            
            letter_found = False
            while(not letter_found):
                if s[low] == s[high]:
                    letter_found = True
                    seen_letters[s[low]] = True
                else:
                    del seen_letters[s[low]]
                low += 1
        
        temp_length = high - low + 1
        max_length = temp_length if temp_length > max_length else max_length
        return max_length
            

                
