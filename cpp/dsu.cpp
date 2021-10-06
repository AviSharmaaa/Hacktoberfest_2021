#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define check(x)  cerr << #x << ": " << x << endl;
int find(vector<int> &link, int n)
{
    while(link[n] != n) n = link[n];
    return n;
}

bool same(vector<int> &link, int a, int b)
{
    return find(link, a) == find(link, b);
}

void unite(vector<int> &link, vector<int> &len, int a, int b)
{
    int x = find(link, a), y = find(link, b);
    if(len[x] < len[y]) swap(x, y);
    link[y] = x;
    len[x] += len[y];
}

void solve()
{   
    vector<int> link(15, 0), len(15, 1);
    iota(link.begin(), link.end(), 0);
    for(int i = 0; i < 11; i++)
    {
        int x, y;
        cin >> x >> y;
        if(!same(link, x, y)) unite(link, len, x, y);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sync;
   
    int t = 1;
    cin >> t;
   
    while(t--) solve();
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;    
}
