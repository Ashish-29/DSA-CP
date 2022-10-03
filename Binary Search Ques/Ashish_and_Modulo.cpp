#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> count(n);
        for (int i = 0; i < n; i++)
        {
            cin >> count[i];
            count[i] %= k;
        }

        sort(count.begin(), count.end());

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += count.end() - lower_bound(count.begin() + i + 1, count.end(), k - count[i]);
        }
        
        cout << ans << endl;
    }

    return 0;
}