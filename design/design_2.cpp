#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <assert.h>
using namespace std;

class RandomizedSet {
    vector<int> vec;
    unordered_map<int,int> mp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (!mp.count(val)) {
            vec.push_back(val);
            mp[val] = int(vec.size() - 1);
            return true;
        } 
        return false;
    }
    
    bool remove(int val) {
        if(mp.count(val)){
            auto idx = mp[val];
            auto last = vec.back();
            auto fnd = vec[idx];
            fnd = last;
            last = fnd;
            vec.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return (vec[size_t(rand()%vec.size())]);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */