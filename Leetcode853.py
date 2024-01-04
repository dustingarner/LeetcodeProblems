class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        speed = [x[1] for x in sorted(zip(position, speed), reverse = True)]
        position = sorted(position, reverse = True)

        prev_fleet = (target - position[0]) / speed[0]
        num_fleets = 1
        for i in range(1, len(position)):
            num_moves = (target - position[i]) / speed[i]
            if num_moves > prev_fleet:
                num_fleets += 1
                prev_fleet = num_moves
        return num_fleets
