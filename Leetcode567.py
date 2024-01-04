class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        char_dict = defaultdict(int)
        for i in s1:
            char_dict[i] += 1
        l, r = 0, 0
        temp_dict = char_dict.copy()
        while(r < len(s2)):
            while(r-l >= len(s1)):
                l += 1
            temp_dict[s2[r]] -= 1
            if not s2[r] in char_dict:
                r += 1
                while(l < r):
                    temp_dict[s2[l]] += 1
                    l += 1
                continue
            while(l < r and temp_dict[s2[r]] < 0):
                temp_dict[s2[l]] += 1
                l += 1
            is_permutation = True
            for i in temp_dict:
                if temp_dict[i] > 0:
                    is_permutation = False
                    break
            if is_permutation:
                return True
            r += 1
        return False
