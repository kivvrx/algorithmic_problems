/*
#include <iostream>
using namespace std;
int main() {
    return 0;
}
*/
#include <iostream>
#include <unordered_map>
#include <assert.h>
using namespace std;
struct point {
    int x, y;
    bool operator == (const point& other) const{
        return x == other.x && y == other.y;
    }
    friend istream& operator>>(istream& is, point& p) {
        is >> p.x >> p.y;
        return is;
    }
};
struct PointHash {
    size_t operator()(const point& p) const noexcept {
        uint64_t ux = static_cast<uint64_t>(static_cast<int64_t>(p.x));
        uint64_t uy = static_cast<uint64_t>(static_cast<int64_t>(p.y));
        uint64_t h = (ux << 32) ^ uy;
        return static_cast<size_t>(h);
    }
};



bool check (const vector<point>& arr){
    unordered_map<point , int, PointHash> m;
    int mn = INT_MAX;
    int mx = INT_MIN;
    for (const auto& p : arr){
        mn = min(mn,p.x);
        mx = max(mx,p.x);
        m[p]++;
    }
    int mid = mn + mx;
    for (const auto& p : m){
        auto y = p.first.y;
        int x = mid - p.first.x;
        point pp {x,y};
        if (p.second != m[pp]) return false;
    }
    return true;
}

int main() {
    assert(check({{0, 0}, {0, 1}, {1, 1}, {2, 2}, {3, 1}, {4, 1}, {4, 0}}));
    assert(!check({{0, 0}, {0, 0}, {1, 1}, {2, 2}, {3, 1}, {4, 1}, {4, 0}}));
    assert(!check({{0, 0}, {0, 0}, {1, 1}, {2, 2}, {3, 1}, {4, 0}}));
    assert(check({{}}));
    assert(check({{0, 0}}));
    assert(check({{0, 0}, {10, 0}}));
    assert(!check({{0, 0}, {11, 1}}));
    assert(!check({{0, 0}, {1, 0}, {3, 0}}));
    return 0;
}

/*
-------------------------                                    
------------------                                     
----------                                    
-----                                     
                 |                  
                 |                   
                 |                  
                 |                 
                 |                 
-----------------|----------------------------------------------------
    -7   -5     -3  -1   1        
                 |                   
                 |                                       
                 |                   
                 |                   
                                    
                                     
                                    
                                     
                                    


mx = mn + 2*(mid - mn)
mx = mn + 2*mid - 2*mn
mx + mn = 2*mid 
mid = (mx+mn)/ 2













*/