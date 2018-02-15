#include <iostream>

using namespace std;

void WyswietlHistorieFaktur(float tab[],int aktualnyIndeks);
float ObliczSrednia(float wartosciFaktur[], int aktualnyIndeks );
bool MaConajmniejTrzyFaktury(int aktualnyIndeks);
void PoinformujKlientaZeNieNalezySieRabat();

int main()
{
float wartosc = 0;
float wartosciFaktur[10];
int LicznikPetli = 0;
float srednia = 0;
float suma = 0;
string Odpowiedz ;
string Potwierdzenie= "t";
int aktualnyIndeks = 0;

do
{
    cout<<LicznikPetli<<endl;
    LicznikPetli = LicznikPetli +1;
    aktualnyIndeks = LicznikPetli -1;
    cout<< "Podaj wartosc ostatniej faktury"<<endl;
    cin>>wartosc;
    wartosciFaktur[aktualnyIndeks] = wartosc;

    if(MaConajmniejTrzyFaktury(aktualnyIndeks))
    {
        srednia = ObliczSrednia(wartosciFaktur,aktualnyIndeks );

        if(srednia >= 300)
        {
            cout<<"Nalezy sie rabat 10% "<<endl;
        }
        else
        {
            PoinformujKlientaZeNieNalezySieRabat();
        }
    }
    else
    {
       PoinformujKlientaZeNieNalezySieRabat();
    }

    cout<<"Czy chcesz zobaczyc historie? t/n"<<endl;
    cin>> Odpowiedz;
    if(Odpowiedz ==Potwierdzenie)
    {
        WyswietlHistorieFaktur(wartosciFaktur,aktualnyIndeks);
    }

    cout<<"Czy chcesz wyjsc z programu? t/n "<<endl;
    cin>> Odpowiedz ;
}
while(Odpowiedz !=Potwierdzenie);

    return 0;

}

void PoinformujKlientaZeNieNalezySieRabat()
{
    cout<<"Nie nalezy Ci się rabat, kupuj wiecej"<<endl;
}

bool MaConajmniejTrzyFaktury(int aktualnyIndeks)
{
    bool MaConajmniejTrzyFaktury;
    MaConajmniejTrzyFaktury = aktualnyIndeks -2 >= 0;
    return MaConajmniejTrzyFaktury ;
}

float ObliczSrednia(float wartosciFaktur[], int aktualnyIndeks )
{
    float suma;
    float srednia;

    suma = wartosciFaktur[aktualnyIndeks];

    suma = suma + wartosciFaktur[aktualnyIndeks -1];

    suma = suma + wartosciFaktur[aktualnyIndeks -2];

    srednia = suma / 3 ;

    return srednia;
}

void WyswietlHistorieFaktur(float tab[],int aktualnyIndeks)
{
    for(int i=0; i<=aktualnyIndeks; i++)
    {
        cout<<tab[i]<<endl;
    }


}