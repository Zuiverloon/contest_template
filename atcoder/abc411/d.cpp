
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

// get multipliactive inverse by euclid method
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

// get multiplicative inverse by quick power
// ax = 1(mod b)
// x = a**(b-2) mod b
ll qpow(ll a, ll b)
{
    ll ans = 1;
    ll mod = b;
    b -= 2;
    a = (a % mod + mod) % mod;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = (a * ans) % mod;
        a = (a * a) % mod;
    }
    return ans;
}

/***     dsu template           */
// vector<ll> fa;

// ll get(ll i)
// {
// 	if (fa[i] != i)
// 	{
// 		fa[i] = get(fa[i]);
// 	}
// 	return fa[i];
// }

// void merge(ll a, ll b)
// {
// 	fa[get(b)] = get(a);
// }

/***     dsu template           */

#define FOR(i, s, j, o) for (ll i = s; i < j; i += o)
#define FORR(i, s, j, o) for (ll i = s; i > j; i += o)

// vector<ll> ft;
// void add(ll i, ll x)
// {
// 	while (i < ft.size())
// 	{
// 		ft[i] += x;
// 		i += lowbit(i);
// 	}
// }

// ll get(ll i)
// {
// 	ll ans = 0;
// 	while (i > 0)
// 	{
// 		ans += ft[i];
// 		i -= lowbit(i);
// 	}
// 	return ans;
// }

vector<vector<ll>> ca(26, vector<ll>(1100001, LLONG_MAX));

ll find(vector<ll> &v, ll val, ll i)
{
    if (v.size() == 0)
        return -1;
    if (val == -1)
    {
        return v[0];
    }
    if (ca[i][val] != LLONG_MAX)
    {
        return ca[i][val];
    }
    ll l = 0, r = v.size();
    ll ans = v.size();
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (v[mid] > val)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (ans >= v.size())
    {
        ca[i][val] = -1;
        return -1;
    }
    else
    {
        ca[i][val] = v[ans];
        return v[ans];
    }
}

void minNotSubSeq(string &s, ll k, vector<ll> &dp)
{
    if (k == 1)
    {
        for (ll i = s.size() - 1; i >= 0; i--)
        {
            dp[i] = s.size() - i + 1;
        }
        return;
    }
    vector<ll> cnt(k, 0);
    ll remain = k;
    ll ans = 0;
    for (ll i = s.size() - 1; i >= 0; i--)
    {
        cnt[s[i] - 'a']++;
        if (cnt[s[i] - 'a'] == 1)
        {
            remain--;
            if (remain == 0)
            {
                ans++;
                cnt = vector<ll>(k, 0);
                remain = k;
            }
        }
        dp[i] = ans + 1;
    }
    // if (remain != k)
    // {
    //   ans++;
    // }
}

ll f(string &s, string &t, vector<vector<ll>> &dp, ll k, vector<ll> &minNotSubSeqDP)
{
    vector<ll> cnt(k, 0);
    ll head = 0;
    for (ll i = 0; i < t.size(); i++)
    {
        ll next = dp[head][t[i] - 'a'];
        // cout << "next=" << next << "\n";
        if (next == LLONG_MAX)
        {
            // if (i == t.size() - 1)
            // {
            // 	return 1;
            // }
            return 0;
        }
        head = next;
    }
    // cout << "head=" << head << "\n";

    if (head >= s.size())
    {
        return 1;
    }
    return minNotSubSeqDP[head];
}
void solve(int cas)
{
    ll n, q;
    cin >> n >> q;
    vector<string> vs(q, "");
    ll vsp = 0;
    vector<vector<ll>> v(q, vector<ll>(2, 0));
    for (ll i = 0; i < q; i++)
    {
        ll d, p;
        cin >> d >> p;
        // cout << "d p " << d << " " << p << "\n";
        if (d == 2)
        {
            cin >> vs[vsp];
            vsp++;
        }
        v[i][0] = d;
        v[i][1] = p;
    }
    ll target = 0;
    vector<char> ans(1000007, '0');
    ll ansp = 0;
    // ll i = n - 1;
    for (ll i = q - 1; i >= 0; i--)
    {
        if (v[i][0] == 3)
        {
            if (target == 0)
                target = v[i][1];
        }
        else if (v[i][0] == 2)
        {
            if (target == v[i][1])
            {
                for (ll j = vs[vsp - 1].size() - 1; j >= 0; j--)
                {
                    ans[ansp++] = vs[vsp - 1][j];
                }
            }
            vsp--;
        }
        else
        {
            if (v[i][1] == target)
                target = 0;
        }
    }
    for (ll i = ansp - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
    if (ansp > 0)
        cout << "\n";
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
