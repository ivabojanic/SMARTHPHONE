#include <iostream>

using namespace std;

enum TipOperativnogSistema {Android,iOS};

class OSistem
{
private:
    TipOperativnogSistema tip;
    int verzija;
public:
    OSistem(){tip = Android; verzija = 1;}
    OSistem(TipOperativnogSistema t,int v){tip = t; verzija = v;}

    TipOperativnogSistema getTip()const
    {
        if(tip == Android)
        {
            return Android;
        }else
            return iOS;
    }
    int getVerzija()const
    {
        return verzija;
    }
    void setTip(TipOperativnogSistema tos)
    {
        tip = tos;
    }
    void setVerzija(int ver)
    {
        verzija = ver;
    }
};
void ispisOpSistema(const OSistem &os)
{
    cout<<"informacije o operativnom sistemu:"<<endl;
    cout<<"----------------------------------"<<endl;
    if(os.getTip() == Android)
        cout<<"Tip sistema je Android."<<endl;
    else
        cout<<"Tip sistema je iOS."<<endl;

    cout<<"Verzija sistema :"<<os.getVerzija()<<endl;
}

enum stanjeTelefon {ukljucen, iskljucen, standby, azurirase};

class SmarthPhone
{
private:
    TipOperativnogSistema sistem;
    stanjeTelefon stanje;
    int downloadProgress;
public:
    SmarthPhone():sistem() {sistem = Android; stanje = iskljucen; downloadProgress = -1;}
    SmarthPhone(TipOperativnogSistema t,stanjeTelefon s,int d):sistem(t){sistem = t; stanje = s; downloadProgress = d;}
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
