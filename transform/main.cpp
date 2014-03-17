/*
ID: liuhdsg2
PROG: transform
LANG: C++
*/
#include <iostream>
#include<fstream>
using namespace std;

int n;
typedef void (*func)(int&,int&);

ifstream fin("transform.in");
ofstream fout("transform.out");
void rotate90(int& x,int& y)
{
    int temp = x;
    x = y;
    y = n - temp - 1;
}

void rotate180(int& x,int& y)
{
    rotate90(x,y);
    rotate90(x,y);
}

void rotate270(int& x,int& y)
{
    rotate180(x,y);
    rotate90(x,y);
}

void reflaction(int &x,int &y)
{
    y = n - y-1;

}

void reflaction_90(int& x,int& y)
{
    reflaction(x,y);
    rotate90(x,y);
}
void reflaction_180(int& x,int& y)
{
    reflaction(x,y);
    rotate180(x,y);
}
void reflaction_270(int& x,int& y)
{
    reflaction(x,y);
    rotate270(x,y);
}
bool isequal(char* a,char* b)
{
    int total = n*n;
    for(int i=0; i<total; i++)
    {
        if(a[i] != b[i])
            return false;
    }
    return true;
}

char* operatematrix(char* res,char* des,func f)
{
    int tempi,tempj;
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            tempi =i;
            tempj =j;
            f(tempi,tempj);

            des[tempi*n+tempj]=res[i*n+j];

        }
    }
    return des;
}
int main()
{
    fin>>n;
    int len =n*n;
    char res[len],des[len],tem[len];

    for(int i=0; i<len; i++)
    {
        fin>>res[i];
    }
    for(int i=0; i<len; i++)
    {
        fin>>des[i];
    }
//    int k =1;
//     for(int i=0;i<len;i++){
//        if(i/n==k){
//        k++;
//        cout<<'\n';}
//        cout<<res[i]<<' ';
//
//    }




    if(isequal(des,operatematrix(res,tem,rotate90)))
    {
        fout<<1<<'\n';
    }
    else if(isequal(des,operatematrix(res,tem,rotate180)))
    {
        fout<<2<<'\n';
    }
    else if(isequal(des,operatematrix(res,tem,rotate270)))
    {
        fout<<3<<'\n';
    }
    else if(isequal(des, operatematrix(res,tem,reflaction)))
    {
        fout<<4<<'\n';
    }
    else if(isequal(des,operatematrix(res,tem,reflaction_180)))
    {
        fout<<5<<'\n';
    }
    else if(isequal(des,operatematrix(res,tem,reflaction_270)))
    {
        fout<<5<<'\n';

    }
    else if(isequal(des, operatematrix(res,tem,reflaction_90)))
    {
        fout<<5<<'\n';

    }
    else if(isequal(des,res))
    {
        fout<<6<<'\n';
    }
    else
    {
        fout<<7<<'\n';
    }


return 0;
}
