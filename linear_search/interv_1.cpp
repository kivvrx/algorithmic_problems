#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <climits>
#include <iomanip>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <assert.h>
using namespace std;



  int minMeetingRooms(vector<pair<int,int>>& intervals){
        sort(intervals.begin(), intervals.end(), [] ( const auto& a, const auto& b){
            return (a.first == b.first? a.second < b.second : a.first < b.first);
        });
        priority_queue<int , vector<int>, greater<int>> pq;
        for (int i = 0; i < intervals.size(); ++i){
            int start = intervals[i].first;
            int end = intervals[i].second;
            if (!pq.empty() && pq.top() <= start){
                pq.pop();
            }
            pq.push(end);
        } 
        return pq.size();
  }


int main (){


    return 0;
}
