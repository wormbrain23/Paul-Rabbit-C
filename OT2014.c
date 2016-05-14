#include <stdio.h>
#include <stdlib.h> /* potrebne pre: funkciaOA2 */
#include <string.h> /* potrebne pre: funkciaOA1 */
#include <math.h>   /* potrebne pre: funkciaSOA2 */
/* Prepisana jedna strana z pravdepodobne opravneho terminu rocnik 2014. */

/* Napiste funkciu, ktorej vstupom je pole retazcov a retazec 'str'. Funkcia
 * z pola vynecha vsetky retazce, ktore su neskor v lexikografickom poradi ako
 * str. Vrati novu dlzku pola. Napr. pre pole {"zita","andrea","eleonora","blazena"}
 * a str = "bozena" zostane v poli len {"andrea","blazena"} a funkcia vrati 2.
 * HINT: pri porovnavani vyuzite standardnu funkciu na porovnavanie retazcov,
 * pri vynechavani retazcov si uvedomte ze pracujete s polom smernikov. */
int funkciaOA1(char *pole[], char *str, int dlzka_pola) {
    int i=0,j=0,nova_dlzka=0;
    while (i < dlzka_pola) {
        if (strcmp(pole[i],str) < 0) {
            /* retazce, ktore podmienku splnaju sa poposuvaju na zaciatok */
            pole[j] = pole[i];
            j++;
            nova_dlzka++;
        }
        i++;
    }
    while (j < dlzka_pola)
        pole[j++] = NULL; /*zvysne retazce budu prazdne */
    return nova_dlzka;
}

/* Napiste funkciu, ktora postupne zo standardneho vstupu nacita lubovolne
 * dlhy riadok do dynamickeho pola a vrati smernik na vysledny retazec. Znak
 * konca riadka do pola neukladajte. Navod na zakladne riesenie: az kym nedojdete
 * na koniec riadka, nacitavajte znaky po jednom a postupne zvacsujte pole. */
char *funkciaOA2() {
    char *riadok, znak;
    int dlzka_riadku=1, index=0;
    znak = getc(stdin); /* stdin - standardny vstup */
    riadok = malloc(dlzka_riadku);
    if (znak == '\n') { /* ak je koniec riadku hned ako prvy znak */
        riadok[0] = '\0';
        return riadok;
    }
    while (znak != '\n') {
        riadok[index++] = znak;
        dlzka_riadku++;
        riadok = realloc(riadok, dlzka_riadku);
        znak = getc(stdin);
    }
    riadok[index] = '\0';
    return riadok;
}

/* Napiste funkciu, ktorej vstupom je matica pevnych rozmerov NxN. Funkcia
 * vrati index riadku, v ktorom je najvacsi sucet hodnot vsetkych prvkov (v riadku). */
#define N 3
int funkciaOA3(int matica[N][N]) {
    int i=0, j=0, max = 0, sucet = 0, index = 1;
    /* na zaciatku je do maxima ulozeny sucet prveho riadku */
    for (j=0;j<N;j++)
        max += matica[0][j];
    /* hladanie noveho maxima v zvysnych riadkoch */
    for (i=1;i<N;i++) {
        for (j=0;j<N;j++)
            sucet += matica[i][j];
        if (sucet > max) {
            max = sucet;
            index = i;
        }
        sucet = 0;
    }
    return index;
}

/* Napiste funkciu, ktora otvori na citanie subor s menom zadanym ako parameter
 * funkcie. V subore su ulozene realne cisla. Funkcia vrati ich priemernu hodnotu
 * (staci nacitavat cez standardne funkcie pre formatovany vstup zo suboru). Osetrite
 * aj chyby, co mozu pri praci so subormi nastat. */
double funkciaOA4(char *nazov) {
    FILE *file;
    double sucet=0.0, priemer=0.0, akt_hodnota=0.0;
    int pocet=0;
    file = fopen(nazov, "r");
    if (file == NULL) { /* fopen vracia NULL ak nastane chyba */
        printf("Subor sa nepodarilo otvorit.\n");
        exit(1);
    }
    while (fscanf(file, "%lf", &akt_hodnota) > 0) {
        pocet++;
        sucet += akt_hodnota;
    }
    if (fclose(file) != 0) { /* pri spravnom ukonceni fclose vracia 0 */
        printf("Subor sa nepodarilo zatvorit.\n");
        exit(1);
    }
    priemer = sucet/(double)pocet;
    return priemer;
}

/* Definujte strukturu Complex so zlozkami real a imag (realna a imaginarna zlozka
 * kommplexneho cisla). */
typedef struct cmplx{
    double real;
    double imag;
} Complex;
/* Napiste funkciu, ktorej vstupom je komplexne cislo z, a ona vypocita jeho
 * absolutnu hodnotu podla vztahu |(z)|=sqrt(R(z)^2+J(z)^2), kde R(z) je realna
 * cast komplex. cisla a J(z) jeho imaginarna cast. */
