#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vii vector<vector<int>>

using namespace std;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    if (a + b > 0 && (a + b) % 2 == 0)
        ans = 1;
    if (a + c > 0 && (a + c) % 2 == 0)
        ans = 1;
    if (c + b > 0 && (c + b) % 2 == 0)
        ans = 1;
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int32_t main()
{
    solve();
    return 0;
}
