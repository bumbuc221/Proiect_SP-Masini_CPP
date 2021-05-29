#include "masini.h"
#include <cstring>
#include <fstream>
#include <conio.h>
//fiecare masina va contine un id care se va incrementa
int Masini::id=0;
int Standard::serie=0;
int Offroad::serie=0;
int Premium::serie=0;
//constructor clasa de baza Masini
char* Masini::get_combustibil() {
   return  combustibil;
}
char* Masini::get_cutie() { return cutie;}
int Masini::get_locuri() {return locuri;}
int Masini::get_usi() {return nr_usi;}
Masini::Masini(char*categorie,int locuri,char*nume,char*cutie,char* combustibil,double pret,int nr_usi)
{
    this->categorie=new char[strlen(categorie)+1];
    strcpy(this->categorie,categorie);
    this->locuri=locuri;
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->cutie=new char[strlen(cutie)+1];
    strcpy(this->cutie,cutie);
    this->combustibil=new char[strlen(combustibil)+1];
    strcpy(this->combustibil,combustibil);
    this->pret=pret;
    this->nr_usi=nr_usi;
    id_v=id;
    valid=1;
    id++;
}

void Masini::init(const Masini &a) {
    this->categorie=new char[strlen(a.categorie)+1];
    strcpy(this->categorie,a.categorie);
    this->locuri=a.locuri;
    this->nume=new char[strlen(a.nume)+1];
    strcpy(this->nume,a.nume);
    this->cutie=new char[strlen(a.cutie)+1];
    strcpy(this->cutie,a.cutie);
    this->combustibil=new char[strlen(a.combustibil)+1];
    strcpy(this->combustibil,a.combustibil);
    this->pret=a.pret;
    this->nr_usi=a.nr_usi;
    this->valid=a.valid;
    this->id_v=a.id_v;
}
//constructor copiere clasa de baza Masini
Masini::Masini(const Masini &a) {
    init(a);
}

//operatorul de copiere al clasei de baza
Masini& Masini::operator=(const Masini &a) {
    if(&a==this)
        return *this;
    delete_();
    init(a);
    return *this;
}
void Masini::delete_() {
    if(categorie!= nullptr)
    delete []categorie;
    if(nume!= nullptr)
    delete []nume;
    if(cutie!= nullptr)
    delete []cutie;
    if(combustibil!= nullptr)
    delete []combustibil;
}
//Destructorul pt clasa de baza Masini
Masini::~Masini() {
 delete_();
}

//functia de afisare al clasei de baza
ostream& Masini::afisare(ostream& st)const{
    st<<"Categorie:"<<categorie<<endl;
    st<<"Nume:"<<nume<<endl<<"Pret:"<<pret<<endl<<"Combustibil:"<<combustibil<<endl;
    st<<"Cutie de viteze:"<<cutie<<endl<<"Locuri:"<<locuri<<endl<<"Usi: "<<nr_usi<<endl;
    st<<endl;
    return st;
}

//operatorul de scriere
ostream& operator<<(ostream& st,const Masini& a)
{
    return a.afisare(st);
}

//---------------------clasa categoria Standard

//constructorul clasei derivate Standard
Standard::Standard(char *categorie, int locuri, char *nume, char *cutie, char *combustibil, double pret, int nr_usi,int locuri_bagaje, char *reducere, char *navigatie)
        : Masini(categorie,locuri,nume,cutie,combustibil,pret,nr_usi){
    this->locuri_bagaje=locuri_bagaje;
    this->reducere=new char[strlen(reducere)+1];
    strcpy(this->reducere, reducere);
    this->navigatie=new char[strlen(navigatie)+1];
    strcpy(this->navigatie,navigatie);
    nr=serie;
    serie++;
}

//constructorul de copiere clasei Standard
Standard::Standard(const Standard &a): Masini(a) {
    this->locuri_bagaje=a.locuri_bagaje;
    this->reducere=new char[strlen(a.reducere)+1];
    strcpy(this->reducere,a.reducere);
    this->navigatie=new char[strlen(a.navigatie)+1];
    strcpy(this->navigatie,a.navigatie);
}

//operatorul de copiere = al clase Standard
Standard& Standard::operator=(const Standard &a) {
    if(&a==this)
        return *this;
    this->delete_();
   if(this->reducere)
    delete []this->reducere;
   if(this->navigatie)
    delete []this->navigatie;
    this->init(a);
    this->reducere=new char[strlen(a.reducere)+1];
    strcpy(this->reducere,a.reducere);
    this->navigatie=new char[strlen(a.navigatie)+1];
    strcpy(this->navigatie,a.navigatie);
    return *this;
}

//destructorul
Standard::~Standard(){
    delete[] navigatie;
    delete[] reducere;
}

//functia de afisare suprascrisa
ostream& Standard::afisare(ostream& st)const{
    st<<" ID-ul: "<< this->get_id()<<endl;
    st<<" Categorie: "<<categorie<<endl;
    st<<" Nume: "<<nume<<endl<<" Pret: "<<pret<<endl<<" Combustibil: "<<combustibil<<endl;
    st<<" Cutie de viteze: "<<cutie<<endl<<" Locuri: "<<locuri<<endl<<" Usi: "<<nr_usi<<endl;
    st<<" Nr locuri bagaje: "<<locuri_bagaje<<endl<<" Reducere: "<<reducere<<endl;
    st<<" Navigatie: "<<navigatie<<endl;
    st<<endl;
    return st;
}

//operatorul de afisare la clasa Standard
ostream& operator<<(ostream& st,const Standard& a)
{
    return a.afisare(st);
}

//---------------------clasa Offroad

//constructor
Offroad::Offroad(char *categorie, int locuri, char *nume, char *cutie, char *combustibil, double pret, int nr_usi,char *troliu, char *carlig, double motor, double inaltime)
        : Masini(categorie,locuri,nume,cutie,combustibil,pret,nr_usi){
    this->inaltime=inaltime;
    this->motor=motor;
    this->troliu=new char[strlen(troliu)+1];
    strcpy(this->troliu,troliu);
    this->carlig=new char[strlen(carlig)+1];
    strcpy(this->carlig,carlig);
    nr=serie;
    serie++;
}

//constructor de copiere
Offroad::Offroad(const Offroad&a): Masini(a)
{
    this->inaltime=a.inaltime;
    this->motor=a.motor;
    this->troliu=new char[strlen(a.troliu)+1];
    strcpy(this->troliu,a.troliu);
    this->carlig=new char[strlen(a.carlig)+1];
    strcpy(this->carlig,a.carlig);
}

//operator de copiere = pentru clasa Offroad
Offroad& Offroad::operator=(const Offroad&a)
{
    if(&a==this)
        return *this;
    delete_();
    delete []this->troliu;
    delete []this->carlig;
    init(a);
    this->inaltime=a.inaltime;
    this->motor=a.motor;
    this->troliu=new char[strlen(a.troliu)+1];
    strcpy(this->troliu,a.troliu);
    this->carlig=new char[strlen(a.carlig)+1];
    strcpy(this->carlig,a.carlig);
    return *this;
}

