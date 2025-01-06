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

// clang++ -std=c++17 main.cpp -o main

ll mod1e9 = 1000000007LL;
ll mod998 = 998244353LL;

void print(ll t)
{
    printf("%lld\n", t);
}

void print(std::string s)
{
    printf("%s", s.c_str());
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

#define FOR(i, s, j, o) for (ll i = s; i < j; i += o)
#define FORR(i, s, j, o) for (ll i = s; i > j; i += o)

ll fpow(ll base, ll ex)
{
    if (ex == 0)
    {
        return 1;
    }
    if (ex == 1)
    {
        return base;
    }
    ll tans = fpow(base, ex / 2);
    if (ex % 2 == 0)
        return tans * tans;
    else
        return tans * tans * base;
}

ll f(ll limit) // num <= limit
{
    std::string slimit = std::to_string(limit);
    ll len = slimit.length();

    ll ans = 0;
    for (ll i = 2; i < len; i++)
    {
        for (ll j = 1; j <= 9; j++) // left digit
        {
            ll tans = 1;
            for (ll k = 1; k < i; k++) // i == 2, 98,97, 87,86
            {
                tans *= j;
            }
            ans += tans;
        }
    }
    std::cout << "tans = " << ans << "\n";
    // for (int i = 0;i<len;i++){

    // }
    for (ll first = 1; first <= 9; first++)
    {
        ll tans = 0;
        if (first < slimit[0] - '0')
        {
            tans = fpow(first, len - 1);
            std::cout << "first tans " << first << " " << tans << "\n";
        }
        else if (first == slimit[0] - '0')
        {
            for (ll offset = 1; offset < len; offset++)
            {
                ll tt = ((offset == len - 1) ? std::min(first - 1, (ll)(slimit[offset] - '0')) + 1 : (std::min(first, (ll)(slimit[offset] - '0')) * fpow(first, len - 1 - offset)));
                std::cout << "offset tt " << offset << " " << tt << "\n";
                // std::cout << "offset " << offset << " " << ((offset == len - 1) ? (slimit[offset] - '0' + 1) : ((slimit[offset] - '0') * fpow(first, len - 1 - offset))) << "\n";
                tans += tt;
            }
            // tans += 1;
        }
        else
        {
            break;
        }
        ans += tans;
    }
    return ans;
}

void find(std::vector<std::string> &v, char s, std::vector<ll> &st)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (s == v[i][j])
            {
                st[0] = i;
                st[1] = j;
                return;
            }
        }
    }
}

void solve(int cas)
{
    ll h, w;
    std::cin >> h >> w;
    std::vector<std::string> v(h, "");
    for (int i = 0; i < h; i++)
    {
        std::cin >> v[i];
    }
    std::unordered_map<ll, std::unordered_map<ll, ll>> vmn;
    std::unordered_map<ll, std::unordered_map<ll, ll>> hmn;
    std::vector<ll> st(4, 0);
    std::vector<ll> ed(3, 0);
    find(v, 'S', st);
    find(v, 'G', ed);
    std::queue<std::vector<ll>> q;
    q.push(st);
    vmn[st[0]][st[1]] = 1;
    hmn[st[0]][st[1]] = 1;
    while (!q.empty())
    {
        std::vector<ll> fr = q.front();
        q.pop();
        ll r = fr[0], c = fr[1], dis = fr[2], dir = fr[3];
        if (r == ed[0] && c == ed[1])
        {
            print(fr[2]);
            return;
        }
        if (r - 1 >= 0 && vmn[r - 1][c] == 0 && v[r - 1][c] != '#' && dir != 1)
        {
            vmn[r - 1][c] = 1;
            q.push(std::vector<ll>{r - 1, c, dis + 1, 1});
        }
        if (r + 1 < h && vmn[r + 1][c] == 0 && v[r + 1][c] != '#' && dir != 1)
        {
            vmn[r + 1][c] = 1;
            q.push(std::vector<ll>{r + 1, c, dis + 1, 1});
        }
        if (c - 1 >= 0 && hmn[r][c - 1] == 0 && v[r][c - 1] != '#' && dir != 2)
        {
            hmn[r][c - 1] = 1;
            q.push(std::vector<ll>{r, c - 1, dis + 1, 2});
        }
        if (c + 1 < w && hmn[r][c + 1] == 0 && v[r][c + 1] != '#' && dir != 2)
        {
            hmn[r][c + 1] = 1;
            q.push(std::vector<ll>{r, c + 1, dis + 1, 2});
        }
    }
    print(-1);
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