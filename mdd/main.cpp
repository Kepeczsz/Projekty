#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;

class Funkcje_matematyczne
{
    public:
        unsigned long long n;
        int b,p;
        void Metoda_Naiwna1(unsigned long long n);
        void Metoda_Naiwna2(unsigned long long n);
        void Odwrocone_tw_wilsona(unsigned long long n);
        int Odwrocone_mal_tw_Fermata(int b,int p);

};
void Funkcje_matematyczne::Metoda_Naiwna1(unsigned long long n)
{

    unsigned long long flag=0;
    for(unsigned long long i =1; i <= n-1; i++ )
    {

        if(n%i==0)
        {
            flag++;
            continue;
        }else break;
    }
    if(flag>1)
    {
        cout<<"Liczba ta, nie jest liczba pierwsza"<<endl;
    }else cout << "Liczba jest pierwsza"<<endl;
};
void Funkcje_matematyczne::Metoda_Naiwna2(unsigned long long n)
{   unsigned long long flag=0;
    for(unsigned long long i =1; i <= sqrt(n); i++ )
    {
        if(n%i==0)
        {
            flag++;
            continue;
        }else break;
    }
    if(flag>1)
    {
        cout<<"Z drugiego twierdzenia Liczba nie jest pierwsza"<<endl;
    }else cout << "Z drugiego twierdzenia liczba  jest pierwsza"<<endl;
}

void Funkcje_matematyczne::Odwrocone_tw_wilsona(unsigned long long n)
{
    unsigned long  silnia=1;
    for (unsigned long  i = 1; i<n;i++)
    {
        silnia *= i;
    }

    if(n>1 && ((silnia+1)%n))
    {
        cout << "Z twierdzenia wilsona liczba NIE jest pierwsza" << endl;
    }else cout << "Z Tw wilsona liczba  jest pierwsza" << endl;
}
int Funkcje_matematyczne::Odwrocone_mal_tw_Fermata(int b,int p)
{
    unsigned long x;
    x = pow(b,p);
    if((x-b)%p==0)
    {
        cout << "Z tw mal fermata liczba jest pierwsza";
    } else cout << "Z tw mal fermata liczba nie jest pierwsza";

};


int main()
{
    Funkcje_matematyczne a;
    unsigned long long n;
    int b,p;

    cin >> n;

    auto start = std::chrono::steady_clock::now();
    a.Metoda_Naiwna1(n);
    auto duration = std::chrono::steady_clock::now() - start;
    auto start1 = std::chrono::steady_clock::now();
    a.Metoda_Naiwna2(n);
    auto duration1 = std::chrono::steady_clock::now() - start;
    auto start2 = std::chrono::steady_clock::now();
    a.Odwrocone_tw_wilsona(n);
    auto duration2 = std::chrono::steady_clock::now() - start;
    cout << "Podaj dwie liczby do tw Fermata"<<endl;
    cin >> b >> p;
    auto start3 = std::chrono::steady_clock::now();
    a.Odwrocone_mal_tw_Fermata(b,p);
    auto duration3 = std::chrono::steady_clock::now() - start;

    cout << " czas trwania Naiwna1:" << duration.count()  << endl
         << "czas trwania Naiwna2:" << duration1.count()  << endl
         << "czas trwania Tw wilsona:"<< duration2.count()<< endl
         << "czas trwania Fermata:" << duration3.count();

    return 0;
}
