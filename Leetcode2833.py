class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        l_count = 0
        r_count = 0
        __count = 0
        for i in moves:
            if i == "L":
                l_count += 1
            elif i == "R":
                r_count += 1
            else:
                __count += 1
        direction = -1 if l_count > r_count else 1
        return abs((l_count * -1) + r_count + (direction * __count))
