/*
ID: liuhdsg2
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream fin("dualpal.in");
ofstream fout("dualpal.out");

bool ispal(string num){
    int len = num.size();

    for(int i=0,j=len-1;i<j;i++,j--){
        if(num[i]!=num[j])
            return false;
    }
    return true;
}
string numtostring(int num,int n){
    string str;
    if(num == 0){
        return str;
    }
    str = numtostring(num/n,n);
    str += "0123456789ABCDEFGHIJKLNMOPQRSTUVWXYZ"[num%n];
    return str;
}
int main()
{
    int N,S;
    fin>>N>>S;
    for(int i=0;i<N;){
        int cont = 0;
        S++;
        for(int j =2;j<=10;j++){
            if(ispal(numtostring(S,j))){
                cont++;
                if(cont == 2){
                fout<<S<<'\n';
                i++;
                break;
                }
            }
        }
    }
    return 0;
}
