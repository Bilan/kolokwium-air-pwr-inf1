#include <stdio.h>

// funkcja wczytujaca
int wczytaj(int ilosc, int tab[])
{
    printf("\n\nPodaj %d liczb. Po wpisaniu wcisnij enter.\n\n", ilosc);
    int i; 
    for(i=0; i<ilosc; i++)
        scanf("%d", &tab[i]);
}

//funkcja wyswietlajaca
int wyswietl(int tablica[], int ilosc)
{
    int i;
    for(i=0; i<ilosc; i++)
    {
        printf("%d ", tablica[i]);
    }
    printf("\n\n");
}

//funkcja liczaca srednie
int srednia(int tablica[], int ilosc)
{
    int i;
    int suma = 0;
    float srednia;
    int iloscliczb = 0;
    
    for (i=0; i<ilosc; i++)
    {   
        if (tablica[i]%2 != 0) {
            suma = suma+tablica[i];
            iloscliczb = iloscliczb + 1;
        }
    }
    srednia = suma/iloscliczb;
    printf("\n\nSrednia podanych liczb nieparzystych to %f \n\n", srednia);
}

//funkcja odwracajaca
void odwroc(int tab1[], int ilosc){
     int i;
     for (i=0; i<ilosc/2; i++){
         int t = tab1[i];
         tab1[i] = tab1[ilosc-1-i];
         tab1[ilosc-1-i] = t;
     } 
}

//funkcja glowna
int main(void)
{
    printf("Kolokwium 07.05.2012.\nAutor: Jakub Bilan, nr indeksu: 194453. \n\n");
    
    char menu;
    int tab[14];
    int i;
    int ilosc;
    
    while(1)
    {
         printf("Menu:\na. wczytaj nowy zestaw danych\nb. wyswietl wszystkie dane z tablicy\nc. oblicz srednia arytmetyczna nieparzystych wyrazow\nd. odwroc kolejnosc\ne. zakoncz program\n\n");
         scanf("\n %c", &menu);
         
         if (menu=='e') break;
         
         switch (menu){
           case 'a':
                
                do
                {
                printf("Podaj ile liczb chcesz wczytac (max 15): \n\n");
                scanf("\n %d", &ilosc);
                if(ilosc>15) printf("Podales zbyt duza ilosc liczb. Sprobuj ponownie.\n\n");
                }
                while(ilosc>15);

                wczytaj(ilosc, tab);
                printf("\n\nPodales nastepujace dane: \n\n");
                
                wyswietl(tab, ilosc);
                printf("\n\nCo chcesz dalej zrobic? \n\n");
                
                break;
                
           case 'b':
                printf("\nPodales nastepujacy zestaw danych: \n\n");
                wyswietl(tab, ilosc);
                printf("\n\nCo chcesz dalej zrobic? \n\n");
                break;
                
           case 'c':
                
                srednia(tab, ilosc);
                printf("\n\nCo chcesz dalej zrobic? \n\n");
                break;
                
           case 'd':
                
                odwroc(tab, ilosc);
                printf("Odwrocone elementy tablicy wygladaja nastepujaco: \n");
                wyswietl(tab, ilosc);
                printf("\n\nCo chcesz dalej zrobic? \n\n");
                break;
           dafault:
                printf("Opcja nieznana \n");
                break;
         }
    }
    
    system("PAUSE");
    return 0;
}
