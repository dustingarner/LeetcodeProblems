class Solution:
    def maximumLength(self, s: str) -> int:
        char_dict = {}
        max_count = 0
        
        indi = 0
        while(indi < len(s)):
            i = s[indi]
            substring_len = 1
            counter = indi + 1
            while(counter <= len(s) - 1 and s[counter] == i):
                substring_len += 1
                counter += 1
            if not i in char_dict:
                char_dict[i] = collections.defaultdict(int)
            max_count = max(max_count, substring_len)
            char_dict[i][substring_len] += 1
            
            counter = substring_len - 1
            while(counter > 0):
                char_dict[i][counter] += 1
                counter -= 1
            
            indi += substring_len
            
        while(max_count > 0):
            for i in char_dict:
                #print(char_dict)
                if char_dict[i][max_count] >= 3:
                    return max_count
                char_dict[i][max_count - 1] += char_dict[i][max_count]
            max_count -= 1
        return -1