double funkciaSOA2(Complex z) {
    return sqrt(z.real*z.real+z.imag*z.imag);
}

/* Napiste funkciu, ktorej vstupom je pole komplexnych cisel. Funkcia ho usporiada
 * podla absolutnej hodnoty. */
void funkciaSOA3(Complex pole[], int dlzka_pola) {
    int i=0,j=0;
    Complex pom_vymena;
    for (i=0;i<dlzka_pola-1;i++)
        for (j=i+1;j<dlzka_pola;j++)
            if (funkciaSOA2(pole[i]) < funkciaSOA2(pole[j])) {
                pom_vymena = pole[i];
                pole[i] = pole[j];
                pole[j] = pom_vymena;
            }
    return;
}

/* Teoreticka otazka: Vyberte si jednu z tem: RETAZEC, SUBOR, STRUKTURA alebo SMERNIK
 * (dalej X). Strucne definujte, co je to X, a uvedte na ake ulohy sa pouziva a akym
 * sposobom (v kontexte programovania v jazyku C).
 * RIESENIE
 * RETAZEC - ide vlastne o postupnost znakov (typ char) ukoncenu znakom '\0', pouziva
 * sa napriklad pri praci so subormi, ak potrebujeme nacitavat obsah suboru a dalej
 * s nim pracovat, alebo pri vypisoch do konzoly.
 * Priklady: retazec ako argument funkcie
 * printf("FEI je skola hrou.\n");
 * zadefinovanie a pouzitie retazca
 * char retazec[51];
 * fscanf(subor, "%50s", retazec);
 * SUBOR - subor je vlastne postupnost bajtov, ulozena na disku. Pouziva sa napriklad
 * na dlhodobe uchovanie dat.
 * Priklady: otvorenie, zapis a zatvorenie suboru
 * FILE *subor;
 * subor = fopen("nazov.txt","w");
 * fprintf(subor,"Toto si chcem ulozit do suboru...");
 * fclose(subor);
 * STRUKTURA - ide o zlozeny datovy typ, pouzivame ju, ak potrebujeme mat pokope viacero
 * dat, napriklad ak chceme uchovavat zaznamy o knihach, tak strukturu moze tvorit autor,
 * nazov knihy, rok vydania a pod...
 * Priklady: zadefinovanie struktury
 * typedef struct kniha{
 * char nazov[100];
 * char autor[50];
 * int rok;
 * } Kniha;
 * Vytvorenie knihy a naplnenie udajmi
 * Kniha k;
 * k.nazov = "Zahada nevediaceho Cauchyho a Dalamberta";
 * k.autor = "Boris Rudolf";
 * k.rok = 1970;
 * SMERNIK - je to premenna, v ktorej je ulozena adresa pamati, na ktoru ukazuje. 
 * Znacime ho hviezdickou pred jeho menom. Pouziva sa napriklad na zmenu hodnot
 * premennych vo funkciach, alebo ak potrebujeme dynamicky alokovanu pamat.
 * Priklady: zmena hodnoty vo funkcii
 * void funkcia(int *cislo) {
 *      *cislo = *cislo+1;
 * }
 * volanie v inej funkcii potom bude vyzerat takto
 * int a=10;
 * funkcia(&a);
 * po volani bude v a ulozena hodnota 11
 * priradenie dynamicky alokovanej pamete
 * int *cisla;
 * cisla = malloc(sizeof(int)*10);
 * s cislami mozme potom pracovat ako s polom o velkosti 10 prvkov */

/* testovaci main */
int main() {
    Complex komplexne[] = { {1.0,1.0}, {10.0,10.0}, {3.0,3.0}, {9.0,9.0}, {4.0,4.0},
                            {7.0,7.0}, {5.0,5.0}, {6.0,6.0}, {2.0,2.0}, {8.0,8.0} };
    char *retazec;
    char *retazce[] = {"zita","andrea","eleonora","blazena"};
    int nova_dlzka = 0, i=0, matica[N][N] = { {1,2,3}, {4,5,6}, {1,6,4} };
    retazec = funkciaOA2();
    printf("Obsah nacitaneho riadku: %s\n",retazec);
    printf("Index max. suctu riadku v matici: %d\n",funkciaOA3(matica));
    nova_dlzka = funkciaOA1(retazce,"bozena",4);
    for (i=0;i<nova_dlzka;i++)
        printf("%s ",retazce[i]);
    putchar('\n');
    funkciaSOA3(komplexne, 10);
    for (i=0;i<10;i++)
        printf("%g\n",funkciaSOA2(komplexne[i]));
    putchar('\n');
    return 0;
}
