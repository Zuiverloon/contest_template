// not accepted
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

void printYes()
{
    cout << "Yes\n";
}

void printNo()
{
    cout << "No\n";
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

struct sg
{
public:
    vector<ll> msg;
    vector<ll> tag;
    ll len;
    sg(ll n)
    {
        len = n;
        msg = vector<ll>(4 * n + 10, 0);
        tag = vector<ll>(4 * n + 10, 0);
    }

    void update(ll l, ll r, ll val)
    {
        update(1, len, l, r, val, 0);
    }

    void pushdown(ll l, ll r, ll o)
    {
        if (l == r)
        {
            tag[o] = 0;
            return;
        }
        msg[o * 2 + 1] += tag[o];
        msg[o * 2 + 2] += tag[o];
        tag[o * 2 + 1] += tag[o];
        tag[o * 2 + 2] += tag[o];
        tag[o] = 0;
        return;
    }

    void set(ll pos, ll val)
    {
        set(1, len, pos, val, 0);
    }

    void set(ll lb, ll rb, ll pos, ll val, ll o)
    {
        if (pos > rb || pos < lb)
        {
            return;
        }
        if (pos == lb && pos == rb)
        {
            tag[o] = 0;
            msg[o] = val;
            return;
        }
        pushdown(lb, rb, o);
        ll mid = (lb + rb) / 2;
        if (pos <= mid)
        {
            set(lb, mid, pos, val, o * 2 + 1);
        }
        else
        {
            set(mid + 1, rb, pos, val, o * 2 + 2);
        }
        msg[o] = min(msg[o * 2 + 1], msg[o * 2 + 2]);
    }

    ll get(ll l, ll r)
    {
        return get(1, len, l, r, 0);
    }

    ll get(ll lb, ll rb, ll l, ll r, ll o)
    {
        if (r < lb || l > rb)
        {
            return LLONG_MAX / 2;
        }
        if (l <= lb && r >= rb)
        {
            return msg[o];
        }
        pushdown(lb, rb, o);
        ll ans = LLONG_MAX / 2;
        ll mid = (lb + rb) / 2;
        if (l <= mid)
        {
            ans = min(ans, get(lb, mid, l, r, o * 2 + 1));
        }
        if (r > mid)
        {
            ans = min(ans, get(mid + 1, rb, l, r, o * 2 + 2));
        }
        return ans;
    }

    void update(ll lb, ll rb, ll l, ll r, ll val, ll o)
    {
        if (l > rb || r < lb)
        {
            return;
        }
        if (l <= lb && r >= rb)
        {
            msg[o] += val;
            tag[o] += val;
            return;
        }
        pushdown(lb, rb, o);
        ll mid = (lb + rb) / 2;
        if (l <= mid)
        {
            update(lb, mid, l, r, val, o * 2 + 1);
        }
        if (r > mid)
        {
            update(mid + 1, rb, l, r, val, o * 2 + 2);
        }
        msg[o] = min(msg[o * 2 + 1], msg[o * 2 + 2]);
        return;
    }

    ll getrmax(ll l, ll r)
    {
        return getrmax(1, len, l, r, 0);
    }

    ll getrmax(ll lb, ll rb, ll l, ll r, ll o)
    {
        if (r < lb || l > rb)
        {
            return -1;
        }
        if (lb == rb && l <= lb && r >= rb)
        {
            if (msg[o] < 0)
            {
                return lb;
            }
            else
            {
                return -1;
            }
        }
        pushdown(lb, rb, o);
        ll mid = (lb + rb) / 2;
        ll tans = getrmax(mid + 1, rb, l, r, o * 2 + 2);
        if (tans != -1)
            return tans;
        return getrmax(lb, mid, l, r, o * 2 + 1);
    }
};

vector<ll>
    onesg;

void setVal(vector<ll> &sg, ll lb, ll rb, ll pos, ll val, ll o)
{
    if (pos < lb || pos > rb)
    {
        return;
    }
    if (pos == lb && pos == rb)
    {
        sg[o] = val;
        return;
    }
    ll mid = (lb + rb) / 2;
    if (pos <= mid)
    {
        setVal(sg, lb, mid, pos, val, o * 2 + 1);
    }
    else
    {
        setVal(sg, mid + 1, rb, pos, val, o * 2 + 2);
    }
    sg[o] = sg[o * 2 + 1] + sg[o * 2 + 2];
    return;
}

ll getVal(vector<ll> &sg, ll lb, ll rb, ll pos, ll o)
{
    if (pos > rb || pos < lb)
    {
        return 0;
    }
    if (pos == lb || pos == rb)
    {
        return sg[o];
    }
    ll mid = (lb + rb) / 2;
    if (pos <= mid)
    {
        return getVal(sg, lb, mid, pos, o * 2 + 1);
    }
    else
    {
        return getVal(sg, mid + 1, rb, pos, o * 2 + 2);
    }
}

ll get(vector<ll> &sg, ll lb, ll rb, ll l, ll r, ll o)
{
    if (l > rb || r < lb)
    {
        return 0;
    }
    if (l <= lb && r >= rb)
    {
        return sg[o];
    }
    ll mid = (lb + rb) / 2;
    ll ans = 0;
    if (l <= mid)
    {
        ans += get(sg, lb, mid, l, r, o * 2 + 1);
    }
    if (r > mid)
    {
        ans += get(sg, mid + 1, rb, l, r, o * 2 + 2);
    }
    return ans;
}

ll getnonzero(ll l, ll r, ll n)
{
    return get(onesg, 1, n, l, r, 0);
}

void solve(int cas)
{
    ll n;
    cin >> n;
    onesg = vector<ll>(4 * n + 10, 0);
    sg sgg(n);
    for (ll i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;
        setVal(onesg, 1, n, i, 1, 0);
        sgg.update(i, i, a);
    }
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        ll tans = 0;
        tans = getnonzero(l, r, n) * k;
        sgg.update(l, r, -k);
        while (sgg.get(l, r) < 0)
        {
            // cout << "in while\n";
            ll rmax = sgg.getrmax(l, r);
            if (rmax == -1)
            {
                cout << "should not be the case\n";
                break;
            }

            ll overflow = sgg.get(rmax, rmax);
            // cout << "rmax=" << rmax << " overflow=" << overflow << "\n";
            tans -= abs(overflow);
            sgg.set(rmax, LLONG_MAX / 10);
            setVal(onesg, 1, n, rmax, 0, 0);
        }
        cout << tans << "\n";
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
