#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Probka
{
    double t;
    double x;
    Probka (double t1, double x1)
    {
    t=t1;
    x=x1;
    }
};


typedef vector<Probka> Dane;
Dane wczytaj (string nazwa_pliku)
{
    Dane tablica;
    ifstream plik(nazwa_pliku);
    string linia;
    while (getline(plik,linia))
    {
        double x,t;
        stringstream ss(linia);
        ss>>t;
        ss.ignore();
        ss>>x;
        Probka probka1(t,x);
        tablica.push_back(probka1);

    }
    plik.close();
    return tablica;
}

void zapisz (string nazwa_pliku, Dane dane)
{
    ofstream zapis(nazwa_pliku);
    for(int i=0;i<dane.size();i++)
    {
        zapis<<dane[i].x<<" "<<dane[i].t<<endl;
    }
    zapis.close();
}

double Srednia (Dane dane) {
    double srednia = 0.0;
    for (int i = 0; i < dane.size(); i++) {
        srednia += dane[i].x;
    }
    if (dane.size() > 0) {
        srednia = srednia / dane.size();
    }
    return srednia;
}

double Minimum(Dane dane) {
    double minimum = 2;
    for ( int i=0; i<dane.size(); i++) {
        if (dane[i].x < minimum)
            minimum = dane[i].x;
    }
    return minimum;
}

double Maksimum(Dane dane) {
    double maksimum = -2;
    for ( int i=0; i<dane.size(); i++) {
        if (dane[i].x > maksimum)
            maksimum = dane[i].x;
    }
    return maksimum;
}

double Calka(Dane dane) {
    double calka = 0, dt = 0, dpole = 0;
    for (int i=1; i < dane.size()-1; i++)
    {
        dt = dane[i+1].x - dane[i].t;
        dpole = (dane[i].x + dane[i+1].x) * dt / 2;
        calka = calka + dpole;
    }
    return calka;
}

int main(int argc, char*argv[])
{
    if(argc !=2)
    {
        return -1;
    }
    cout<<argv[1]<<endl;
    Dane dane = wczytaj(argv[1]);
    zapisz("out.csv",dane);
    cout<<endl<<"Srednia: "<<Srednia(dane);
    cout<<endl<<"Minimum: "<<Minimum(dane);
    cout<<endl<<"Maksimum: "<<Maksimum(dane);
    cout<<endl<<"Calka: "<<Calka(dane);
    return 0;
}
