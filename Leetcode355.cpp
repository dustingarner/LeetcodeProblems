class Twitter {
public:
    unordered_set<int> users;
    unordered_map<int, unordered_set<int>> following;
    deque<pair<int, int>> feed;

    Twitter() {
        
    }
    
    void verifyUser(int userId){
        if(users.find(userId)!=users.end()){
            return;
        }
        users.insert(userId);
        following[userId] = {userId};
    }

    void postTweet(int userId, int tweetId) {
        verifyUser(userId);
        feed.push_front({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        verifyUser(userId);
        vector<int> newsFeed;
        for(int i=0; i<feed.size(); ++i){
            pair<int, int> tweet = feed[i];
            if(following[userId].find(tweet.first)==following[userId].end()){
                continue;
            }
            newsFeed.push_back(tweet.second);
            if(newsFeed.size()==10){
                break;
            }
        }
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        verifyUser(followerId);
        verifyUser(followeeId);
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        verifyUser(followerId);
        verifyUser(followeeId);
        following[followerId].erase(followeeId);
    }
};
