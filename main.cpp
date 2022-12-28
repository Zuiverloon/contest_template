// #include <bits/stdc++.h>

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

using namespace std;

typedef long long ll;

// g++ main.cpp -o main

template <typename T>
void printVector(vector<T> &v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		cout << v[i] << " ";
	}
	cout << v[v.size() - 1] << endl;
}

template <typename T>
void printVectorNoSpace(vector<T> &v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		cout << v[i];
	}
	cout << v[v.size() - 1] << endl;
}

template <typename T>
T gcd(T a, T b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

bool isPrime(int a)
{
	if (a == 1)
		return false;
	if (a == 2)
		return true;
	if (a % 2 == 0)
		return false;
	int limit = (int)sqrt(a);
	for (int i = 3; i <= limit; i++)
	{
		if (a % i == 0)
			return false;
	}
	return true;
}

template <typename T>
bool isinset(unordered_set<T> &s, T n)
{
	return s.find(n) != s.end();
}

ll power(int a, int n)
{
	ll ans = 1;
	for (int i = 0; i < n; i++)
	{
		ans *= a;
	}
	return ans;
}

void printCase(int i)
{
	cout << "case #" << i << ":" << endl;
}

struct cmp
{
	bool operator()(string &s1, string &s2)
	{
		if (s1 + s2 < s2 + s1)
			return s1 > s2;
		else
			return s2 > s1;
	}
};

bool vequal(vector<int> &v1, vector<int> &v2)
{
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

template <typename T>
bool elementEqual(vector<T> &v)
{
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] != v[i - 1])
			return false;
	}
	return true;
}

template <typename T>
T lcm(T a, T b)
{
	return a / gcd(a, b) * b;
}

void splitbyspace(vector<string> &v, string &s)
{
	string t = "";
	for (int i = 0; i < s.length(); i++)
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
string decto(T n, T d) // d<=10
{
	string ans = "";
	while (n >= d)
	{
		int mod = n % d;
		ans = to_string(mod) + ans;
		n /= d;
	}
	ans = to_string(n) + ans;
	return ans;
}

/** 排列组合 **/
template <typename T>
ll comp(T a, T b)
{
	if (a < b)
		return comp(b, a);
	if (a == b)
		return 1;
	if (a - b > b)
		b = a - b;
	ll ans = 1;
	for (ll i = a; i >= a - b + 1; i--)
	{
		ans *= i;
	}
	for (ll i = b; i >= 2; i--)
	{
		ans /= i;
	}
	return ans;
}

template <typename T>
ll perm(T a, T b)
{
	if (a < b)
		return perm(b, a);
	ll ans = 1;
	for (ll i = a; i >= a - b + 1; i--)
	{
		ans *= i;
	}
	return ans;
}

int main()
{
	return 0;
}
