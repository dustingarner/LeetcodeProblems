class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> required (numCourses);
        for(int i=0; i<prerequisites.size(); ++i){
            int course1 = prerequisites[i][0], course2 = prerequisites[i][1];
            required[course1].push_back(course2);
        }
        bool hasCycle = true;
        vector<int> seenCourses (numCourses, 0);
        for(int i=0; i<numCourses; ++i){
            hasCycle = false;
            dfs(required, i, hasCycle, seenCourses);
            if(hasCycle){
                break;
            }
        }
        return !hasCycle;
    }

    void dfs(vector<vector<int>>& required, int course, bool& hasCycle, 
            vector<int>& seenCourses){
        if(seenCourses[course]==2){
            hasCycle = true;
            return;
        }
        if(seenCourses[course]==1){
            return;
        }
        seenCourses[course] = 2;
        for(auto& x:required[course]){
            dfs(required, x, hasCycle, seenCourses);
            if(hasCycle){
                return;
            }
        }
        seenCourses[course] = 1;
    }
};
