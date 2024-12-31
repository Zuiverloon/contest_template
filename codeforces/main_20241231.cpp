#include <stdio.h>
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

typedef long long ll;

void f(std::string &s, std::string &t)
{
    std::vector<ll> le(26, 0);
    for (int i = 1; i < t.size(); i++)
    {
        char c = t[t.size() - 1 - i];
        if (le[c - 'a'] == 0)
        {
            le[c - 'a'] = i;
        }
    }
    ll ans = INT_MAX;
    ll l = -1, r = -1;

    for (int i = 1; i < s.size(); i++)
    {
        if (le[s[i] - 'a'] > 0)
        {

            if (i + 1 + le[s[i] - 'a'] < ans)
            {
                l = i;
                r = t.size() - le[s[i] - 'a'];
                ans = i + 1 + le[s[i] - 'a'];
            }
        }
    }
    if (l == -1)
    {
        printf("-1\n");
        return;
    }
    std::string ansstr(ans, '0');
    ll ansp = 0;
    for (int i = 0; i <= l; i++)
    {
        ansstr[ansp++] = s[i];
    }
    for (int i = r; i < t.size(); i++)
    {
        ansstr[ansp++] = t[i];
    }
    printf("%s\n", ansstr.c_str());
}

int main()
{
    std::string s, t;
    std::cin >> s;
    std::cin >> t;
    f(s, t);
    return 0;
}