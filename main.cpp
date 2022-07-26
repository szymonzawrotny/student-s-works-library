#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <string>
using namespace std;
int numerPracy = 1,kopiaLiczbyPrac;
int liczbaPrac = 0,inz = 0,mgr = 0,lic = 0;

class Praca{
public:
    int id;
    string typPracy;
    string tytul;
    string nazwiskoAutora;
    string imionaAutora;
    int rok;
    string nazwiskoPromotora;
    string imionaPromotora;
    string slowaKluczowe;
    string streszczenie;
    void setter(){
        id = numerPracy;
        cout<<"Podaj typ pracy(dopuszczalne typy to: \"inz\",\"lic\",\"mgr\"): ";
        cin>>typPracy;
        while(typPracy != "inz" && typPracy != "lic" && typPracy != "mgr"){
            cin.clear();
            cin.ignore(1024,'\n');
            cout<<"Niedozwolony typ pracy, podaj ponownie: ";
            cin>>typPracy;
        }

        cout<<"Podaj tytul: ";
        cin.clear();
        cin.ignore(1024,'\n');
        getline(cin,tytul);

        cout<<"Podaj nazwisko autora: ";
        cin>>nazwiskoAutora;

        cout<<"Podaj imiona autora: ";
        cin.clear();
        cin.ignore(1024,'\n');
        getline(cin,imionaAutora);

        cout<<"Podaj rok powstania(musi byc wiekszy od 2000): ";
        cin>>rok;
        while(rok<2000){
            cin.clear();
            cin.ignore(1024,'\n');
            cout<<"Rok pracy nie moze byc wczesniejszy niz 2000, podaj ponownie: ";
            cin>>rok;
        }

        cout<<"Podaj nazwisko promotora pracy: ";
        cin>>nazwiskoPromotora;

        cout<<"Podaj imiona promotora: ";
        cin.clear();
        cin.ignore(1024,'\n');
        getline(cin,imionaPromotora);

        cout<<"Podaj slowa kluczowe: ";
        cin.clear();
        cin.ignore(1024,'\n');
        getline(cin,slowaKluczowe);

        cout<<"Podaj streszczenie pracy: ";
        cin.clear();
        cin.ignore(1024,'\n');
        getline(cin,streszczenie);
    }
};
class Biblioteka{
    fstream plik;
    int ilosPrac;
    Praca *tab;
    public:
        void showAll(){
            plik.open("biblioteka.dat",ios::in);
            if(plik.good()){
                string line;
                cout<<"LISTA PRAC: \n"<<"-----------\n\n";
                while(getline(plik,line)){
                    cout<<line<<endl;
                }
                plik.close();
            }
            else{
                cout<<"sorki cos nie dziala"<<endl;
            }
        }

        void showShort(){
            cout<<"LISTA PRAC:\n----------\n";
            for(int i=0;i<kopiaLiczbyPrac;i++){
                cout<<tab[i].id<<" "<<tab[i].typPracy<<" "<<tab[i].imionaAutora<<" \""<<tab[i].tytul<<"\" "<<tab[i].rok<<endl;
            }
        }

