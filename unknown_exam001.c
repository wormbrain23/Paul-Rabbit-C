#include <stdio.h>
#include <string.h> /* potrebne na strchr, strlen, strcmp, str... */
#include <stdlib.h> /* potrebne na qsort, malloc, free ... */
#include <math.h> /* sqrt, pow... */
/* Prepisana jedna strana z neznameho terminu */

/* BT. Teoreticka otazka: Strucne napiste: Co je to smernik/ukazovatel? Aky je rozdiel
 * medzi typovym a netypovym smernikom? Co je to smernikova aritmetika? Na co sa vyuzivaju
 * smerniky v jazyku C? */
/* RIESENIE
 * Co je to smernik -> vid. OT2014.c -> posledna otazka. Typovym smernik ma jasne urceny typ, na aky
 * moze ukazovat (akeho typu moze uchovavat adresu). Netypovy - void smernik moze ukazovat na hociktory
 * z datovych typov, pricom neskor moze opat ukazovat na odlisny typ.
 * void *smernik;
 * int cislo=5;
 * double ine_cislo=10.3;
 * smernik = &cislo; - ukazuje na premennu typu int
 * smernik = &ine_cislo - ukazuje na premennu typu double
 * Smernikova aritmetika povoluje 3 operacie - scitanie/odcitanie/porovnavanie smernikov. Funguje
 * podobne ako pri klasickej aritmetike s cislami, akurat ide vzdy o hodnoty adries, ak teda mam
 * smernik typu int *s1 a typu char *s2 tak po vykonani
 * s1 = s1 + 2;
 * s2 = s2 + 2;
 * sa prvy smernik posunie o 8 bajtov v pamati, zatialco druhy o 2 bajty, pretoze int v pamati zabera
 * 4 bajty. Rovnako pri porovnavani smernikov sa porovnavaju adresy kam ukazuju, nie hodnoty.
 * Na co sa vyuzivaju - opat vid. OT2014.c -> posledna otazka.
 */
/* BS1. Napiste deklaraciu zlozeneho datoveho typu s nazvom Point s 2 zlozkami: x,y (cele
 * cisla). Napiste deklaraciu zlozeneho datoveho typu Triangle s 3 zlozkami A,B,C (typu Point). */
typedef struct point{
    int x,y;
} Point;
typedef struct triangle{
    struct point a,b,c; /* v case prekladu este nie je znamy nazov sturktury Point */
} Triangle;

/* BS2. Napiste funkciu, ktorej vstupom su 2 body (vid BS1) a vystupom je ich (Euklidovska)
 * vzdialenost (t.j. odmocnina((x1-x2)^2+(y1-y2)^2), kde x1,y1 a x2,y2 su prislusne suradnice bodov. */
double funkciaBS2(Point p1, Point p2) {
    return sqrt(pow(p1.x-p2.x,2.0)+pow(p1.y-p2.y,2.0));
}
/* BS3. Napiste funkciu, ktorej vstupom je trojuholnik (vid BS1) a vystupom je jeho obvod (vyuzite
 * funkciu z BS2). */ 
double funkciaBS3(Triangle t) {
    double dlzka_ab, dlzka_bc, dlzka_ca;
    dlzka_ab = funkciaBS2(t.a,t.b);
    dlzka_bc = funkciaBS2(t.b,t.c);
    dlzka_ca = funkciaBS2(t.c,t.a);
    return dlzka_ab+dlzka_bc+dlzka_ca;
}
/* BR1. Napiste funkcia, ktora obrati retazec. T.j. ak je jej vstupom "retazec", jej vystupom bude
 * "cezater". */
char *funkciaBR1(char *retazec) {
    int zaciatok = 0,koniec = strlen(retazec)-1;
    char pom;
    while (zaciatok < koniec) {
        pom = retazec[zaciatok];
        retazec[zaciatok] = retazec[koniec];
        retazec[koniec] = pom;
        zaciatok++;
        koniec--;
    }
    return retazec;
}
/* BR2. Napiste kratky program (staci main funkciu, ktora nacita slovo zo standardneho vstupu (staci cez
 * scanf, ale pozor na pretecenie), obrati ho pomocou funkcie BR1 a vypise obratene slovo. */
void funkciaBR2() {
    char slovo[100];
    scanf("%99s",slovo);
    printf("%s\n",funkciaBR1(slovo));
}
/* BR3. Napiste funkciu, ktora najde najkratsi retazec v poli retazcov (ak ich je viac, vrati posledny
 * z nich). Napiste kratky program (vyuzivajuci tuto funkciu), ktory vypise najkratsi parameter zadany
 * z prikazoveho riadku (pouzite argumenty main funkcie). */
char *funkciaBR3(char *pole[], int dlzka_pola) {
    int min = strlen(pole[0]), index_min = 0, i = 0; /* na zaciatku ma min. dlzku prvy retazec v poli */
    for (i=1;i<dlzka_pola;i++)
        if (strlen(pole[i]) < min) {
            min = strlen(pole[i]);  /* nastavim novu min. dlzku */
            index_min = i;  /* zaznacim si index retazca, ktory ju ma */
        }
    return pole[index_min];
}
/* BP1. Npiste funkciu. Vstupom funkcie je subor otvoreny na citanie (premenna typu FILE*). Ulohou
 * funkcie je nacitat cisla zo suboru (cez fscanf, nacitavanie sa ukonci ak fscanf nenacita cislo)
 * do dynamicky alokovaneho pola, pricom velkost pola prisposobi poctu udajov (pouzite realloc).
 * Predpoklada sa, ze na prve miesto v poli ulozi pocet nacitanych cisel, a az za tym budu nasledovat
 * samotne nacitane cisla. Vrati smernik na vysledne pole cisel. */

/* BP2. Napiste funkciu, ktora do suboru s danym menom (parameter funkcie) zapise na koniec (pouzite
 * "append" mod otvorenia suboru) zadany retazec (druhy parameter). */
void funkciaBP2(char *nazov_suboru, char *retazec) {
    FILE *subor;
    subor = fopen(nazov_suboru,"a"); /* append */
    fprintf(subor,"%s",retazec);
    fclose(subor);
}
/* BP3. Napiste funkciu. Vstupom je M x N matica a pole N cisel (rozmery staci napevno). Funkcia naplni
 * pole suctami hodnot v N stlpcoch matice. */

/* Na fotke je este BONUSova otazka zamerana na tvorbu automatu, to sa mi riesit nechce. */

/* testovaci main */
int main(int argc, char **argv) { /* argc/argv kvoli ulohe BR3 */
    Triangle t;
    char slovo[] = "eduben akizyf andaiz zu";
    //char *mena[] = { "hopla","afrika","belarus","pravitko","stol","izba","rozum","hipster","zazula","zubor","ypsilon"};
    t.a.x = 0;
    t.a.y = 0;
    t.b.x = 1;
    t.b.y = 0;
    t.c.x = 0;
    t.c.y = 1;
    printf("%g\n",funkciaBS3(t));
    printf("%s\n",funkciaBR1(slovo));
    printf("%s\n",funkciaBR3(argv,argc));
    return 0;
}
