#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct aa
{
    vector<int> v;
    int sum;
    int idx;
    bool operator<(const aa &a) const
    {
        if (sum != a.sum)
            return sum > a.sum;
        return idx > a.idx;
    }
};
int summ[1000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string ans[n + 1];
        priority_queue<aa> q;
        for (int i = 1; i <= n; i++)
        {
            vector<int> v;
            v.push_back(i);
            cin >> summ[i];
            aa a;
            a.sum = summ[i];
            a.v = v;
            a.idx = i;
            q.push(a);
        }
        int cnt = n + 1;
        while (q.size() != 1)
        {
            aa a = q.top();
            q.pop();
            aa b = q.top();
            q.pop();
            for (int i = 0; i < a.v.size(); i++)
            {
                ans[a.v[i]] = '0' + ans[a.v[i]];
            }
            for (int i = 0; i < b.v.size(); i++)
            {
                ans[b.v[i]] = '1' + ans[b.v[i]];
                a.v.push_back(b.v[i]);
            }
            a.sum = a.sum + b.sum;
            a.idx = ++cnt;
            q.push(a);
        }
        if (n == 1)
            ans[1] = '0';
        for (int i = 1; i <= n; i++)
            cout << summ[i] << "-" << ans[i] << "\n";
    }
}