//functia de afisare pentru clasa offroad
ostream& Offroad::afisare(ostream& st)const{
    st<<" ID-ul: "<<this->get_id()<<endl;
    st<<" Categorie: "<<categorie<<endl;
    st<<" Nume: "<<nume<<endl<<" Pret: "<<pret<<endl<<" Combustibil: "<<combustibil<<endl;
    st<<" Cutie de viteze: "<<cutie<<endl<<" Locuri: "<<locuri<<endl<<" Usi: "<<nr_usi<<endl;
    st<<" Troliu: "<<troliu<<endl<<" Carlig de remorcare: "<<carlig<<endl;
    st<<" Capacitate Motor: "<<motor<<endl<<" Inaltime: "<<inaltime<<endl;
    st<<endl;
    return st;
}

//operatorul de afisare la clasa Offroad
ostream& operator<<(ostream& st,const Offroad& a)
{
    return a.afisare(st);
}

//destructor clasa Offroad
Offroad::~Offroad(){
    delete []troliu;
    delete []carlig;
}


//-----------------clasa Premium

//constructorul clasei Premium
Premium::Premium(char *categorie, int locuri, char *nume, char *cutie, char *combustibil, double pret, int nr_usi,int putere, int capacitate_cilindrica, char *transmisie, char *pilot_automat)
        : Masini(categorie,locuri,nume,cutie,combustibil,pret,nr_usi){
    this->putere=putere;
    this->capacitate_cilindrica=capacitate_cilindrica;
    this->transmisie=new char[strlen(transmisie)+1];
    strcpy(this->transmisie,transmisie);
    this->pilot_automat=new char[strlen(pilot_automat)+1];
    strcpy(this->pilot_automat,pilot_automat);
    nr=serie;
    serie++;
}

//constructorul de copiere
Premium::Premium(const Premium &a): Masini(a){
    this->putere=a.putere;
    this->capacitate_cilindrica=a.capacitate_cilindrica;
    this->transmisie=new char[strlen(a.transmisie)+1];
    strcpy(this->transmisie,a.transmisie);
    this->pilot_automat=new char[strlen(a.pilot_automat)+1];
    strcpy(this->pilot_automat,a.pilot_automat);
}

//operatorul de copiere = al clasei Premium
Premium& Premium::operator=(const Premium &a) {
    if(&a==this)
        return *this;
    delete_();
    delete []this->transmisie;
    delete []this->pilot_automat;
    init(a);
    this->putere=a.putere;
    this->capacitate_cilindrica=a.capacitate_cilindrica;
    this->transmisie=new char[strlen(a.transmisie)+1];
    strcpy(this->transmisie,a.transmisie);
    this->pilot_automat=new char[strlen(a.pilot_automat)+1];
    strcpy(this->pilot_automat,a.pilot_automat);
    return *this;
}
//functia de afisare
ostream & Premium::afisare(ostream &st) const {
    st<<" ID-ul: "<<this->get_id()<<endl;
    st<<" Categorie: "<<categorie<<endl;
    st<<" Nume: "<<nume<<endl<<" Pret: "<<pret<<endl<<" Combustibil: "<<combustibil<<endl;
    st<<" Cutie de viteze: "<<cutie<<endl<<" Locuri: "<<locuri<<endl<<" Usi: "<<nr_usi<<endl;
    st<<" Putere: "<<putere<<" CP"<<endl<<" Capacitate cilindrica: "<<capacitate_cilindrica<<endl;
    st<<" Transmisie: "<<transmisie<<endl<<" Pilot automat: "<<pilot_automat<<endl;
    st<<endl;
    return st;
}

//operatorul de afisare pt clasa Premium
ostream& operator<<(ostream& st,const Premium& a)
{
    return a.afisare(st);
}

//Destructor al clasei Premium
Premium::~Premium(){
    delete []transmisie;
    delete []pilot_automat;
}


//clasa Global ---------------------------------------
//clasa Global constructor
Global::Global() {
    l1=0;
    char linie[100];
    ifstream f("masini_clasice.txt");
    while(f.getline (linie,100)) {
        l1++;
    }
    a=citire_standard(l1);
    l2=0;
    ifstream g("masini_offroad.txt");
    while(g.getline (linie,100)) {
        l2++;
    }
    b= citire_offroad(l2);
    l3=0;
    ifstream e("masini_premium.txt");
    while(e.getline (linie,100)) {
        l3++;
    }
    c=citire_premium(l3);
}
//clasa Global constructor de copiere

Global::Global(const Global&x)
{
    this->l1=x.l1;
    this->l2=x.l2;
    this->l3=x.l3;
    this->a=new Standard*[x.l1];
    for(int i=0;i<x.l1;i++)
        this->a[i]=new Standard(*x.a[i]);
    this->b=new Offroad*[x.l2];
    for(int i=0;i<x.l2;i++)
         this->b[i]=new Offroad(*x.b[i]);
    this->c=new Premium*[x.l3];
    for(int i=0;i<x.l3;i++)
        this->c[i]=new Premium(*x.c[i]);
}

