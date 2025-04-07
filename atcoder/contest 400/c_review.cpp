#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    cin >> n;
    
    int c1 = sqrtl(n / 2); // for a = 1
    int c2 = sqrtl(n / 4); // for a = 2
    // it is enough to count b only for a = 1 and a = 2 so as not to count same numbers many times
    cout << c1 + c2;

    return 0;
}
