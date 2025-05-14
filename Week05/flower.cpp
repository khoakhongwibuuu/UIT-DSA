
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

vector<int> get_ans(const vector<int> &A, int K)
{
    map<int, int> Hash;
    vector<int> ans;
    for (auto &i : A)
        Hash[i]++;
    for (auto &it : Hash)
    {
        ans.push_back(it.first);
        it.second--;
        if (ans.size() == K)
            return ans;
    }
    int remain = K - ans.size();
    for (auto &it : Hash)
    {
        if (it.second)
        {
            while (it.second--)
            {
                ans.push_back(it.first);
                if (ans.size() == K)
                    return ans;
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ans = get_ans(a, k);

    for (const int &x : ans)
        cout << x << ' ';
    return 0;
}