Global::~Global() {
        for (int i = 0; i < l1; i++)
            if(a[i])
            delete a[i];
        delete a;
        for (int i = 0; i < l2; i++)
            if(b[i])
            delete b[i];
        delete b;
        for (int i = 0; i < l3; i++)
            if(c[i])
            delete c[i];
        delete c;
}
//citire masini standard standard
Standard** Global::citire_standard(int n)
{
    Standard** a=new Standard*[n];
    int k=0;
    char linie[200];
    char categorie[5];
    int locuri;
    char nume[50],cutie[20],combustibil[20];
    double pret;
    int nr_usi;
    char reducere[20],navigatie[30];
    int nr_bagaje;
    ifstream f("masini_clasice.txt");
    while(f.getline (linie,200))
    {
        char*p = strtok(linie,",\n");
        int j=0,ok=1;
        while(p)
        {
            switch (j) {
                case 0:
                    break;
                case 1:
                    strcpy(categorie,p);
                    break;
                case 2:
                    strcpy(nume,p);
                    break;
                case 3:
                    strcpy(cutie,p);
                    break;
                case 4:
                    strcpy(combustibil,p);
                    break;
                case 5:
                    pret= atoi(p);
                    break;
                case 6:
                    nr_usi=atoi(p);
                    break;
                case 7:
                    locuri= atoi(p);
                    break;
                case 8:
                    nr_bagaje=atoi(p);
                    break;
                case 9:
                    strcpy(reducere,p);
                    break;
                case 10:
                    strcpy(navigatie,p);
                    break;
                case 11:
                    if(strcmp(p,"VALID"))
                        ok=0;
                    break;
            }
            j++;
            p=strtok(nullptr,",\n");
        }
        a[k]=new Standard(categorie,locuri,nume,cutie,combustibil,pret,nr_usi,nr_bagaje,reducere,navigatie);
        if(!ok)
            a[k]->set_valid(0);
        k++;
    }
    return a;
}
//citire masini  offroad
Offroad** Global::citire_offroad(int n)
{
    Offroad** a=new Offroad*[n];
    int k=0;
    char linie[200];
    char categorie[5];
    int locuri;
    char nume[50],cutie[20],combustibil[20];
    double pret;
    int nr_usi;
    char troliu[20],carlig[30];
    double inaltime,motor;
    ifstream f("masini_offroad.txt");
    while(f.getline (linie,200))
    {
        char*p = strtok(linie,",\n");
        int j=0,ok=1;
        while(p)
        {
            switch (j) {
                case 0:
                    break;
                case 1:
                    strcpy(categorie,p);
                    break;
                case 2:
                    strcpy(nume,p);
                    break;
                case 3:
                    strcpy(cutie,p);
                    break;
                case 4:
                    strcpy(combustibil,p);
                    break;
                case 5:
                    pret= atoi(p);
                    break;
                case 6:
                    nr_usi=atoi(p);
                    break;
                case 7:
                    locuri= atoi(p);
                    break;
                case 8:
                    strcpy(troliu,p);
                    break;
                case 9:
                    strcpy(carlig,p);
                    break;
                case 10:
                    inaltime=atoi(p);
                    break;
                case 11:
                    motor=atoi(p);
                    break;
                case 12:
                    if(strcmp(p,"VALID"))
                        ok=0;
                    break;
            }
            j++;
            p= strtok(nullptr,",\n");
        }
        a[k]=new Offroad(categorie,locuri,nume,cutie,combustibil,pret,nr_usi,troliu,carlig,motor,inaltime);
        if(!ok)
            a[k]->set_valid(0);
        k++;
    }
    return a;
}
//citire masini premium fisier
Premium** Global::citire_premium(int n)
{
    Premium** a=new Premium*[n];
    int k=0;
    char linie[200];
    char categorie[5];
    int locuri;
    char nume[50],cutie[20],combustibil[20];
    double pret;
    int nr_usi;
    char transmisie[20],pilot_automat[30];
    double putere,capacitate_cilindrica;
    ifstream f("masini_premium.txt");
    while(f.getline (linie,200))
    {
        char*p = strtok(linie,",\n");
        int j=0,ok=1;
        while(p)
        {
            switch (j) {
                case 0:
                    break;
                case 1:
                    strcpy(categorie,p);
                    break;
                case 2:
                    strcpy(nume,p);
                    break;
                case 3:
                    strcpy(cutie,p);
                    break;
                case 4:
                    strcpy(combustibil,p);
                    break;
                case 5:
                    pret= atoi(p);
                    break;
                case 6:
                    nr_usi=atoi(p);
                    break;
                case 7:
                    locuri= atoi(p);
                    break;
                case 8:
                    strcpy(transmisie,p);
                    break;
                case 9:
                    strcpy(pilot_automat,p);
                    break;
                case 10:
                    putere=atoi(p);
                    break;
                case 11:
                    capacitate_cilindrica=atoi(p);
                    break;
                case 12:
                    if(strcmp(p,"VALID"))
                        ok=0;
                    break;
            }
            j++;
            p= strtok(nullptr,",\n");
        }
        a[k]=new Premium(categorie,locuri,nume,cutie,combustibil,pret,nr_usi,putere,capacitate_cilindrica,transmisie,pilot_automat);
        if(!ok)
            a[k]->set_valid(0);
        k++;
    }
    return a;
}
//cautare seria A dupa nume
void Global::cautare_seria_A_nume(char *nume) {
    for(int i=0;i<l1;i++)
    {
        if(strstr(a[i]->get_nume(),nume) && a[i]->get_valid())
            cout<<" ID: "<<a[i]->get_id()<<" , "<<"NUME: "<<a[i]->get_nume()<<" , "<<"PRET/ZI: "<<a[i]->get_pret()<<"LEI"<<endl;
    }
}
//cautare seria A dupa pret
void Global::cautare_seria_A_pret(int pret) {
    for(int i=0;i<l1;i++)
    {

        if(abs(int(a[i]->get_pret()-pret))<=10 && a[i]->get_valid())
            cout<<" ID: "<<a[i]->get_id()<<" , "<<"NUME: "<<a[i]->get_nume()<<" , "<<"PRET/ZI: "<<a[i]->get_pret()<<"LEI"<<endl;
    }
}
//cautare seria B dupa nume
void Global::cautare_seria_B_nume(char *nume) {
    for(int i=0;i<l2;i++)
    {
        if(strstr(b[i]->get_nume(),nume) && b[i]->get_valid())
            cout<<" ID: "<<b[i]->get_id()<<" , "<<"NUME: "<<b[i]->get_nume()<<" , "<<"PRET/ZI: "<<b[i]->get_pret()<<"LEI"<<endl;
    }
}
//cautare seria B dupa pret
void Global::cautare_seria_B_pret(int pret) {
    for(int i=0;i<l2;i++)
    {

        if(abs(int(b[i]->get_pret()-pret))<=10 && b[i]->get_valid())
            cout<<" ID: "<<b[i]->get_id()<<" , "<<"NUME: "<<b[i]->get_nume()<<" , "<<"PRET/ZI: "<<b[i]->get_pret()<<"LEI"<<endl;
    }
}
//cautare seria C dupa nume
void Global::cautare_seria_C_nume(char *nume) {
    for(int i=0;i<l3;i++)
    {
        if(strstr(c[i]->get_nume(),nume) && c[i]->get_valid())
            cout<<" ID: "<<c[i]->get_id()<<" , "<<"NUME: "<<c[i]->get_nume()<<" , "<<"PRET/ZI: "<<c[i]->get_pret()<<"LEI"<<endl;
    }
}
//cautare seria C dupa pret
void Global::cautare_seria_C_pret(int  pret) {
    for(int i=0;i<l3;i++)
    {

        if(abs(int(c[i]->get_pret()-pret))<=100 && c[i]->get_valid())
            cout<<" ID: "<<c[i]->get_id()<<" , "<<"NUME: "<<c[i]->get_nume()<<" , "<<"PRET/ZI: "<<c[i]->get_pret()<<"LEI"<<endl;
    }
}


