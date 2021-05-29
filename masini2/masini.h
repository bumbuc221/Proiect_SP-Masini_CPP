#ifndef MASINI_MASINI_H
#define MASINI_MASINI_H
#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

class Masini {
protected:
    int id_v;
    char* categorie;
    int locuri;
    char* nume,*cutie,*combustibil;
    double pret;
    int nr_usi;
    int valid;
public:
    static int id;
    Masini(char*categorie,int locuri,char*nume,char*cutie,char* combustibil,double pret,int nr_usi);
    Masini(const Masini& a);
    Masini& operator=(const Masini&a);
    int get_locuri();
    char* get_cutie();
    char* get_combustibil();
    void delete_();
    virtual ~Masini();
    virtual ostream& afisare(ostream&a)const;
    int get_usi();
    void init(const Masini&a);
    virtual int get_id()const{return id_v;}
    char* get_categorie(){return categorie;}
    friend ostream& operator<<(ostream&st,const Masini&a);
    char* get_nume()
    {
        return nume;
    }
    virtual double get_pret()
    {
        return pret;
    }
     void set_valid(int n)
    {
        if(n==0)
        valid=0;
        else
            valid=1;
    }
    int get_valid()
    {
        return valid;
    }
    void set_id(int n)
    { id_v=n;}
};

//categorie de masina Standarda cu buget mediu
class Standard:public Masini {
    int locuri_bagaje;
    char *reducere;
    char *navigatie;
    int nr;
public:
    static int serie;
    Standard(char *categorie, int locuri, char *nume, char *cutie, char *combustibil, double pret, int nr_usi,int locuri_bagaje,char* reducere,char* navigatie);
    Standard(const Standard&a);
    Standard& operator=(const Standard&a);
    char* get_reducere(){return reducere;}
    ostream& afisare(ostream& a)const;
    int get_loc_bagaje(){return locuri_bagaje;}
    friend ostream& operator<<(ostream& st,const Standard&a);
    ~Standard();
    char* get_navigatie(){return navigatie;}
    int get_id()const
    {
        return nr;
    }
};

//categoria de masini off-road
class Offroad:public Masini{
    char* troliu;
    double motor,inaltime;
    char *carlig;
    int nr;
public:
    static int serie;
    char* get_troliu(){return troliu;}
    Offroad(char *categorie, int locuri, char *nume, char *cutie, char *combustibil, double pret, int nr_usi,char* troliu,char* carlig,double motor,double inaltime);
    Offroad(const Offroad&a);
    double get_motor(){return motor;}double get_inaltime(){return inaltime;}
    Offroad& operator=(const Offroad&a);
    ostream& afisare(ostream& a)const;
    char* get_carlig(){return carlig;}
    friend ostream& operator<<(ostream& st,const Offroad&a);
    ~Offroad();
    int get_id() const
    {
        return nr;
    }
};

//categoria de masini premium
class Premium:public Masini{
    int putere,capacitate_cilindrica;
    char* transmisie;
    char* pilot_automat;
    int nr;
public:
    static int serie;
    int get_putere(){return putere;}int get_capacitate(){return capacitate_cilindrica;}
    Premium(char *categorie, int locuri, char *nume, char *cutie, char *combustibil, double pret, int nr_usi,int putere,int capacitate_cilindrica,char* transmisie,char* pilot_automat);
    Premium(const Premium&a);
    char* get_transmisie(){return transmisie;}
    Premium& operator=(const Premium&a);
    ostream& afisare(ostream& a)const;
    char* get_pilot(){return pilot_automat;}
    friend ostream& operator<<(ostream& st,const Premium&a);
    ~Premium();
    int get_id()const
    {
        return nr;
    }
};

//structura Node
class Node{
public:
    char* nume,*data;
    Masini* a;
    Node* next;
    Node(Masini*,char* nume,char* data);
    Node(const Node&);
    ~Node();
};
class Global;
//clasa List
class List{
public:
    Node* head,*tail;
    List();
    ~List();
    void append(Masini* aux,char*,int n,char* d);
    void stergere(Global v,char*nume,char* nume_masina);
    void afis();
    void update_fisier_inchirieri();
    void citire_date();
};
//clasa Global care contine trei siruri cu masini
class Global{
public:
    int l1,l2,l3;
    Standard** a;
    Premium** c;
    Offroad** b;
    Global();
    Global(const Global&);
    ~Global();
    void cautare_seria_A_nume(char *nume);
    void cautare_seria_A_pret(int  pret);
    void cautare_seria_B_nume(char *nume);
    void cautare_seria_B_pret(int  pret);
    void cautare_seria_C_nume(char *nume);
    void cautare_seria_C_pret(int  pret);
    Standard** citire_standard(int n);
    Offroad** citire_offroad(int n);
    Premium** citire_premium(int n);
    void inchiriere(List*,char *seria,int id);
    void update_masini_clasice_fisier();
    void update_masini_offroad_fisier();
    void update_masini_premium_fisier();
};



void meniu();
void optiuni();

Standard** citirefisier1();
Offroad** citirefisier2();
Premium** citirefisier3();
//  Standard** citire2(int n);















#endif //MASINI_MASINI_H
