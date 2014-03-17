/*
ID: liuhdsg2
PROG: beads
LANG: C++
*/

#include <iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream fin("beads.in");
ofstream fout("beads.out");

string preprocess(string necklace){
    int lastcolorpos = 0;
    char lastcolor = necklace[0];
    int i =0;

        for(int k=0;k<necklace.size();){
            if(necklace[k]=='w'){
                k++;

            }else if(necklace[k]==lastcolor ||lastcolor =='w'){
                necklace.replace(lastcolorpos,k-lastcolorpos+1,k-lastcolorpos+1,necklace[k]);
                lastcolor = necklace[k];
                lastcolorpos = k;
                k++;
            }else{
                lastcolor = necklace[k];
                lastcolorpos = k;
                k++;
            }
    }
    return necklace;
}
int main()
{   int n;
    string necklace;
    fin>>n>>necklace;
    necklace += necklace;


    char lastbead = necklace[0];
    int last_chg = 0;
    int totalbead = 0;
    int maxbeads = 0;
    bool changed = false;
    bool changedp = false;
    necklace = preprocess(necklace);

    for(int i = 0; i < necklace.size(); i++){
        char bead = necklace[i];

        if(necklace[last_chg]!=bead && !changedp){
                changedp = true;
                last_chg = i;
        }
        if(bead=='w'||bead==lastbead||!changed){
            totalbead++;
            if(lastbead != 'w'&&bead != lastbead){
                changed = true;
                lastbead =bead;

        }

        }else{
             if(totalbead>maxbeads){
                maxbeads = totalbead;
            }
            totalbead = 0;
            i = last_chg;
            lastbead =necklace[last_chg];
            changed =false;
            changedp =false;
        }
        lastbead = bead;
    }
    if(totalbead>maxbeads){
        maxbeads = totalbead;
    }
    cout << maxbeads<< endl;
    return 0;
}