void Global::inchiriere(List* l,char *seria,int id) {
    char nume[40];
    int zile;
    cout<<" Introduceti numele dvs. : ";cin.getline(nume,40);
    cout<<" Introduceti nr. zile de inchiriere: ";
    while(true)
    {
        cin>>zile;
        if(zile>0)
            break;
        cout<<" Introduceti nr. zile de inchiriere valid: ";
    }
    cout<<endl;
    Masini* aux;
    if(strcmp(seria,"A")==0)
    {
        a[id]->set_valid(0);
        aux=a[id];
        aux->set_id(id);
        l->append(aux,nume,0,"");
        system("cls");
        cout<<" -----TICHET------"<<endl<<endl;
        cout<<" NUMELE: "<<nume<<endl;
        cout<<" DATA: "<<__DATE__<<endl;
        cout<<" PRETUL: "<<a[id]->get_pret()<<" lei/ZI"<<" , "<<"total: "<<a[id]->get_pret()*zile<<" lei/ "<<zile<<" zile"<<endl;
        cout<<endl<<" MASINA: "<<endl;
        cout<<*a[id];
        cout<<" ------------------"<<endl;
        update_masini_clasice_fisier();
        l->update_fisier_inchirieri();
        cout<<endl<<" Apasati enter pentru a continua.";cin.get();cin.get();
    }
    else
        if(strcmp(seria,"B")==0)
        {
            b[id]->set_valid(0);
            aux=b[id];
            aux->set_id(id);
            l->append(aux,nume,0,"");
            system("cls");
            cout<<" -----TICHET------"<<endl<<endl;
            cout<<" NUMELE: "<<nume<<endl;
            cout<<" DATA: "<<__DATE__<<endl;
            cout<<" PRETUL: "<<b[id]->get_pret()<<" lei/ZI"<<" , "<<"total: "<<b[id]->get_pret()*zile<<" lei/ "<<zile<<" zile"<<endl;
            cout<<endl<<" MASINA: "<<endl;
            cout<<*b[id];
            cout<<"-----------------"<<endl;
            update_masini_offroad_fisier();
            l->update_fisier_inchirieri();
            cout<<endl<<" Apasati enter pentru a continua.";cin.get();cin.get();
        } else
        {
            c[id]->set_valid(0);
            aux=c[id];
            aux->set_id(id);
            l->append(aux,nume,0,"");
            system("cls");
            cout<<" -----TICHET------"<<endl<<endl;
            cout<<" NUMELE: "<<nume<<endl;
            cout<<" DATA: "<<__DATE__<<endl;
            cout<<" PRETUL: "<<c[id]->get_pret()<<" lei/ZI"<<" , "<<"total: "<<c[id]->get_pret()*zile<<" lei/ "<<zile<<" zile"<<endl;
            cout<<endl<<" MASINA: "<<endl;
            cout<<*c[id];
            cout<<" -----------------"<<endl;
            update_masini_premium_fisier();
            l->update_fisier_inchirieri();
            cout<<endl<<" Apasati enter pentru a continua.";cin.get();cin.get();
        }
}
//update masini clasice fisier
void Global::update_masini_clasice_fisier() {
    ofstream f;
    f.open ("masini_clasice.txt");
    for(int i=0;i<l1;i++)
    {
        f<<i<<","<<"A"<<","<<a[i]->get_nume()<<","<<a[i]->get_cutie()<<","<<a[i]->get_combustibil()<<","<<a[i]->get_pret()<<","<<a[i]->get_usi()<<",";
        f<<a[i]->get_locuri()<<","<<a[i]->get_loc_bagaje()<<","<<a[i]->get_reducere()<<","<<a[i]->get_navigatie()<<",";
        if(a[i]->get_valid())
            f<<"VALID\n";
        else
            f<<"INVALID\n";
    }
    f.close();
}
//update fisere masini offroad
void Global::update_masini_offroad_fisier() {
    ofstream f;
    f.open ("masini_offroad.txt");
    for(int i=0;i<l2;i++)
    {
        f<<i<<","<<"B"<<","<<b[i]->get_nume()<<","<<b[i]->get_cutie()<<","<<b[i]->get_combustibil()<<","<<b[i]->get_pret()<<","<<b[i]->get_usi()<<",";
        f<<b[i]->get_locuri()<<","<<b[i]->get_troliu()<<","<<b[i]->get_carlig()<<","<<b[i]->get_inaltime()<<","<<b[i]->get_motor()<<",";
        if(b[i]->get_valid())
            f<<"VALID\n";
        else
            f<<"INVALID\n";
    }
    f.close();
}
//update fisier masini premium
void Global::update_masini_premium_fisier() {
    ofstream f;
    f.open ("masini_premium.txt");
    for(int i=0;i<l3;i++)
    {
        f<<i<<","<<"C"<<","<<c[i]->get_nume()<<","<<c[i]->get_cutie()<<","<<c[i]->get_combustibil()<<","<<c[i]->get_pret()<<","<<c[i]->get_locuri()<<",";
        f<<c[i]->get_usi()<<","<<c[i]->get_transmisie()<<","<<c[i]->get_pilot()<<","<<c[i]->get_putere()<<","<<c[i]->get_capacitate()<<",";
        if(c[i]->get_valid())
            f<<"VALID\n";
        else
            f<<"INVALID\n";
    }
    f.close();
}
//-------------------------------clasa Node
//constructor Node
Node::Node(Masini* p,char *nume, char *data) {
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->data=new char[strlen(data)+1];
    strcpy(this->data,data);
    next= nullptr;
    a=p;
}
//constructor de copiere Node
Node::Node(const Node &x) {
    this->nume=new char[strlen(x.nume)+1];
    strcpy(this->nume,x.nume);
    this->data=new char[strlen(x.data)+1];
    strcpy(this->data,x.data);
    this->next=x.next;
    this->a=x.a;
}
//destructor Node
Node::~Node() {
    delete []nume;
    delete []data;
}

