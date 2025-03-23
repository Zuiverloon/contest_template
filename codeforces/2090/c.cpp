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

void printYes()
{
    std::cout << "Yes\n";
}

void printNo()
{
    std::cout << "No\n";
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

bool mim(std::vector<ll> &a1, std::vector<ll> &a2)
{
    if (a1[3] != a2[3])
    {
        return a1[3] > a2[3];
    }
    ll a1x = a1[0];
    if (a1[2] == 2 || a1[2] == 3)
    {
        a1x++;
    }
    ll a1y = a1[1];
    if (a1[2] == 1 || a1[2] == 3)
    {
        a1y++;
    }
    ll a2x = a2[0];
    if (a2[2] == 2 || a2[2] == 3)
    {
        a2x++;
    }
    ll a2y = a2[1];
    if (a2[2] == 1 || a2[2] == 3)
    {
        a2y++;
    }

    if (a1x != a2x)
    {
        return a1x > a2x;
    }
    else
    {
        return a1y > a2y;
    }
}

void solve(int cas)
{
    ll n;
    std::cin >> n;
    auto cmp = [&](std::vector<ll> &a1, std::vector<ll> &a2) -> bool
    {
        if (a1[3] != a2[3])
        {
            return a1[3] > a2[3];
        }
        ll a1x = a1[0];
        if (a1[2] == 2 || a1[2] == 3)
        {
            a1x++;
        }
        ll a1y = a1[1];
        if (a1[2] == 1 || a1[2] == 3)
        {
            a1y++;
        }
        ll a2x = a2[0];
        if (a2[2] == 2 || a2[2] == 3)
        {
            a2x++;
        }
        ll a2y = a2[1];
        if (a2[2] == 1 || a2[2] == 3)
        {
            a2y++;
        }

        if (a1x != a2x)
        {
            return a1x > a2x;
        }
        else
        {
            return a1y > a2y;
        }
    };
    std::priority_queue<std::vector<ll>, std::vector<std::vector<ll>>, std::function<bool(std::vector<ll> & a1, std::vector<ll> & a2)>> ept(cmp);
    std::priority_queue<std::vector<ll>, std::vector<std::vector<ll>>, std::function<bool(std::vector<ll> & a1, std::vector<ll> & a2)>> som(cmp);
    ept.push(std::vector<ll>{1, 1, 0, 3});
    std::map<ll, std::set<ll>> mp;
    mp[1].insert(1);
    for (ll i = 0; i < n; i++)
    {
        ll t;
        std::cin >> t;
        if (t == 1)
        {
            std::vector<ll> emptp = ept.empty() ? std::vector<ll>{0} : ept.top();
            std::vector<ll> somtp = som.empty() ? std::vector<ll>{0} : som.top();
            // printVector(emptp);
            // printVector(somtp);
            bool compare = mim(emptp, somtp);
            // std::cout << "compare " << compare << "\n";
            if ((!som.empty() && !ept.empty() && compare))
            {
                // std::cout << "a\n";
                auto fr = som.top();
                // printVector(fr);
                som.pop();
                ll posx = fr[0], posy = fr[1], step = fr[3];
                if (fr[2] == 1)
                {
                    posy++;
                }
                else if (fr[2] == 2)
                {
                    posx++;
                }
                else if (fr[2] == 3)
                {
                    posx++;
                    posy++;
                }
                std::cout << posx << " " << posy << "\n";
                fr[2]++;

                ll nx = fr[0], ny = fr[1];
                if (fr[2] == 1)
                {
                    ny++;
                }
                else if (fr[2] == 2)
                {
                    nx++;
                }
                else if (fr[2] == 3)
                {
                    nx++;
                    ny++;
                }
                if (fr[2] < 4)
                {
                    som.push(std::vector<ll>{fr[0], fr[1], fr[2], fr[2] == 3 ? (nx + ny + 3) : (nx + ny + 1)});
                }
            }
            else
            {
                // std::cout << "b\n";
                auto fr = ept.top();
                ept.pop();
                // printVector(fr);
                ll posx = fr[0], posy = fr[1];
                std::cout << posx << " " << posy << "\n";

                som.push(std::vector<ll>{fr[0], fr[1], 1, (posx + posy + 1 + 1)});
                if (!isinset(mp[fr[0] + 3], fr[1]))
                {
                    mp[fr[0] + 3].insert(fr[1]);
                    ept.push(std::vector<ll>{fr[0] + 3, fr[1], 0, fr[0] + 3 + fr[1] + 1});
                }
                if (!isinset(mp[fr[0]], fr[1] + 3))
                {
                    mp[fr[0]].insert(fr[1] + 3);
                    ept.push(std::vector<ll>{fr[0], fr[1] + 3, 0, fr[0] + 3 + fr[1] + 1});
                }
            }
        }
        else
        {
            auto fr = ept.top();
            ept.pop();
            // printVector(fr);
            ll posx = fr[0], posy = fr[1];
            std::cout << posx << " " << posy << "\n";

            som.push(std::vector<ll>{fr[0], fr[1], 1, (posx + posy + 1 + 1)});

            if (!isinset(mp[fr[0] + 3], fr[1]))
            {
                mp[fr[0] + 3].insert(fr[1]);
                ept.push(std::vector<ll>{fr[0] + 3, fr[1], 0, fr[0] + 3 + fr[1] + 1});
            }
            if (!isinset(mp[fr[0]], fr[1] + 3))
            {
                mp[fr[0]].insert(fr[1] + 3);
                ept.push(std::vector<ll>{fr[0], fr[1] + 3, 0, fr[0] + 3 + fr[1] + 1});
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // initmobelong();

    int n = 1;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    return 0;
}