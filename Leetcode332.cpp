class Solution {
public:
    int itineraryLength = 0;
    bool itineraryFound = false;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        itineraryLength = tickets.size()+1;
        unordered_map<string, vector<string>> flights;
        unordered_map<string, unordered_map<string, int>> seenFlights;
        for(auto x:tickets){
            if(flights.find(x[0])==flights.end()){
                flights[x[0]] = {};
                seenFlights[x[0]] = {};
            }
            if(seenFlights[x[0]].find(x[1])==seenFlights[x[0]].end()){
                seenFlights[x[0]][x[1]] = 0;
            }
            flights[x[0]].push_back(x[1]);
            seenFlights[x[0]][x[1]]++;
        }
        for(auto& [x, y]:flights){
            sort(y.begin(), y.end());
            vector<string> newVector = {};
            for(auto z:y){
                if(newVector.size()==0){
                    newVector.push_back(z);
                    continue;
                }
                if(z==newVector[newVector.size()-1]){
                    continue;
                }
                newVector.push_back(z);
            }
            flights[x] = newVector;
        }
        vector<string> itinerary = {"JFK"};
        dfs(itinerary[0], itinerary, flights, seenFlights);
        return itinerary;
    }

    void dfs(string airport, vector<string>& itinerary, unordered_map<string, vector<string>>& flights,
            unordered_map<string, unordered_map<string, int>>& seenFlights){
        if(flights.find(airport)==flights.end()){
            return;
        }
        for(auto& x:flights[airport]){
            if(seenFlights[airport][x]==0){
                continue;
            }
            seenFlights[airport][x]--;
            itinerary.push_back(x);
            if(itinerary.size()==itineraryLength){
                itineraryFound = true;
                return;
            }
            dfs(x, itinerary, flights, seenFlights);
            if(itineraryFound){
                return;
            }
            seenFlights[airport][x]++;
            itinerary.pop_back();
        }
    }
};