//------------------------clasa Lista
//constructor
List::List() {
    head= nullptr;
    tail= nullptr;
}
//destructor clasa list
List::~List() {
    delete head;
    delete tail;
}
//append list
void List::append(Masini* x,char* nume,int n,char* d) {
    char data[20];
    if(n==0)
        strcpy(data,__DATE__);
    else
        strcpy(data,d);
    Node* aux=new Node(x,nume,data);
    if(head== nullptr)
    {
        head=aux;
        tail=aux;
    }
    else
    {
        tail->next=aux;
        tail=aux;
    }
}
//stergerea unei masini din lista de imprumuturi
void List::stergere(Global v, char *nume, char *nume_masina) {
    Node* aux=head;
    Node* aux2;
    int verif=0;//verififca daca gasete masina pe numele
    if(head)
    if(strcmp(head->nume,nume)==0 && strcmp(head->a->get_nume(),nume_masina)==0)
    {
        if(strcmp(head->a->get_categorie(),"A")==0) {
            for (int i = 0; i < v.l1; i++)
                if (strcmp(v.a[i]->get_nume(), nume_masina) == 0) {
                    verif = 1;
                    v.a[i]->set_valid(1);
                    v.update_masini_clasice_fisier();
                    break;
                }
        }
        else {
            if (strcmp(head->a->get_categorie(), "B") == 0) {
                for (int i = 0; i < v.l2; i++)
                    if (strcmp(v.b[i]->get_nume(), nume_masina) == 0) {
                        verif = 1;
                        v.b[i]->set_valid(1);
                        v.update_masini_offroad_fisier();
                        break;
                    }
            }
                    else {
                        if (strcmp(head->a->get_categorie(), "C") == 0) {
                            for (int i = 0; i < v.l3; i++)
                                if (strcmp(v.c[i]->get_nume(), nume_masina) == 0) {
                                    verif = 1;
                                    v.c[i]->set_valid(1);
                                    v.update_masini_premium_fisier();
                                    break;
                                }
                        }
                    }
        }
        head=head->next;update_fisier_inchirieri();
        delete aux;
    }
    else
    {
        while(aux)
        {
            if(strcmp(aux->nume,nume)==0 && strcmp(aux->a->get_nume(),nume_masina)==0)
            {
                if(strcmp(aux->a->get_categorie(),"A")==0) {
                    for (int i = 0; i < v.l1; i++)
                        if (strcmp(v.a[i]->get_nume(), nume_masina) == 0) {
                            verif = 1;
                            v.a[i]->set_valid(1);
                            v.update_masini_clasice_fisier();
                            break;
                        }
                }
                        else {
                    if (strcmp(aux->a->get_categorie(), "B") == 0) {
                        for (int i = 0; i < v.l2; i++)
                            if (strcmp(v.b[i]->get_nume(), nume_masina) == 0) {
                                verif = 1;
                                v.b[i]->set_valid(1);
                                v.update_masini_offroad_fisier();
                                break;
                            }
                    }
                            else {
                        if (strcmp(aux->a->get_categorie(), "C") == 0)
                            for (int i = 0; i < v.l3; i++)
                                if (strcmp(v.c[i]->get_nume(), nume_masina) == 0) {
                                    verif = 1;
                                    v.c[i]->set_valid(1);
                                    v.update_masini_premium_fisier();
                                    break;
                                }
                    }
                }
                                if(verif==1)
                                {
                                    aux2->next=aux->next;
                                    if(aux==tail) {
                                        delete aux;
                                        tail = nullptr;
                                    }else
                                        delete aux;
                                    update_fisier_inchirieri();
                                    break;
                                }
            }
            aux2=aux;
            aux=aux->next;
            }
    }
    if(!verif) {
        cout << " Nu s-a gasit nici o masina inchiriata pe numele dvs.!" << endl;
        cout<<endl<<" Apasati enter pentru a continua.";cin.get();
    }
}
//update fisier masini inchirieri
void List::update_fisier_inchirieri() {
    Node* aux=head;
    ofstream f;
    f.open ("inchirieri.txt");
    while(aux)
    {
        f<<aux->a->get_id()<<","<<aux->a->get_categorie()<<","<<aux->a->get_nume()<<",";
        f<<aux->a->get_cutie()<<","<<aux->a->get_combustibil()<<","<<aux->a->get_pret()<<","<<aux->a->get_locuri()<<",";
        f<<aux->a->get_usi()<<","<<aux->nume<<","<<aux->data<<"\n";
        aux=aux->next;
    }
    f.close();
}
//void citire fisier date inchirieri
void List::citire_date() {
    char linie[200];
    char categorie[5];
    int locuri;
    char nume[50],cutie[20],combustibil[20],nume_utilizotor[50],data[20];
    double pret;
    int nr_usi;int id=0;
    ifstream f("inchirieri.txt");
    while(f.getline (linie,200))
    {
        char*p = strtok(linie,",\n");
        int j=0;
        while(p)
        {
            switch (j)
            {
                case 0:
                    id= atoi(p);
                    break;
                case 1:
                    strcpy(categorie,p);
                    break;
                case 2:
                    strcpy(nume,p);
                    break;
                case 3:
                    strcpy(cutie,p);
                    break;
                case 4:
                    strcpy(combustibil,p);
                    break;
                case 5:
                    pret= atof(p);
                    break;
                case 6:
                    locuri= atoi(p);
                    break;
                case 7:
                    nr_usi=atoi(p);
                    break;
                case 8:
                    strcpy(nume_utilizotor,p);
                    break;
                case 9:
                    strcpy(data,p);
                    break;
            }
            j++;
            p= strtok(nullptr,",\n");
        }
        Masini *a=new Masini(categorie,locuri,nume,cutie,combustibil,pret,nr_usi);
        a->set_id(id);
        append(a,nume_utilizotor,1,data);
    }
}

//afisarea listei
void List::afis() {
    Node *aux=head;
    while(aux!= nullptr)
    {
        cout<<"Nume:"<<aux->nume<<endl<<"Data inchirieri:"<<aux->data<<endl<<*aux->a<<endl;
        aux=aux->next;
    }

}

void meniu()
{
    cout<<" ---------------------------"<<endl;
    cout<<" |           Meniu         |"<<endl;
    cout<<" | 1.  Masini disponibile. |"<<endl;
    cout<<" | 2.  Inchiriere masina.  |"<<endl;
    cout<<" | 3.  Restituire masina.  |"<<endl;
    cout<<" | 4.  Informatii masini.  |"<<endl;
    cout<<" | 5.  Exit, apasa ESC.    |"<<endl;
    cout<<" ---------------------------"<<endl<<endl;
    cout<<"     Alegeti o optiune: ";

}

