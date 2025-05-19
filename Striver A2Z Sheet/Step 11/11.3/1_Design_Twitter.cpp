#include <bits/stdc++.h>
using namespace std;

class Twitter
{
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int timeStamp;

public:
    Twitter()
    {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        timeStamp++;
        tweets[userId].push_back({timeStamp, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>> maxHeap; // (timestamp, tweetId)
        // getting the user tweets
        for (auto &tweet : tweets[userId])
        {
            maxHeap.push({tweet.first, tweet.second});
        }

        // getting their followers' tweets
        for (auto followeeId : followers[userId])
        {
            if (followeeId == userId)
                continue; // Skip own tweets to avoid duplication

            for (auto &tweet : tweets[followeeId])
            {
                maxHeap.push({tweet.first, tweet.second});
            }
        }
        vector<int> news;
        while (!maxHeap.empty() && news.size() < 10)
        {
            news.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return news;
    }

    void follow(int followerId, int followeeId)
    {
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main()
{

    return 0;
}