        void wyszukiwanie(){
            cout<<"Dostepne opcje:\n--------------\n";
            cout<<"1. Nazwisko autora\n";
            cout<<"2. Nazwisko promotora\n";
            cout<<"3. Tutul\n";
            cout<<"4. Slowo kluczowe\n";
            cout<<"5. Streszczenia\n";
            cout<<"6. Roku powstania\n";
            int wybor;
            cout<<"Wybierz kryterium:";
            wybor=getch();
            switch(wybor){
                case '1':{
                    system("cls");
                    cout<<"Wedlug nazwiska autora:\nWprowadz wartosc: ";
                    string wartosc;
                    cin>>wartosc;
                    for(int i=0;i<kopiaLiczbyPrac;i++){
                        if(tab[i].imionaAutora.find(wartosc) != string::npos){
                            cout<<tab[i].id<<" "<<tab[i].typPracy<<" "<<tab[i].imionaAutora<<" \""<<tab[i].tytul<<"\" "<<tab[i].rok<<endl;
                        }
                    }
                }break;
                case '2':{
                    system("cls");
                    cout<<"Wedlug nazwiska promotora:\nWprowadz wartosc: ";
                    string wartosc;
                    cin>>wartosc;
                    for(int i=0;i<kopiaLiczbyPrac;i++){
                        if(tab[i].imionaPromotora.find(wartosc) != string::npos){
                            cout<<tab[i].id<<" "<<tab[i].typPracy<<" "<<tab[i].imionaAutora<<" \""<<tab[i].tytul<<"\" "<<tab[i].rok<<endl;
                        }
                    }
                }break;
                case '3':{
                    system("cls");
                    cout<<"Wedlug tytulu:\nWprowadz wartosc: ";
                    string wartosc;
                    cin>>wartosc;
                    for(int i=0;i<kopiaLiczbyPrac;i++){
                        if(tab[i].tytul.find(wartosc) != string::npos){
                            cout<<tab[i].id<<" "<<tab[i].typPracy<<" "<<tab[i].imionaAutora<<" \""<<tab[i].tytul<<"\" "<<tab[i].rok<<endl;
                        }
                    }
                }break;
                case '4':{
                    system("cls");
                    cout<<"Wedlug slowa kluczowego:\nWprowadz wartosc: ";
                    string wartosc;
                    cin>>wartosc;
                    for(int i=0;i<kopiaLiczbyPrac;i++){
                        if(tab[i].slowaKluczowe.find(wartosc) != string::npos){
                            cout<<tab[i].id<<" "<<tab[i].typPracy<<" "<<tab[i].imionaAutora<<" \""<<tab[i].tytul<<"\" "<<tab[i].rok<<endl;
                        }
                    }
                }break;
                case '5':{
                    system("cls");
                    cout<<"Wedlug streszczenia:\nWprowadz wartosc: ";
                    string wartosc;
                    cin>>wartosc;
                    for(int i=0;i<kopiaLiczbyPrac;i++){
                        if(tab[i].streszczenie.find(wartosc) != string::npos){
                            cout<<tab[i].id<<" "<<tab[i].typPracy<<" "<<tab[i].imionaAutora<<" \""<<tab[i].tytul<<"\" "<<tab[i].rok<<endl;
                        }
                    }
                }break;
                case '6':{
                    system("cls");
                    cout<<"Wedlug roku powstania:\nWprowadz wartosc: ";
                    int wartosc;
                    cin>>wartosc;
                    for(int i=0;i<kopiaLiczbyPrac;i++){
                        if(tab[i].rok == wartosc){
                            cout<<tab[i].id<<" "<<tab[i].typPracy<<" "<<tab[i].imionaAutora<<" \""<<tab[i].tytul<<"\" "<<tab[i].rok<<endl;
                        }
                    }

                }break;
                default: {
                    cout<<"cos zle wybrales:\n";
                    exit(0);
                }break;
                }
        }

        void edytowanie(){
            cout<<"Dostepne opcje:\n--------------\n";
            cout<<"1. Nazwisko autora\n";
            cout<<"2. Nazwisko promotora\n";
            cout<<"3. Tutul\n";
            cout<<"4. Slowo kluczowe\n";
            cout<<"5. Streszczenia\n";
            cout<<"6. Roku powstania\n";
            int wybor;
            cout<<"Wybierz kryterium:";
            wybor=getch();
            switch(wybor){
                case '1':{
                    system("cls");
                    cout<<"Edytuj nazwisko autora:\nPodaj id pracy: ";
                    int wartosc;
                    cin>>wartosc;
                    cout<<"Podaj wartosc:";
                    string noweDane;
                    cin>>noweDane;
                    for(int i=0;i<kopiaLiczbyPrac;i++){
                        if(tab[i].id == wartosc){
                            tab[i].imionaAutora = noweDane;
                        }
                    }
                }break;
                case '2':{
                    system("cls");
                    cout<<"Edytuj nazwisko promotora:\nPodaj id pracy: ";
                    int wartosc;
                    cin>>wartosc;
                    cout<<"Podaj wartosc:";
                    string noweDane;
                    cin>>noweDane;
                    for(int i=0;i<kopiaLiczbyPrac;i++){
                        if(tab[i].id == wartosc){
                            tab[i].imionaPromotora = noweDane;
                        }
                    }
                }break;
                case '3':{
                    system("cls");
                    cout<<"Edytuj tytul:\nPodaj id pracy: ";
                    int wartosc;
                    cin>>wartosc;
                    cout<<"Podaj wartosc:";
                    string noweDane;
                    cin.clear();
                    cin.ignore(1024,'\n');
                    getline(cin,noweDane);
                    for(int i=0;i<kopiaLiczbyPrac;i++){
                        if(tab[i].id == wartosc){
                            tab[i].tytul = noweDane;
                        }
                    }
                }break;
                case '4':{
                    system("cls");
                    cout<<"Edytuj slowo kluczowe:\nPodaj id pracy: ";
                    int wartosc;
                    cin>>wartosc;
                    cout<<"Podaj wartosc:";
                    string noweDane;
                    cin>>noweDane;
                    for(int i=0;i<kopiaLiczbyPrac;i++){
                        if(tab[i].id == wartosc){
                            tab[i].slowaKluczowe = noweDane;
                        }
                    }
                }break;
                case '5':{
                    system("cls");
                    cout<<"Edytuj streszczenie:\nPodaj id pracy: ";
                    int wartosc;
                    cin>>wartosc;
                    cout<<"Podaj wartosc:";
                    string noweDane;
                    cin>>noweDane;
                    for(int i=0;i<kopiaLiczbyPrac;i++){
                        if(tab[i].id == wartosc){
                            tab[i].streszczenie = noweDane;
                        }
                    }
                }break;
                case '6':{
                    system("cls");
                    cout<<"Edytuj rok powstania:\nPodaj id pracy: ";
                    int wartosc;
                    cin>>wartosc;
                    cout<<"Podaj wartosc:";
                    int noweDane;
                    cin>>noweDane;
                    while(noweDane<2000){
                        cin.clear();
                        cin.ignore(1024,'\n');
                        cout<<"Rok pracy nie moze byc wczesniejszy niz 2000, podaj ponownie: ";
                        cin>>noweDane;
                    }
                    for(int i=0;i<kopiaLiczbyPrac;i++){
                        if(tab[i].id == wartosc){
                            tab[i].rok = noweDane;
                        }
                    }
                }break;
                default: {
                    cout<<"cos zle wybrales:\n";
                    exit(0);
                }break;
                }

            plik.open("biblioteka.dat",ios::out);
            if(plik.good()){
                    for(int i=0;i<kopiaLiczbyPrac;i++){
                     plik<<"---------------------------------------\n";
                        plik<<"1.Id: "<<tab[i].id<<endl;
                        plik<<"2.Typ: "<<tab[i].typPracy<<endl;
                        plik<<"3.Autor: "<<tab[i].imionaAutora<<endl;
                        plik<<"4.Tytul: "<<tab[i].tytul<<endl;
                        plik<<"5.Slowa kluczowe: "<<tab[i].slowaKluczowe<<endl;
                        plik<<"6.Rok: "<<tab[i].rok<<endl;
                        plik<<"7.Promotor: "<<tab[i].imionaPromotora<<endl;
                        plik<<"8.Streszczenie: "<<tab[i].streszczenie<<endl;
                        plik<<"---------------------------------------\n";
                    }
                plik.close();
            }
            else{
                cout<<"sorki cos nie dziala"<<endl;
            }
        }