void optiuni()
{
    Global v;
    List l;
    l.citire_date();
    char key;int ok=1;
    int cod_ascii;
    while(ok) {
        meniu();
        while(true) {
            key = getch();
            cod_ascii = key;
            if (cod_ascii == 27 || cod_ascii == 49 || cod_ascii == 50 || cod_ascii == 51 || cod_ascii==52)
                break;
            system("cls");
            meniu();
        }
        int kd=0;//verifica disponibilitatea
        switch (cod_ascii) {
            case 49:
                system("cls");
                char s[5];
                cout << " Avem urmatoarele categorii:" << endl<<endl;
                cout << " Seria A Standard cu pretul intre 50-500 lei/zi." << endl;
                cout << " Seria B Offroad" << endl;
                cout << " Seria C Premium cu pretul intre 500-3000 lei/zi" << endl << endl;
                cout << " Introduceti seria: ";
                cin.getline(s, 5);
                while (true) {
                    if (strcmp(s, "A") == 0) {
                        system("cls");
                        for(int i=0;i<v.l1;i++)
                            if(v.a[i]->get_valid())
                            {cout<<*v.a[i];kd=1;}
                        break;
                    }
                    else if (strcmp(s, "B") == 0) {
                        system("cls");
                        for(int i=0;i<v.l2;i++)
                            if(v.b[i]->get_valid())
                            {cout<<*v.b[i];kd=1;}
                        break;
                    }
                    else if (strcmp(s, "C") == 0) {
                        system("cls");
                        for(int i=0;i<v.l3;i++)
                            if(v.c[i]->get_valid())
                            {cout<<*v.c[i];kd=1;}
                        break;
                    }
                    else {
                        cout << " Introduceti seria corecta: ";
                        cin.getline(s, 5);
                    }
                }
                if(!kd)
                    cout<<endl<<" Nu avem masini disponibile din seria aceasta."<<endl;
                cout<<endl<<" Apasati enter pentru a continua.";
                cin.get();
                system("cls");
                break;
            case 50:
                system("cls");
                char s1[5];
                cout<<" Introduceti seria A/B/C: ";
                while(true)
                {
                    cin.getline(s1,5);
                    if(strcmp(s1,"A")==0 || strcmp(s1,"B")==0 || strcmp(s1,"C")==0)
                        break;
                    else
                        cout<<" Introduceti seria corecta A/B/C: ";
                }
                system("cls");
                char s3[5];
                cout<<endl;
                cout<<" 1. Cautare dupa pret."<<endl;
                cout<<" 2. Cautare dupa nume. "<<endl<<endl;
                cout<<endl<<" Introduceti o optiune dintre cele 2: ";
                while(true)
                {
                    cin.getline(s3,5);
                    if(strcmp(s3,"1")==0 || strcmp(s3,"2")==0)
                        break;
                    else
                        cout<<" Introduceti optiunea corecta 1 sau 2: ";
                }
                system("cls");
                if(strcmp(s3,"1")==0)
                {
                    int p,frecventa[1000];
                    for(int i=0;i<1000;i++)
                        frecventa[i]=0;
                    cout<<" Introduceti pretul: ";cin>>p;cin.get();
                    cout<<endl;
                    system("cls");
                    int ok2=0,ok3=0;
                    if(strcmp(s1,"A")==0)
                    {
                        cout<<" Masini disponibile:"<<endl;
                        for(int i=0;i<v.l1;i++) {
                            if (v.a[i]->get_pret() == p && v.a[i]->get_valid()) {
                                cout << *v.a[i];
                                ok2 = 1;
                                frecventa[i]=1;
                            }
                            if (abs(int(v.a[i]->get_pret()) - p) <=10 && v.a[i]->get_valid())
                            { ok3 = 1;frecventa[i]=1;}
                        }
                        if(!ok2)
                            cout<<" Nu avem masini disponibile pentru pretul respectiv!"<<endl;
                        cout<<endl<<" Masini similare dupa pret:"<<endl;
                        v.cautare_seria_A_pret(p);
                    }
                    else
                        if(strcmp(s1,"B")==0)
                        {
                            cout<<" Masini disponibile:"<<endl;
                            for(int i=0;i<v.l2;i++){
                                if(v.b[i]->get_pret()==p && v.b[i]->get_valid())
                                { cout<<*v.b[i];ok2=1;frecventa[i]=1;}
                                if (abs(int(v.b[i]->get_pret()) - p) <=10 && v.b[i]->get_valid())
                                { ok3 = 1;frecventa[i]=1;}
                            }
                            if(!ok2)
                                cout<<" Nu avem masini disponibile pentru pretul respectiv!"<<endl;
                            cout<<endl<<" Masini similare dupa pret:"<<endl;
                            v.cautare_seria_B_pret(p);
                        }
                        else
                        {
                            cout<<" Masini disponibile:"<<endl;
                            for(int i=0;i<v.l3;i++) {
                                if (v.c[i]->get_pret() == p && v.c[i]->get_valid()) {
                                    cout << *v.c[i];
                                    ok2 = 1;frecventa[i]=1;
                                }
                                if (abs(int(v.c[i]->get_pret()) - p) <=100 && v.c[i]->get_valid())
                                { ok3 = 1;frecventa[i]=1;}
                            }
                            if(!ok2)
                                cout<<" Nu avem masini disponibile pentru pretul respectiv!"<<endl;
                            cout<<endl<<" Masini similare dupa pret:"<<endl;
                            v.cautare_seria_C_pret(p);
                        }
                        if(ok2 || ok3)
                        {
                            char o[5];
                            cout <<endl<<" Doriti sa inchiriati una dintre masini?"<<endl;
                            cout<< " 1. Da"<<endl;
                            cout<< " 2. Nu"<<endl;
                            cout<<endl<<" Introduceti o optiune: ";
                            while(true)
                            {
                                cin.getline(o,5);
                                if(strcmp(o,"1")==0 || strcmp(o,"2")==0)
                                    break;
                                cout<<" Introduceti o optiune corecta! : ";
                            }
                            if(strcmp(o,"1")==0)
                            {
                                int id_;
                                cout<<" Introduceti ID-ul masini: ";
                                while(true) {
                                    cin >> id_;
                                    cin.get();
                                    if (frecventa[id_])
                                        break;
                                    cout << " Introduceti un ID corect din cele de sus: ";
                                }
                                v.inchiriere(&l,s1,id_);
                            }
                            else
                            {
                                system("cls");
                                break;
                            }
                        }
                        else
                        {
                            cout<<" Nu avem masini disponibile!"<<endl;
                            cout<<endl<<" Apasati enter pentru a continua.";cin.get();
                        }

                }
                else
                    if(strcmp(s3,"2")==0)
                    {
                        char nume_m[50];int pr=0,frecventa2[1000];//pretul echivalat
                        for(int i=0;i<1000;i++)
                            frecventa2[i]=0;
                        cout<<" Introduceti numele masini: ";cin.getline(nume_m,50);
                        int ok4=0,ok5=0;
                        cout<<endl;
                        system("cls");
                        if(strcmp(s1,"A")==0)
                        {
                            cout<<" Masini disponibile:"<<endl;
                            for(int i=0;i<v.l1;i++)
                                if (strstr(v.a[i]->get_nume(),nume_m) && v.a[i]->get_valid()) {
                                    cout << *v.a[i];
                                    ok4 = 1;pr=int(v.a[i]->get_pret());
                                    frecventa2[i]=1;
                                }
                            for(int i=0;i<v.l1;i++)
                                if(abs(int(v.a[i]->get_pret()) - pr) <=10 && v.a[i]->get_valid())
                                { ok5=1;frecventa2[i]=1;}
                            if(!ok4)
                                cout<<" Nu avem masini disponibile pentru pretul respectiv!"<<endl;
                            cout<<endl<<" Masini similare :"<<endl;
                            if(pr)
                            v.cautare_seria_A_pret(pr);
                        }
                        else
                        if(strcmp(s1,"B")==0)
                        {
                            cout<<" Masini disponibile:"<<endl;
                            for(int i=0;i<v.l2;i++)
                                if(strstr(v.b[i]->get_nume(),nume_m) && v.b[i]->get_valid())
                                { cout<<*v.b[i];ok4=1; pr=int(v.b[i]->get_pret());
                                frecventa2[i]=1;
                                }
                            for(int i=0;i<v.l2;i++)
                                if(abs(int(v.b[i]->get_pret()) - pr) <=10 && v.b[i]->get_valid())
                                {ok5=1;frecventa2[i]=1;}
                            if(!ok4)
                                cout<<" Nu avem masini disponibile pentru pretul respectiv!"<<endl;
                            cout<<endl<<" Masini similare:"<<endl;
                            if(pr)
                            v.cautare_seria_B_pret(pr);
                        }
                        else
                        {
                            cout<<" Masini disponibile:"<<endl;
                            for(int i=0;i<v.l3;i++) {
                                if (strstr(v.c[i]->get_nume(),nume_m) && v.c[i]->get_valid()) {
                                    cout << *v.c[i];
                                    ok4 = 1;pr=int(v.c[i]->get_pret());
                                    frecventa2[i]=1;
                                }
                                if (abs(int(v.c[i]->get_pret()) - pr) <=100 && v.c[i]->get_valid())
                                { ok5 = 1;frecventa2[i]=1;}
                            }
                            if(!ok4)
                                cout<<" Nu avem masini disponibile pentru pretul respectiv!"<<endl;
                            cout<<endl<<" Masini similare :"<<endl;
                            if(pr)
                            v.cautare_seria_C_pret(pr);
                        }
                        if(ok4 || ok5)
                        {
                            char e[5];
                            cout <<endl<<" Doriti sa inchiriati una dintre masini?"<<endl;
                            cout<< " 1. Da"<<endl;
                            cout<< " 2. Nu"<<endl;
                            cout<<endl<<" Introduceti o optiune: ";
                            while(true)
                            {
                                cin.getline(e,5);
                                if(strcmp(e,"1")==0 || strcmp(e,"2")==0)
                                    break;
                                cout<<" Introduceti o optiune corecta! : ";
                            }
                            if(strcmp(e,"1")==0)
                            {
                                int id_;
                                cout<<" Introduceti ID-ul masini: ";
                                while(true) {
                                    cin >> id_;
                                    cin.get();
                                    if (frecventa2[id_])
                                        break;
                                    cout << " Introduceti un ID corect din cele de sus: ";
                                }
                                v.inchiriere(&l,s1,id_);
                            }
                            else
                            {
                                system("cls");
                                break;
                            }
                        }
                        else
                        {
                            cout<<" Nu avem masini disponibile!"<<endl;
                            cout<<endl<<" Apasati enter pentru a continua.";cin.get();
                        }


                    }
                system("cls");
                break;
            case 51:
                system("cls");
                char nume_[30],nume_masina[30],s4[5];
                cout<<" Introduceti numele dvs: ";cin.getline(nume_,30);
                cout<<" Introduceti numele masini: ";cin.getline(nume_masina,30);
                cout<<" Introduceti seria A/B/C: ";
                while(true)
                {
                    cin.getline(s4,5);
                    if(strcmp(s4,"A")==0 || strcmp(s4,"B")==0 || strcmp(s4,"C")==0)
                        break;
                    else
                        cout<<" Introduceti seria corecta A/B/C: ";
                }
                if(strcmp(s4,"A")==0)
                    l.stergere(v,nume_,nume_masina);
                else if(strcmp(s4,"B")==0)
                    l.stergere(v,nume_,nume_masina);
                else
                    l.stergere(v,nume_,nume_masina);
                system("cls");
                cout<<" Va multumim!"<<endl;
                cout<<endl<<" Apasati enter pentru a continua.";
                cin.get();
                system("cls");
                break;
            case (52):
                system("cls");
                char q[5];
                cout << " Avem urmatoarele categorii:" << endl << endl;
                cout << " Seria A Standard cu pretul intre 50-500 lei/zi." << endl;
                cout << " Seria B Offroad" << endl;
                cout << " Seria C Premium cu pretul intre 500-3000 lei/zi" << endl << endl;
                cout << " Introduceti seria: ";
                while (true) {
                    cin.getline(q, 5);
                    if (strcmp(q, "A") == 0 || strcmp(q, "B") == 0 || strcmp(q, "C") == 0)
                        break;
                    cout << " Introduceti seria corecta: ";
                }
                system("cls");
                if (strcmp(q, "A") == 0) {
                    for (int i = 0; i < v.l1; i++)
                        cout << " ID-ul: " << v.a[i]->get_id() << " , " << " Nume: " << v.a[i]->get_nume() << endl;
                } else {
                    if (strcmp(q, "B") == 0) {
                        for (int i = 0; i < v.l2; i++)
                            cout << " ID-ul: " << v.b[i]->get_id() << " , " << " Nume: " << v.b[i]->get_nume() << endl;
                    } else
                        for (int i = 0; i < v.l3; i++)
                            cout << " ID-ul: " << v.c[i]->get_id() << " , " << " Nume: " << v.c[i]->get_nume() << endl;
                }
                while (true) {
                    char z[5];
                    cout << endl << " Doriti sa aflati informatii despre o masina? " << endl;
                    cout << " 1. Da" << endl;
                    cout << " 2. Nu" << endl << endl;
                    cout << " Introduceti o optiune: ";
                    while (true) {
                        cin.getline(z, 5);
                        if (strcmp(z, "1") == 0 || strcmp(z, "2") == 0)
                            break;
                        cout << " Introduceti o optiune corecta: ";
                    }
                    if (strcmp(z, "1") == 0) {
                        int id_2;
                        cout << " Introduceti ID-ul masini: ";
                        while (true) {
                            cin>>id_2;cin.get();
                            if (strcmp(q, "A") == 0 && id_2 < v.l1)
                                break;
                            else if (strcmp(q, "B") == 0 && id_2 < v.l2)
                                break;
                            else if (strcmp(q, "C") == 0 && id_2 < v.l3)
                                break;
                            cout << " Introduceti ID-ul valid: ";
                        }
                        cout << " ------ Informatii masina ------" << endl << endl;
                        if (strcmp(q, "A") == 0)
                            cout << *v.a[id_2];
                        else if (strcmp(q, "B") == 0)
                            cout << *v.b[id_2];
                        else
                            cout << *v.c[id_2];
                        cout <<endl<< " Apasati enter pentru a continua."; cin.get();
                        system("cls");
                        if (strcmp(q, "A") == 0) {
                            for (int i = 0; i < v.l1; i++)
                                cout << " ID-ul: " << v.a[i]->get_id() << " , " << " Nume: " << v.a[i]->get_nume()
                                     << endl;
                        } else {
                            if (strcmp(q, "B") == 0) {
                                for (int i = 0; i < v.l2; i++)
                                    cout << " ID-ul: " << v.b[i]->get_id() << " , " << " Nume: " << v.b[i]->get_nume()
                                         << endl;
                            } else
                                for (int i = 0; i < v.l3; i++)
                                    cout << " ID-ul: " << v.c[i]->get_id() << " , " << " Nume: " << v.c[i]->get_nume()
                                         << endl;
                        }
                    } else
                    {cout << " Apasa enter pentru a continua.";cin.get();break;}
                }
                system("cls");
                break;
            case 27:
                system("cls");
                ok=0;
                break;
        }
    }
}


