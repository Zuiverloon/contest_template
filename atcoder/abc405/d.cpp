
#include <functional> //c++17 function
#include <vector>
#include <string.h>
#include <string>
#include <set>
#include <unordered_set>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <cctype>
#include <chrono>
#include <utility>
#include <list>
#include <stdio.h>
#include <iostream>

// #include <bits/stdc++.h>

typedef long long ll;
using namespace std;

// clang++ -std=c++17 main.cpp -o main

ll mod1e9 = 1000000007LL;
ll mod998 = 998244353LL;
ll mod1e8 = 100000000LL - 3;

ll gcd(ll a, ll b)
{
    if (a < b)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void printVector(std::vector<ll> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " \n"[i == v.size() - 1];
        // printf("%lld%c", v[i], " \n"[i == v.size() - 1]);
    }
}

void printVector(std::vector<std::string> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " \n"[i == v.size() - 1];
        // printf("%s%c", v[i].c_str(), " \n"[i == v.size() - 1]);
    }
}

template <typename T>
void printMatrix(std::vector<std::vector<T>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        printVector(v[i]);
    }
}

template <typename T>
bool isinset(std::set<T> &s, T n) // 判断是否在set内
{
    return s.find(n) != s.end();
}

template <typename T>
bool isinset(std::unordered_set<T> &s, T n) // 判断是否在set内
{
    return s.find(n) != s.end();
}

void ppqq()
{
    // 	auto cmp = [](int a, int b) -> bool
    // 	{ return a < b; };
    // 	std::priority_queue<int, std::vector<int>, std::function<bool(int a, int b)>> q(cmp);
}

ll lowbit(ll a)
{
    return a & (-a);
}

ll highbit(ll a)
{
    ll lb = lowbit(a);
    while (lb != a)
    {
        a -= lb;
        lb = lowbit(a);
    }
    return lb;
}

ll countone(ll a)
{
    ll ans = 0;
    while (a > 0)
    {
        ans += (a & 1);
        a >>= 1;
    }
    return ans;
}

void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

/***     dsu template           */
vector<ll> fa;

ll get(ll i)
{
    if (fa[i] != i)
    {
        fa[i] = get(fa[i]);
    }
    return fa[i];
}

void merge(ll a, ll b)
{
    fa[get(b)] = get(a);
}

/***     dsu template           */

#define FOR(i, s, j, o) for (ll i = s; i < j; i += o)
#define FORR(i, s, j, o) for (ll i = s; i > j; i += o)

vector<ll> ans;

void f(vector<ll> &t, ll k, ll pos)
{
    deque<vector<ll>> que;
    que.push_back(vector<ll>{0, t[0], 0});
    for (ll i = 1; i < t.size(); i++)
    {
        while (!que.empty() && que.front()[0] + k < i)
        {
            que.pop_front();
        }
        auto &fr = que.front();
        ll newval = fr[2] + (fr[1] <= t[i] ? 1 : 0);
        // cout << "test " << i << " " << newval << "\n";
        if (i == t.size() - 1)
        {
            ans[pos] = newval;
            return;
        }
        else
        {
            while (!que.empty() && (que.back()[2] > newval || (que.back()[2] == newval && que.back()[1] < t[i])))
            {
                que.pop_back();
            }
            que.push_back(vector<ll>{i, t[i], newval});
        }
    }
}

bool valid(vector<ll> &v, ll mid, ll m)
{
    vector<ll> cnt(m + 1, 0);
    for (ll i = 0; i <= mid; i++)
    {
        cnt[v[i]]++;
    }
    bool ans = false;
    for (ll i = 1; i < cnt.size(); i++)
    {
        if (cnt[i] == 0)
        {
            return true;
        }
    }
    return false;
}

void solve(int cas)
{
    ll h, w;
    cin >> h >> w;
    vector<string> v(h, "");
    vector<vector<bool>> reach(h, vector<bool>(w, false));
    queue<vector<ll>> q;
    for (ll i = 0; i < h; i++)
    {
        cin >> v[i];
        for (ll j = 0; j < w; j++)
        {
            if (v[i][j] == 'E')
            {
                q.push(vector<ll>{i, j});
                reach[i][j] = true;
            }
        }
    }
    while (!q.empty())
    {
        auto fr = q.front();
        q.pop();
        ll tr = fr[0], tc = fr[1];
        if (tr - 1 >= 0 && v[tr - 1][tc] == '.' && !reach[tr - 1][tc])
        {
            v[tr - 1][tc] = 'v';
            reach[tr - 1][tc] = true;
            q.push(vector<ll>{tr - 1, tc});
        }

        if (tr + 1 < h && v[tr + 1][tc] == '.' && !reach[tr + 1][tc])
        {
            v[tr + 1][tc] = '^';
            reach[tr + 1][tc] = true;
            q.push(vector<ll>{tr + 1, tc});
        }
        if (tc - 1 >= 0 && v[tr][tc - 1] == '.' && !reach[tr][tc - 1])
        {
            v[tr][tc - 1] = '>';
            reach[tr][tc - 1] = true;
            q.push(vector<ll>{tr, tc - 1});
        }
        if (tc + 1 < w && v[tr][tc + 1] == '.' && !reach[tr][tc + 1])
        {
            v[tr][tc + 1] = '<';
            reach[tr][tc + 1] = true;
            q.push(vector<ll>{tr, tc + 1});
        }
    }
    for (ll i = 0; i < h; i++)
    {
        cout << v[i] << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // initmobelong();

    int n = 1;
    // std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    return 0;
}
