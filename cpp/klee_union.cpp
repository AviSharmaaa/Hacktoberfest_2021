#include<bits/stdc++.h> 
using namespace std; 

int find_union(vector<pair<int,int>> vect) 
{ 
  int size = vect.size(); 

  vector <pair <int, bool> > endpoints(size * 2); 
  for (int i = 0; i < size; i++) 
  { 
    endpoints[i*2]  = make_pair(vect[i].first, false); 
    endpoints[i*2 + 1] = make_pair(vect[i].second, true); 
  } 

  sort(endpoints.begin(), endpoints.end()); 

  int result=0; 
  int counter = 0; 

  for (int i=0; i<size*2; i++) 
  { 
    if (counter) 
      result+=(endpoints[i].first - endpoints[i-1].first); 

    if (endpoints[i].second)
      counter--;
    else
      counter++; 
  } 
  return result; 
} 

int main() 
{ 
  vector< pair <int,int> > vect; 

  int size, a, b;

  cin>>size;

  for(int i=0;i<size;i++)
  {
      cin>>a;
      cin>>b;
      vect.push_back(make_pair(a,b));
  }

  int final=find_union(vect);

  cout<<"Length of union of segments of a line is " <<final;

  return 0;
} 