//citire fisier masini Standarde
Standard** citirefisier1()
{
    Standard** a=new Standard*[100];
    int k=0;
    char linie[200];
    char categorie[5];
    int locuri;
    char nume[50],cutie[20],combustibil[20];
    double pret;
    int nr_usi;
    char reducere[20],navigatie[30];
    int nr_bagaje;
    ifstream f("masini_clasice.txt");
    while(f.getline (linie,200))
    {
        char*p = strtok(linie,",\n");
        int j=0;
        while(p)
        {
            switch (j) {
                case 0:
                    break;
                case 1:
                    strcpy(categorie,p);
                    break;
                case 2:
                    strcpy(nume,p);
                    break;
                case 3:
                    strcpy(cutie,p);
                    break;
                case 4:
                    strcpy(combustibil,p);
                    break;
                case 5:
                    pret= atoi(p);
                    break;
                case 6:
                    nr_usi=atoi(p);
                    break;
                case 7:
                    locuri= atoi(p);
                    break;
                case 8:
                    nr_bagaje=atoi(p);
                    break;
                case 9:
                    strcpy(reducere,p);
                    break;
                case 10:
                    strcpy(navigatie,p);
                    break;
            }
            j++;
            p= strtok(nullptr,",\n");
        }
        a[k++]=new Standard(categorie,locuri,nume,cutie,combustibil,pret,nr_usi,nr_bagaje,reducere,navigatie);
    }
    return a;
}

