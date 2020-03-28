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
bool turnOff()
    {
        if(stanje == ukljucen)
        {
             stanje = iskljucen;
            downloadProgress = -1;
            return true;
        }else
            return false;
    }
    bool turnOn()
    {
        if(stanje == iskljucen)
        {
            stanje = ukljucen;
            downloadProgress = -1;
            return true;
        }else
            return false;
    }
    bool sleep()
    {
        if(stanje == ukljucen)
        {
            stanje = standby;
            downloadProgress = -1;
            return true;
        }else
            return false;
    }
    bool wakeUp()
    {
        if(stanje == standby)
        {
            stanje = ukljucen;
            downloadProgress = -1;
            return true;
        }else
            return false;
    }
    bool finishUpdate()
    {
        if(stanje == azurirase && downloadProgress == 100)
        {
            stanje = ukljucen;
            downloadProgress = -1;
            return true;
        }else
            return false;
    }
    bool startUpdate(int newVersion)
    {
        if(stanje == ukljucen)
        {
            stanje = azurirase;
            downloadProgress = 0;
            O.setVerzija(newVersion);
            return true;
        }else
            return false;
    }
    bool downloadBatch()
    {
        if(stanje == azurirase)
        {
            do
            {
                downloadProgress+=10;
            }while(downloadProgress!=100);
            return true;
        }else
            return false;
    }
stanjeTelefon getStanjeUredjaja()const
{
    return stanje;
}
TipOperativnogSistema getTipS()const
{
    return O.getTip();
}
int getVerzijuS()const
{
    return O.getVerzija();
}
};

void ispisSmartPhona(const SmarthPhone &s)
{
    cout<<"SmartPhone:"<<endl;
    cout<<"-----------------------"<<endl;
    if(s.getStanjeUredjaja() == ukljucen)
        cout<<"Telefon je ukljucen"<<endl;
    else if (s.getStanjeUredjaja() == iskljucen)
        cout<<"Telefon je iskljucen"<<endl;
    else if (s.getStanjeUredjaja() == standby)
        cout<<"Telefon je u standby"<<endl;
    else
        cout<<"Telefon se azurira"<<endl;

    cout<<"-----------------------"<<endl;
    cout<<s.getTipS()<<endl;
    cout<<"-----------------------"<<endl;
    cout<<s.getVerzijuS()<<endl;

}
int meni()
{
    int op;
    cout<<"1. Ukljuci"<<endl;
    cout<<"2. Iskljuci"<<endl;
    cout<<"3. U sleep mode"<<endl;
    cout<<"4. Probudi"<<endl;
    cout<<"5. Pocni azuriranje"<<endl;
    cout<<"6. Skini Batch"<<endl;
    cout<<"7. Zavrsi azuriranje"<<endl;
    cout<<"8. Kraj"<<endl;
    cin>>op;
    return op;
}

int main()
{
    int opcija;
    SmarthPhone S;
    bool prom;
    int verzija = 5;

    do
    {

    opcija = meni();

    switch(opcija)
    {
    case 1:
        prom = S.turnOn();
        break;
    case 2:
        prom = S.turnOff();
        break;
    case 3:
        prom = S.sleep();
        break;
    case 4:
        prom = S.wakeUp();
        break;
    case 5:
        prom = S.startUpdate(verzija);
        break;
    case 6:
        prom = S.downloadBatch();
        break;
    case 7:
        prom = S.finishUpdate();
        break;
    }
    if (opcija<1 || opcija>8)
        cout<<"Ne postoji opcija!"<<endl;
    else if(prom == true)
        ispisSmartPhona(S);

    }while(opcija>=1 && opcija<=7);
    return 0;
}
