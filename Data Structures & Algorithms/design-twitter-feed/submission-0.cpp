class Twitter {
public:
    
    int time=0;
    unordered_map<int,unordered_set<int>> followList;
    unordered_map<int , vector<pair<int,int>> > tweets;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({time++, tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        
        vector<int> res;
        priority_queue<vector<int>> pq;
         followList[userId].insert(userId); 
        for (auto user : followList[userId]){
         if(tweets.count(user) && !tweets[user].empty()){
            int idx =tweets[user].size()-1;

            auto &temp =tweets[user][idx];
            pq.push({temp.first,temp.second,user,idx});
         }
        }

         while(!pq.empty() && res.size()<10){
           auto temp =pq.top();
           pq.pop();

           int tweetid=temp[1];
           int user =temp[2];
           int idx= temp[3];
           res.push_back(tweetid);
           if(idx>0)
           {auto &tmp =tweets[user][idx-1];
            pq.push({tmp.first,tmp.second,user,idx-1});

           }
         }
     return res;
        
    }
    
    void follow(int followerId, int followeeId) {
       followList[followerId].insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId); 
    }
};
