/*
ID: liuhdsg2
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int temp = 'A' - 1;
int getnum(string a){
    int len = a.length();
    int total = 1;
    for(int i = 0 ; i < len; i++){
        total *= (a[i] - temp);
    }
    return total;
}

bool can_go(string a, string b){\
    int res1 = getnum(a) % 47;
    int res2 = getnum(b) % 47;
    return res1 == res2;
}

int main()
{
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    string a,b;
    fin>>a>>b;
    if(can_go(a,b)){
        fout<<"GO\n";
    }else{
        fout<<"STAY\n";
    }

    return 0;
}
