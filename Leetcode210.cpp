class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> hasRequisites(numCourses, false);
        vector<vector<int>> allows(numCourses);
        unordered_map<int, int> required;
        for(int i=0; i<prerequisites.size(); ++i){  
            int course1 = prerequisites[i][1], course2 = prerequisites[i][0];
            allows[course1].push_back(course2);
            hasRequisites[course2] = true;
            if(required.find(course2)==required.end()){
                required[course2] = 0;
            }
            required[course2] += course1;
        }
        queue<int> classes;
        for(int i=0; i<numCourses; ++i){
            if(!hasRequisites[i]){
                classes.push(i);
            }
        }
        vector<int> order;
        if(classes.empty()){
            return order;
        }
        vector<bool> seen(numCourses, false);
        while(!classes.empty()){
            int currentClass = classes.front();
            cout << currentClass<<endl;
            classes.pop();
            if(seen[currentClass]){
                return {};
            }
            seen[currentClass] = true;
            order.push_back(currentClass);
            for(int i=0; i<allows[currentClass].size(); ++i){
                int nextClass = allows[currentClass][i];
                required[nextClass] -= currentClass;
                if(required[nextClass] == 0){
                    classes.push(nextClass);
                }
            }
        }
        if(order.size()!=numCourses){
            return {};
        }
        return order;
    }
};
