#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Twitter {
public:
    static int timestamp;
    class Tweet {
    public:
        int id;
        int time;
        Tweet* next;
        Tweet(int id, int time) : id(id), time(time){};
    };
    class User {
    public:
        int id;
        set<int> followed;
        Tweet* head;
        User() {}
        User(int id) {
            this->id = id;
            followed = set<int>();
            followed.insert(id);
            head = nullptr;
        }
        ~User() {
            auto cur = head;
            while (cur) {
                auto temp = cur;
                cur = cur->next;
                delete temp;
                temp = nullptr;
            }
        }
        void follow(int userId) { followed.insert(userId); }
        void unfollow(int userId) {
            if (userId != this->id) followed.erase(userId);
        }
        void post(int tweetId) {
            Tweet* twt = new Tweet(tweetId, timestamp);
            timestamp++;
            twt->next = head;
            head = twt;
        }
    };
    unordered_map<int, User> userMap;
    Twitter() {}
    ~Twitter() {
        // for(auto itr=userMap.begin();itr!=userMap.end();itr++){
        //     if(userMap.count(itr->first)){
        //         delete itr->second;
        //     }
        // }
    }
    void postTweet(int userId, int tweetId) {
        if (userMap.count(userId) == 0) {
            userMap.insert({userId, User(userId)});
        }
        User& u = userMap[userId];
        u.post(tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if (!userMap.count(userId)) return res;
        set<int>& users = userMap[userId].followed;
        auto TweetCompare = [](Tweet* a, Tweet* b) {
            if (a->time < b->time) return true;
            return false;
        };
        // struct TweetCompare {
        //     bool operator()(const Tweet *a, const Tweet *b) {
        //         return a->time < b->time;
        //     }
        // };
        priority_queue<Tweet*, vector<Tweet*>, decltype(TweetCompare)> pq(TweetCompare);
        for (auto id : users) {
            Tweet* twt = userMap[id].head;
            if (twt == nullptr) continue;
            pq.push(twt);
        }
        while (!pq.empty()) {
            if (res.size() == 10) break;
            Tweet* twt = pq.top();
            pq.pop();
            res.push_back(twt->id);
            if (twt->next) {
                pq.push(twt->next);
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (userMap.count(followerId) == 0) {
            userMap.insert({followerId, User(followerId)});
        }
        if (userMap.count(followeeId) == 0) {
            userMap.insert({followeeId, User(followeeId)});
        }
        userMap[followerId].follow(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (userMap.count(followerId)) {
            userMap[followerId].unfollow(followeeId);
        }
    }
};
int Twitter::timestamp = 0;
int main() {
    Twitter* twitter = new Twitter();
    twitter->postTweet(1, 5);  // 用户 1 发送了一条新推文 (用户 id = 1, 推文 id = 5)
    auto res = twitter->getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含一个 id 为 5 的推文
    for (auto num : res) cout << num << endl;
    twitter->follow(1, 2);     // 用户 1 关注了用户 2
    twitter->postTweet(2, 6);  // 用户 2 发送了一个新推文 (推文 id = 6)
    twitter->getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含两个推文，id 分别为 -> [6, 5] 。推文 id 6
                              // 应当在推文 id 5 之前，因为它是在 5 之后发送的
    twitter->unfollow(1, 2);  // 用户 1 取消关注了用户 2
    twitter->getNewsFeed(
        1);  // 用户 1 获取推文应当返回一个列表，其中包含一个 id 为 5 的推文。因为用户 1 已经不再关注用户 2
    delete twitter;
    return 0;
}