        void zapisDoTablicy(){
            tab = new Praca[kopiaLiczbyPrac];
            plik.open("biblioteka.dat",ios::in);
            if(plik.good()){
                for(int i=0;i<kopiaLiczbyPrac;i++){
                    for(int j=0;j<10;j++){
                        string line;
                        getline(plik,line);
                        for(int k=0;k<line.size();k++){
                            if(line[k]=='1' && line[k+1]=='.'){
                                string z;
                                z+= line[k+6];
                                tab[i].id = stoi(z);
                            }
                            else if(line[k]=='2' && line[k+1]=='.'){
                                string z;
                                for(int l=7;l<10;l++){
                                    z+=line[l];
                                }
                                tab[i].typPracy = z;
                            }
                            else if(line[k]=='3' && line[k+1]=='.'){
                                string z;
                                for(int l=9;l<line.size();l++){
                                    z+=line[l];
                                }
                                tab[i].imionaAutora = z;

                            }
                            else if(line[k]=='4' && line[k+1]=='.'){
                                string z;
                                for(int l=9;l<line.size();l++){
                                    z+=line[l];
                                }
                                tab[i].tytul = z;
                            }
                            else if(line[k]=='5' && line[k+1]=='.'){
                                    string z;
                                for(int l=18;l<line.size();l++){
                                    z+=line[l];
                                }
                                tab[i].slowaKluczowe = z;
                            }
                            else if(line[k]=='6' && line[k+1]=='.'){
                                string z;
                                for(int l=7;l<11;l++)
                                    z+=line[k+l];
                                tab[i].rok = stoi(z);
                            }
                            else if(line[k]=='7' && line[k+1]=='.'){
                                string z;
                                for(int l=12;l<line.size();l++){
                                    z+=line[l];
                                }
                                tab[i].imionaPromotora = z;
                            }
                            else if(line[k]=='8' && line[k+1]=='.'){
                                string z;
                                for(int l=16;l<line.size();l++){
                                    z+=line[l];
                                }
                                tab[i].streszczenie = z;
                            }
                        }
                    }
                }
                plik.close();
            }
            else{
                cout<<"sorki cos nie dziala"<<endl;
            }
            numerPracy = tab[kopiaLiczbyPrac-1].id + 1;
        }

