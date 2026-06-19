class Twitter {
public:
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int count = 0;
    priority_queue<pair<int, int>> pq;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        count++;
        tweets[userId].push_back({count, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> allTweets;
        vector<pair<int, int>> userTweets = tweets[userId];
        unordered_set<int> following = followers[userId];
        for(int i = 0 ; i < userTweets.size() ; i++) allTweets.push_back(userTweets[i]);
        for(int followeeId : following) {
            // if(followeeId == userId) continue; 
            
            vector<pair<int, int>> followeeTweets = tweets[followeeId];
            for(int j = 0 ; j < followeeTweets.size() ; j++) {
                allTweets.push_back(followeeTweets[j]);
            }
        }

        sort(allTweets.begin(), allTweets.end());

        int n = allTweets.size();
        int idx = n-1;

        vector<int> res;
        while(res.size() < 10 && idx >= 0){
            res.push_back(allTweets[idx].second);
            idx--;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
