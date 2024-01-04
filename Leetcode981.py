class TimeMap:

    def __init__(self):
        self.map = {}
        self.times = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if not key in self.map:
            self.map[key] = {timestamp: value}
            self.times[key] = [timestamp]
            return
        self.map[key][timestamp] = value
        self.times[key].append(timestamp)

    def get(self, key: str, timestamp: int) -> str:
        if not key in self.map:
            return ""
        #times = list(self.map[key].keys())
        if self.times[key][0] > timestamp:
            return ""
        l = 0
        r = len(self.map[key]) - 1
        while(l < r):
            m = ((r-l)//2) + l + 1
            current_time = self.times[key][m]
            if current_time == timestamp:
                return self.map[key][current_time]
            if current_time < timestamp:
                l = m
            else:
                r = m - 1
        return self.map[key][self.times[key][l]]



# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
