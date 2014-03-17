/*
ID: liuhdsg2
PROG: milk2
LANG: C++
*/
#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

ifstream fin("milk2.in");
ofstream fout("milk2.out");

int n;

struct milker
{
    int begintime;
    int endtime;
};

vector<milker> milkers;

bool cmp(milker a, milker b)
{
    if(a.begintime<b.begintime)
        return true;
    else if(a.endtime<b.endtime&&a.begintime==b.begintime)
    {
        return true;
    }
    return false;
}
void initialvct()
{
    milker m;
    for(int i=0; i<n; i++)
    {
        fin>>m.begintime>>m.endtime;
        milkers.push_back(m);
    }
    sort(milkers.begin(),milkers.end(),cmp);
//     for(int i=0;i<n;i++){
//        cout<<' '<<milkers[i].begintime;
//     }
//     cout<<'\n';
//      for(int i=0;i<n;i++){
//        cout<<' '<<milkers[i].endtime;
//     }
}

int main()
{
    fin>>n;
    initialvct();
    int maxend = milkers[0].endtime,maxbegin = milkers[0].begintime;
    int maxc = maxend - maxbegin,maxidle = 0;
    for(int i = 1; i<n; i++)
    {
        if(milkers[i].begintime <= maxend && milkers[i].endtime >= maxend)
        {
            maxend = milkers[i].endtime;
        }
        else if(milkers[i].begintime > maxend)
        {
            int temp = maxend - maxbegin;
            if(maxc <temp)
            {
                maxc = temp;
            }
            temp = milkers[i].begintime - maxend;
            if(maxidle < temp)
            {
                maxidle = temp;
            }
            maxend = milkers[i].endtime;
            maxbegin = milkers[i].begintime;

        }
    }
    int temp = maxend - maxbegin;
    if(maxc <temp)
    {
        maxc = temp;
    }
    cout<<"\ncontinus = "<<maxc<<" maxidle = " <<maxidle<<'\n';
    fout<<maxc<<' '<<maxidle<<'\n';
    return 0;
}
