#include <iostream>

using namespace std;
class Trojkat
{
public: float a,h;
    void Wczytywanie(){
        cin >> a >> h;
    }
    float Pole(){
        float P = (a*h)/2;
        return P;
    }

};
void Porownywanie(Trojkat trojkat1, Trojkat trojkat2)
{
    float P1 = trojkat1.Pole();
    float P2 = trojkat2.Pole();
    if(P1>P2){
        cout << "P1 Ma wieksze pole";
    }
    else if(P1==P2){
        cout << "Maja rowne pola";
    }else cout << "P2 ma wieksze pole";

}
int main()
{
    Trojkat *trojkat1 = new Trojkat;
    Trojkat *trojkat2 = new Trojkat;
    trojkat1 -> Wczytywanie();
    trojkat2 ->Wczytywanie();
    Porownywanie(*trojkat1,*trojkat2);
    delete trojkat1;
    delete trojkat2;

    return 0;
}
