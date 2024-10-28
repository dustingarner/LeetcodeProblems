class RandomizedSet {
public:
    unordered_map<int, int> numSet;
    vector<int> numPoints;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool notPresent = numSet.find(val) == numSet.end();
        if(notPresent){
            numSet[val] = numPoints.size();
            numPoints.push_back(val);
        }
        return notPresent;
    }
    
    bool remove(int val) {
        bool present = numSet.find(val) != numSet.end();
        if(present){
            int temp = numPoints[numPoints.size()-1];
            numPoints[numSet[val]] = temp;
            numPoints[numPoints.size()-1] = val;
            numSet[temp] = numSet[val];
            numSet.erase(val);
            numPoints.pop_back();
        }
        return present;
    }
    
    int getRandom() {
        auto it = numPoints.begin() + (rand() % numPoints.size());
        return *it;
    }
};