//citirea fisier masini offroad
Offroad** citirefisier2()
{
    Offroad** a=new Offroad*[100];
    int k=0;
    char linie[200];
    char categorie[5];
    int locuri;
    char nume[50],cutie[20],combustibil[20];
    double pret;
    int nr_usi;
    char troliu[20],carlig[30];
    double inaltime,motor;
    ifstream f("masini_offroad.txt");
    while(f.getline (linie,200))
    {
        char*p = strtok(linie,",\n");
        int j=0;
        while(p)
        {
            switch (j) {
                case 0:
                    break;
                case 1:
                    strcpy(categorie,p);
                    break;
                case 2:
                    strcpy(nume,p);
                    break;
                case 3:
                    strcpy(cutie,p);
                    break;
                case 4:
                    strcpy(combustibil,p);
                    break;
                case 5:
                    pret= atoi(p);
                    break;
                case 6:
                    nr_usi=atoi(p);
                    break;
                case 7:
                    locuri= atoi(p);
                    break;
                case 8:
                    strcpy(troliu,p);
                    break;
                case 9:
                    strcpy(carlig,p);
                    break;
                case 10:
                    inaltime=atoi(p);
                    break;
                case 11:
                    motor=atoi(p);
                    break;
            }
            j++;
            p= strtok(nullptr,",\n");
        }
        a[k++]=new Offroad(categorie,locuri,nume,cutie,combustibil,pret,nr_usi,troliu,carlig,motor,inaltime);
    }
    return a;
}

//citire datelor din fisierul masini Premium
Premium** citirefisier3()
{
    Premium** a=new Premium*[100];
    int k=0;
    char linie[200];
    char categorie[5];
    int locuri;
    char nume[50],cutie[20],combustibil[20];
    double pret;
    int nr_usi;
    char transmisie[20],pilot_automat[30];
    double putere,capacitate_cilindrica;
    ifstream f("masini_premium.txt");
    while(f.getline (linie,200))
    {
        char*p = strtok(linie,",\n");
        int j=0;
        while(p)
        {
            switch (j) {
                case 0:
                    break;
                case 1:
                    strcpy(categorie,p);
                    break;
                case 2:
                    strcpy(nume,p);
                    break;
                case 3:
                    strcpy(cutie,p);
                    break;
                case 4:
                    strcpy(combustibil,p);
                    break;
                case 5:
                    pret= atoi(p);
                    break;
                case 6:
                    nr_usi=atoi(p);
                    break;
                case 7:
                    locuri= atoi(p);
                    break;
                case 8:
                    strcpy(transmisie,p);
                    break;
                case 9:
                    strcpy(pilot_automat,p);
                    break;
                case 10:
                    putere=atoi(p);
                    break;
                case 11:
                    capacitate_cilindrica=atoi(p);
                    break;
            }
            j++;
            p= strtok(nullptr,",\n");
        }
        a[k++]=new Premium(categorie,locuri,nume,cutie,combustibil,pret,nr_usi,putere,capacitate_cilindrica,transmisie,pilot_automat);
    }
    return a;
}

//citire sir Masini
Masini** citire(int n)
{
    Masini** a=new Masini*[n];
    char categorie[5];
    int locuri;
    char nume[50],cutie[20],combustibil[20];
    double pret;
    int nr_usi;
    for(int i=0;i<n;i++)
    {
        cout<<"Categorie: ";cin.getline(categorie,5);
        cout<<"Nume: ";cin.getline(nume,50);
        cout<<"Cutie: ";cin.getline(cutie,20);
        cout<<"Combustibil: ";cin.getline(combustibil,20);
        cout<<"Pret: ";cin>>pret;
        cout<<"Locuri: ";cin>>locuri;
        cout<<"Numar usi: ";cin>>nr_usi;
        cin.get();
        a[i]=new Masini(categorie,locuri,nume,cutie,combustibil,pret,nr_usi);
    }
    return a;
}

//citire clasa Standard
Standard** citire2(int n)
{
    Standard** a=new Standard*[n];
    char categorie[5];
    int locuri;
    char nume[50],cutie[20],combustibil[20];
    double pret;
    int nr_usi;
    char reducere[20],navigatie[30];
    int nr_bagaje;
    for(int i=0;i<n;i++)
    {
        cout<<"Categorie: ";cin.getline(categorie,5);
        cout<<"Nume: ";cin.getline(nume,50);
        cout<<"Cutie: ";cin.getline(cutie,20);
        cout<<"Combustibil: ";cin.getline(combustibil,20);
        cout<<"Navigatie: ";cin.getline(navigatie,30);
        cout<<"Reducere: ";cin.getline(reducere,20);
        cout<<"Pret: ";cin>>pret;
        cout<<"Locuri: ";cin>>locuri;
        cout<<"Numar usi: ";cin>>nr_usi;
        cout<<"Numar loc bagaje: ";cin>>nr_bagaje;
        cin.get();
        a[i]=new Standard(categorie,locuri,nume,cutie,combustibil,pret,nr_usi,nr_bagaje,reducere,navigatie);
    }
    return a;
}