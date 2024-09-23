class DetectSquares {
public:
    unordered_map<int, vector<int>> horizontal;
    unordered_map<int, multiset<int>> vertical;

    DetectSquares() {

    }
    
    void add(vector<int> point) {
        if(vertical.find(point[0])==vertical.end()){
            vertical[point[0]] = {};
        }
        vertical[point[0]].insert(point[1]);
        if(horizontal.find(point[1])==horizontal.end()){
            horizontal[point[1]] = {};
        }
        horizontal[point[1]].push_back(point[0]);
    }
    
    int count(vector<int> point) {
        if(horizontal.find(point[1])==horizontal.end()){
            return 0;
        }
        int total = 0;
        for(auto x:horizontal[point[1]]){
            if(x==point[0]){
                continue;
            }
            total += findSquares(point, x);
        }
        return total;
    }

    int findSquares(vector<int>& point, int verticallyAligned){
        int dist = abs(point[0]-verticallyAligned);
        vector<int> directions = {point[1]-dist, point[1]+dist};
        int squares = 0;
        for(auto x:directions){
            int perpCount = vertical[point[0]].count(x);
            int cornerCount = vertical[verticallyAligned].count(x);
            squares += perpCount * cornerCount;
        }
        return squares;
    }
};
