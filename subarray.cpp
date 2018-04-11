#include <map>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <cstring>

using namespace std;

template<std::size_t S>
int solve(std::array<int, S> a0) {
  map<int,int> m;
  int sum=0, i=0, flag=0;
  sum+=S;
  for(auto it = a0.begin();it!=a0.end();it++)
  {
    m.clear();
    m[*it]=1;
    for(auto it1 = it+1;it1!=a0.end();it1++)
    {
      flag=0;
      if(m.find(*it1)!=m.end())
        m.find(*it1)->second+=1;
      else
        m[*it1]=1;
      for(auto mi = m.begin();mi!=m.end();mi++)
      {
        if(mi->second%2==0)
          flag=1;
      }
      if(flag!=1)
        sum++;    
    }
  }
  return sum;    
}
