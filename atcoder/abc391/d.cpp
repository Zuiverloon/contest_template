

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

void solve(int cas)
{
    ll n, w;
    std::cin >> n >> w;
    std::vector<ll> colcnt(w + 1, 0);
    std::unordered_map<ll, std::vector<ll>> pos;
    std::unordered_map<ll, std::vector<ll>> ord;
    std::unordered_map<ll, std::unordered_map<ll, ll>> xord;
    std::unordered_map<ll, ll> ans;
    std::vector<std::vector<ll>> v(n, std::vector<ll>(2, 0));
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i][0] >> v[i][1];
        ord[i] = std::vector<ll>{v[i][0], v[i][1]};
    }
    std::sort(v.begin(), v.end(), [&](std::vector<ll> &a, std::vector<ll> &b)
              {
		if (a[0]!=b[0]){
			return a[0]<b[0];

		}
		else{
			return a[1]<b[1];
		} });
    for (int i = 0; i < n; i++)
    {
        ll x = v[i][0], y = v[i][1];
        colcnt[x]++;
        xord[x][y] = colcnt[x];
        pos[x].push_back(y);
    }
    ll minheight = INT_MAX;
    for (int i = 1; i < w + 1; i++)
    {
        minheight = std::min(minheight, colcnt[i]);
    }
    for (int i = 1; i <= minheight; i++)
    {
        // find max
        ll tans = 0;
        for (int j = 1; j <= w; j++)
        {
            tans = std::max(tans, pos[j][i - 1]);
        }
        ans[i] = tans;
    }
    ll q;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        ll t, a;
        std::cin >> t >> a;
        ll ax = ord[a - 1][0], ay = ord[a - 1][1];
        // std::cout << "ax ay " << ax << " " << ay << "\n";
        ll offset = xord[ax][ay];

        ll tans = ans[offset];
        // std::cout << "offset ansoffset " << offset << " " << tans << "\n";
        if (tans == 0)
        {
            tans = LLONG_MAX / 2;
        }
        if (t >= tans)
        {
            std::cout << "No\n";
        }
        else
        {
            std::cout << "Yes\n";
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
    // std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    return 0;
}