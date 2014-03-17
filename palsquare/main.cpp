/*
ID: liuhdsg2
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream fin("palsquare.in");
ofstream fout("palsquare.out");

int n;

bool ispal(string num){
    int len = num.size();
    if(len==1){
        return true;
    }
    for(int bg = 0,ed = len -1;bg<ed;bg++,ed--){
        if(num[bg] != num[ed])
            return false;
    }
    return true;
}

string tostring(int num){
    string res;//输出的回文不在乎正反，无所谓正反
    char c;
    int temp;
    while(num){
            //str += "0123456789ABCDEFGHIJXLMNOPQRSTUVWXYZ"[num%n];
        temp = num%n;
        if(temp>=10){
        c = 'A'+temp-10;
        }else{
        c = '0'+temp;
        }
        res += c;
        num /=n;
    }
    return res;
}

string reverse(string str){//利用string进行翻转
    string res(str.rbegin(),str.rend());
    return res;
}

string numtostring(int num){
    string str;
    if(num == 0){
        return str;
    }
    str = numtostring(num/n);
    str += "0123456789ABCDEFGHIJXLMNOPQRSTUVWXYZ"[num%n];
    return str;
}
int main()
{

    string str,num;
    fin>>n;
    for(int i =1;i<=300;i++){
        str = tostring(i*i);
        if(ispal(str)){
                num = tostring(i);
                //num.reserve();
            fout<<numtostring(i)<<' '<<str<<'\n';
        }
    }

    return 0;
}
