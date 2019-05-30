//kurė Dominykas Rakūnas :D
#include <bits/stdc++.h>

using namespace std;
void write(bool found, int * temp, int seka, ofstream& out);
int main()
{
    ifstream in("U2.txt");
    ofstream out("U2rez.txt");
    int start[2];
    int startTemp[2];
    int end[2];
    int endTemp[2];
    int rows;
    int values;
    int seka = 0;
    in>>startTemp[0]; //susikuriu kopijas, nes tikrinant kitas kordinates reikia nuo pradiniu koordinaciu skaiciuot
    in>>startTemp[1];
    in>>endTemp[0];
    in>>endTemp[1];

    in>>rows;

    start[0]=startTemp[0];
    end[0]=endTemp[0];
    start[1]=startTemp[1];
    end[1]=endTemp[1];

    for(int i=0; i<rows; i++)
    {
        in>>values;
        int temp[values]; //laikinas masyvas kintantis dydziu pagal tai, kiek reiksniu yra eilutej
        for(int j=0; j<values; j++)
        {
            in>>temp[j];

            switch(temp[j]) //tikrina i kuria puse paeina ta reiksme
            {
            case 1:
                start[1]++;
                break;
            case 2:
                start[0]++;
                break;
            case 3:
                start[1]--;
                break;
            case 4:
                start[0]--;
                break;
            }
            seka++;
            if(start[0]==end[0] && start[1]==end[1]) //jei pagauna atitikmeni, tai iraso ir breakina cikla
            {
                write(true, temp, seka, out);
                break;
            }
        }
        if(start[0]!=end[0] || start[1]!=end[1]) // jeigu neranda, tai iraso ir nebera, ko breikint
        {
            write(false, temp, seka, out);
            cout<<"\n nerado "<<i<<endl;
        }
        start[0]=startTemp[0];
        end[0]=endTemp[0];
        start[1]=startTemp[1];
        end[1]=endTemp[1];
        seka = 0;
    }
    return 0;
}
void write(bool found, int * temp, int seka, ofstream& out)
{
    if(found)
    {
        out<<"pasiektas tikslas   ";
        for(int i=0; i<seka; i++)
        {
            out<<temp[i]<<" ";
        }
        out<<seka;
        out<<endl;
    }
    else
    {
        out<<"sekos pabaiga       ";
        for(int i=0; i<seka; i++)
        {
            out<<temp[i]<<" ";
        }
        out<<seka;
        out<<endl;
    }
}
