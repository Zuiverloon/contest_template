// #include <bits/stdc++.h>

#include <functional> //c++17 function
#include <iostream>
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

// #include <bits/stdc++.h>

typedef long long ll;
typedef int64_t i64;
typedef int32_t i32;

// g++ main.cpp -o main

int mod1e9 = 1e9 + 7;
int mod998 = 998244353;

template <typename T>
void print(T t)
{
	std::cout << t << std::endl;
}

template <typename T>
void printans(T t)
{
	std::cout << "ans = " << t << std::endl;
}

template <typename T>
void printVector(std::vector<T> &v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << v[v.size() - 1] << "\n";
}

template <typename T>
void printVectorNoSpace(std::vector<T> &v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		std::cout << v[i];
	}
	std::cout << v[v.size() - 1] << "\n";
}
template <typename T>
void printMatrix(std::vector<std::vector<T>> &m)
{
	for (int i = 0; i < m.size(); i++)
	{
		printVector(m[i]);
	}
}

template <typename T>
T gcd(T a, T b) // 最大公因数
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

template <typename T>
T lcm(T a, T b) // 最小公倍数
{
	return a / gcd(a, b) * b;
}

std::vector<bool> prime;

void getPrimeNums(int ceiling)
{
	prime = std::vector<bool>(ceiling + 1, true);
	int sqrtn = (int)std::sqrt(ceiling + 0.1);
	for (int i = 2; i <= sqrtn; i++)
	{
		if (prime[i])
		{
			for (int j = i; j * i <= ceiling; j++)
			{
				prime[i * j] = false;
			}
		}
	}
}

bool isPrime(int a) // 判断素数
{
	return prime[a];
}

template <typename T>
bool isinset(std::unordered_set<T> &s, T n) // 判断是否在set内
{
	return s.find(n) != s.end();
}

template <typename T>
bool isinset(std::set<T> &s, T n) // 判断是否在set内
{
	return s.find(n) != s.end();
}

ll power(ll a, ll n) // a的n次方
{
	if (n == 0)
		return 1l;
	if (n == 1)
		return a;
	if (n % 2 == 0)
	{
		ll tans = power(a, n / 2);
		tans *= tans;
		return tans;
	}
	else
	{
		ll tans = power(a, n / 2);
		tans *= tans;
		tans *= a;
		return tans;
	}
}

ll powerAndMod(ll a, ll n, ll m)
{
	if (n == 0)
		return 1LL % m;
	if (n == 1)
		return a % m;
	if (n % 2 == 0)
	{
		ll tans = powerAndMod(a, n / 2, m);
		tans *= tans;
		return tans % m;
	}
	else
	{
		ll tans = powerAndMod(a, n / 2, m);
		tans *= tans;
		tans %= m;
		tans *= a;
		return tans % m;
	}
}

void printCase(int i)
{
	std::cout << "case #" << i << ":\n";
}

template <typename T>
ll vsum(std::vector<int> &v)
{ // vector求和
	ll sum = 0;
	for (int i : v)
		sum += i;
	return sum;
}

bool vequal(std::vector<int> &v1, std::vector<int> &v2) // 判断两个vector是否相等
{
	for (int i = 0; i < v1.size(); ++i)
	{
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

template <typename T>
bool elementEqual(std::vector<T> &v) // 判断vector中每个元素是否相等
{
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i] != v[i - 1])
			return false;
	}
	return true;
}

void splitbyspace(std::vector<std::string> &v, std::string &s) // 用空格分割字符串得到数组
{
	std::string t = "";
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ')
		{
			if (t.size() > 0)
			{
				v.push_back(t);
			}
			t = "";
		}
		else
			t += s[i];
	}
	if (t.length() > 0)
		v.push_back(t);
	return;
}

template <typename T>
std::string decto(T n, T d) // d<=10 进制转换 把十进制的数n转化为d进制
{
	std::string ans = "";
	while (n >= d)
	{
		int mod = n % d;
		ans = std::to_string(mod) + ans;
		n /= d;
	}
	ans = std::to_string(n) + ans;
	return ans;
}

/** 排列组合 **/
template <typename T>
ll comp(T a, T b) // 组合数
{
	if (a < b)
		return comp(b, a);
	if (a == b)
		return 1;
	if (a - b > b)
		b = a - b;
	ll ans = 1;
	for (ll i = a; i >= a - b + 1; --i)
	{
		ans *= i;
	}
	for (ll i = b; i >= 2; --i)
	{
		ans /= i;
	}
	return ans;
}

template <typename T>
ll perm(T a, T b) // 排列数
{
	if (a < b)
		return perm(b, a);
	ll ans = 1;
	for (ll i = a; i >= a - b + 1; --i)
	{
		ans *= i;
	}
	return ans;
}

template <typename T>
int countone(T n) // 数一个数的二进制有几个1
{
	int ans = 0;
	while (n != 0)
	{
		if ((n & 1) == 1)
		{
			ans++;
		}
		n >>= 1;
	}
	return ans;
}

// void priority_queue_definition() // 优先队列定义
// {
// 	auto cmp = [](int a, int b) -> bool
// 	{ return a < b; };
// 	std::priority_queue<int, std::vector<int>, std::function<bool(int a, int b)>> q(cmp);
// 	q.push(2);
// 	q.push(3);
// 	q.push(1);
// 	std::cout << q.top() << "\n"; // output: 3
// }

template <typename T>
int digitSum(T num) // 求一个数 各位之和  1234 —> 10
{
	int ans = 0;
	while (num != 0)
	{
		int t = num % 10;
		ans += t;
		num /= 10;
	}
	return ans;
}

ll reverseNum(int num) // 反转一个数 1234 -> 4321
{
	ll ans = 0;
	while (num != 0)
	{
		int t = num % 10;
		ans *= 10;
		ans += t;
		num /= 10;
	}
	return ans;
}

ll factorial(int num) // 阶乘
{
	ll ans = 1;
	for (int i = 2; i <= num; ++i)
	{
		ans *= i;
	}
	return ans;
}

void exgcd(int a, int b, int &x, int &y)
{ // ax + by = gcd(a,b)
	if (b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	exgcd(b, a % b, y, x);
	y -= a / b * x;
}
int lowbit(int n)
{
	return n & (-n);
}

bool isPalindrome(std::string &s)
{
	for (int i = 0; i < s.length() / 2; i++)
	{
		if (s[i] != s[s.length() - 1 - i])
		{
			return false;
		}
	}
	return true;
}
// using namespace std;

void solve()
{
}

// clang++ -std=c++17 main.cpp -o main
// ./main

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n = 1;
	// std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		solve();
	}
	return 0;
}