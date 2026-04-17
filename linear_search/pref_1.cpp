#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> pref(n);
    vector<long long> pref_s(n);
    pref[0] = a[0];
    pref_s[0] = a[0];
    int idx = 0;
    for (int i = 1; i < n; i++) {
        pref_s[i] += pref_s[i-1] + a[i];
        pref[i] = (a[i] > a[i-1] ? pref_s[i] : a[i]);  
        if (pref[idx] < a[i]) {idx = i;}
    }
    for (int i = 0; i < n; i++) {
        if (i < idx) cout << 0 << " ";
        else cout << 1 << " ";
    }
    cout << endl;

    return 0;
}