        void howMany(){
            plik.open("biblioteka.dat",ios::in);
            if(plik.good()){
                string line;
                while(getline(plik,line)){
                    for(int i=0;i<line.size();i++){
                        if(line[i]=='I' && line[i+1]=='d')
                            liczbaPrac++;
                    }
                }
                for(int i=0;i<kopiaLiczbyPrac;i++){
                    if(tab[i].typPracy=="inz"){
                        inz++;
                    }
                    else if(tab[i].typPracy=="lic"){
                        lic++;
                    }
                    else if(tab[i].typPracy=="mgr"){
                        mgr++;
                    }
                }
                cout<<"Ilosc wszystkich prac w bibliotece: "<<liczbaPrac<<endl;
                cout<<"Ilosc prac inzynierskich: "<<inz<<endl;
                cout<<"Ilosc prac licencjackich: "<<lic<<endl;
                cout<<"Ilosc prac magisterskich: "<<mgr<<endl;
                kopiaLiczbyPrac = liczbaPrac;
                liczbaPrac = 0;
                mgr = 0;
                inz = 0;
                lic = 0;
                plik.close();
            }
            else{
                cout<<"sorki cos nie dziala"<<endl;
            }
        }

        void ileProm(){
            for(int i=0;i<kopiaLiczbyPrac;i++){
                int ile = 0;
                for(int j=0;j<kopiaLiczbyPrac;j++){
                    if(tab[i].imionaPromotora == tab[j].imionaPromotora)
                        ile++;
                }
                cout<<tab[i].imionaPromotora<<": "<<ile<<endl;
            }
        }

        void slowaKluczowe(){

        }

        void addNew(Praca obiekt){
            plik.open("biblioteka.dat",ios::app);
            if(plik.good()){
                plik<<"---------------------------------------\n";
                plik<<"1.Id: "<<obiekt.id<<endl;
                plik<<"2.Typ: "<<obiekt.typPracy<<endl;
                plik<<"3.Autor: "<<obiekt.imionaAutora<<" "<<obiekt.nazwiskoAutora<<endl;
                plik<<"4.Tytul: "<<obiekt.tytul<<endl;
                plik<<"5.Slowa kluczowe: "<<obiekt.slowaKluczowe<<endl;
                plik<<"6.Rok: "<<obiekt.rok<<endl;
                plik<<"7.Promotor: "<<obiekt.imionaPromotora<<" "<<obiekt.nazwiskoPromotora<<endl;
                plik<<"8.Streszczenie: "<<obiekt.streszczenie<<endl;
                plik<<"---------------------------------------\n";

                plik.close();
            }
            else{
                cout<<"sorki cos nie dziala"<<endl;
            }
        }
};
void podMenu(){
    Praca obiekt;
    Biblioteka obiektB;
    obiektB.zapisDoTablicy();
    cout<<"DODATKOWE OPCJE:\n----------------\n";
    cout<<"1. Ilosc prac\n";
    cout<<"2. Lista prac dla poszczegolnych promotorow\n";
    int wybor;
    cout<<"Wybierz: ";
    wybor=getch();
    switch(wybor){
        case '1': {
            system("cls");
            obiektB.howMany();
        }
        break;
        case '2': {
            system("cls");
            obiektB.ileProm();
        }
        break;
        default: {
            cout<<"cos zle wybrales";
            exit(0);
            }
            break;
    }
}
void interfejs(){
    Praca obiekt;
    Biblioteka obiektB;
    fstream plik;
    plik.open("biblioteka.dat",ios::in);
            if(plik.good()){
                string line;
                while(getline(plik,line)){
                    for(int i=0;i<line.size();i++){
                        if(line[i]=='I' && line[i+1]=='d')
                            liczbaPrac++;
                    }
                }
                kopiaLiczbyPrac = liczbaPrac;
                liczbaPrac = 0;
                plik.close();
            }
            else{
                cout<<"sorki cos nie dziala"<<endl;
            }
    obiektB.zapisDoTablicy();
    cout<<"Dzien dobry witam w programie \"Biblioteka prac dyplomowych\"\n";
    cout<<"MENU GLOWNE\n-----------\n";
    cout<<"1. Dodaj prace\n";
    cout<<"2. Wyswietl prace(pelny format)\n";
    cout<<"3. Wyswietl prace(skrocony format)\n";
    cout<<"4. Wyszukaj prace\n";
    cout<<"5. Edytuj Prace\n";
    cout<<"6. Dodatkowe\n";
    cout<<"7. Wyjscie\n\n";

    int wybor;
    cout<<"Wybierz: ";
    wybor=getch();
    switch(wybor){
        case '1': {
            system("cls");
            obiekt.setter();
            obiektB.addNew(obiekt);
        }break;
        case '2': {
            system("cls");
            obiektB.showAll();
        }break;
        case '3': {
            system("cls");
            obiektB.showShort();
        }break;
        case '4': {
            system("cls");
            obiektB.wyszukiwanie();
        }break;
        case '5': {
            system("cls");
            obiektB.edytowanie();
        }break;
        case '6': {
            system("cls");
            podMenu();
        }break;
        case '7': exit(0);
        default: {
                cout<<"cos zle wybrales";
                exit(0);
            }break;
    }
    getch();
    system("cls");
}
int main(){
    for(;;)
    interfejs();
    return 0;
}
