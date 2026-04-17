
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;


bool check (const string& s, const string& t){
    int ssz = s.size();
    int tsz = t.size();
    if ((ssz == 0 && tsz == 0) ||  (abs(ssz-tsz) > 1)) return false;
    if (ssz-tsz == -1) { // вставить 
        if (ssz == 0) return true;
        int cnt = 0;
        int l_s = 0;
        for (int l_t = 0; l_t < tsz; ++l_t){
            if (cnt > 1) return false;
            if (s[l_s] != t[l_t]) {
                cnt++;
                continue;
            }
            ++l_s;
        }
        return true;
    }
    else if (ssz-tsz == 1) { // удалить
        if (tsz == 0) return true;
        int cnt = 0;
        int l_t = 0;
        for (int l_s = 0; l_s < ssz; ++l_s){
            if (cnt > 1) return false;
            if (t[l_t] != s[l_s]) {
                cnt++;
                continue;
            }
            ++l_t;
        }
        return true;
    } 
    else { // заменить
        int cnt = 0;
        int l_t = 0;
        for (int l_s = 0; l_s < ssz; ++l_s){
            if (cnt > 1) return false;
            if (s[l_t] != t[l_s]) {
                cnt++;
            }
            ++l_t;
        }
        return cnt == 1;
    }
}

int main() {

    assert(check("ab", "abc") == true);

    assert(check("bc", "abc") == true);

    assert(check("ab", "acb") == true);

    assert(check("abc", "ab") == true);

    assert(check("abc", "bc") == true);

    assert(check("acb", "ab") == true);

    assert(check("abc", "axc") == true);

    assert(check("abc", "abc") == false);

    assert(check("abc", "axyd") == false);

    assert(check("", "a") == true);

    cout << "ALL ASSERTS PASSED\n";
}
