#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

class zi{
    vector<vector<int>> all_v;
    vector<int> cur;
    vector<int> idx;
    int now;
    bool check_now(){
            if (all_v[now].size() > cur[now]){
                return true;        
            }
            return false;
    };

    public:
    zi(const vector<int>& v1 , const vector<int>& v2){
        all_v.push_back({});
        all_v.push_back(v1);
        all_v.push_back(v2);
        cur.push_back(0);
        cur.push_back(0);
        cur.push_back(0);
        now = 1;
    };
    int next(){
        int nxt = -1;
        if (check_now()){
            nxt = all_v[now][cur[now]];
            idx.push_back(cur[now]);
            cur[now]++;
            now = (now + 1 >= all_v.size()? 1 : now + 1); 
        }
        else if (idx.size() == (all_v[1].size() + all_v[2].size())){
            return nxt;
        }
        else{
            while (!check_now()){
                now = (now + 1 >= all_v.size()? 1 : now + 1); 
            }
            nxt = all_v[now][cur[now]];
            idx.push_back(cur[now]);
            cur[now]++;
        }
        return nxt;
    };
};

// zi(v1,v2);
// 1 2 3 4 
// 1 2 
// 

int main() {

    // ---------- TEST 1: оба пустые ----------
    {
        zi z({}, {});
        assert(z.next() == -1);
    }

    // ---------- TEST 2: один пустой ----------
    {
        zi z({1,2,3}, {});
        assert(z.next() == 1);
        assert(z.next() == 2);
        assert(z.next() == 3);
        assert(z.next() == -1);
    }

    // ---------- TEST 3: другой пустой ----------
    {
        zi z({}, {5,6});
        assert(z.next() == 5);
        assert(z.next() == 6);
        assert(z.next() == -1);
    }

    // ---------- TEST 4: равные длины ----------
    {
        zi z({1,2}, {3,4});
        assert(z.next() == 1);
        assert(z.next() == 3);
        assert(z.next() == 2);
        assert(z.next() == 4);
        assert(z.next() == -1);
    }

    // ---------- TEST 5: v2 длиннее ----------
    {
        zi z({1}, {10,20,30});
        assert(z.next() == 1);
        assert(z.next() == 10);
        assert(z.next() == 20);
        assert(z.next() == 30);
        assert(z.next() == -1);
    }

    // ---------- TEST 6: v1 длиннее ----------
    {
        zi z({7,8,9}, {100});
        assert(z.next() == 7);
        assert(z.next() == 100);
        assert(z.next() == 8);
        assert(z.next() == 9);
        assert(z.next() == -1);
    }

    // ---------- TEST 7: большие числа ----------
    {
        zi z({1000,2000}, {3000,4000,5000});
        assert(z.next() == 1000);
        assert(z.next() == 3000);
        assert(z.next() == 2000);
        assert(z.next() == 4000);
        assert(z.next() == 5000);
        assert(z.next() == -1);
    }

    // ---------- TEST 8: повторяющиеся элементы ----------
    {
        zi z({1,1,1}, {2,2});
        assert(z.next() == 1);
        assert(z.next() == 2);
        assert(z.next() == 1);
        assert(z.next() == 2);
        assert(z.next() == 1);
        assert(z.next() == -1);
    }

    // ---------- TEST 9: проверка полного обхода ----------
    {
        zi z({1,2,3}, {4,5,6});
        vector<int> out;
        while (true) {
            int x = z.next();
            if (x == -1) break;
            out.push_back(x);
        }
        vector<int> expected = {1,4,2,5,3,6};
        assert(out == expected);
    }

    // ---------- TEST 10: сложный смешанный ----------
    {
        zi z({10,20,30,40}, {1,2});
        assert(z.next() == 10);
        assert(z.next() == 1);
        assert(z.next() == 20);
        assert(z.next() == 2);
        assert(z.next() == 30);
        assert(z.next() == 40);
        assert(z.next() == -1);
    }

    cout << "ALL ASSERTS PASSED\n";
    return 0;
}

