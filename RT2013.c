#include <stdio.h>
#include <string.h> /* potrebne na strchr, strlen, strcmp, str... */
#include <stdlib.h> /* potrebne na qsort, malloc, free ... */
/* Prepisana jedna strana z 2013 RT 
 * Na skuske boli zda sa 2 skupiny - A/B, zadania su velmi podobne */

/* TA/TB. Teoreticka otazka: Co znamena zapis "char *str;" a co znamena zapis 
 * "char text[100];"? Pri rieseni akych uloh vyuzijete str, resp. text (konkretizujte 
 * prikladom)? */
/* RIESENIE
 * char *str; vytvori smernik typu char s nazvom str
 * char text[100]; vytvori pole s nazvom text, ktore ma 100 prvkov typu char
 * str sa da vyuzit napriklad ak chcem pracovat s adresou uz existujuceho prvku typu char
 * alebo ak potrebujem blok pamati s velkostou, ktora nie je znama v case kompilacie.
 * Priklady: str = &text[50]; - str ma priradenu adresu na 51. prvok v poli text
 * str = malloc(sizeof(char)*dlzka_retazca); - pre str vyhradim pamat o velkosti ulozenej
 * v premennej dlzka_retazca.
 * text sa da vyuzit, ak dopredu pozname velkost retazca, pre ktory potrebujeme blok
 * pamati.
 * Priklady: text = "Nejaky text"; - do textu ulozim retazec "Nejaky text"
 * scanf("%99s",text); - do textu nacitam retazec o maximalnej velkosti 99 (posledny
 * znak bude ukoncovaci '\0'). */

/* A1. Napiste funkciu. Vstupom funkcie je pole cisel. Funkcia zisti, ci sa v poli
 * cisel  nachadza nejake cislo viac ako raz. Funkcia vrati index prveho cisla,
 * ktore sa opakuje, alebo -1, ak sa ziadne cislo neopakuje. HINT: vyuzite
 * pomocnu funkciu. */
int funkciaA1(int pole[], int dlzka_pola) {
    int i=0,j=0;
    for (i=0;i<dlzka_pola;i++)
        for (j=i+1;j<dlzka_pola;j++)    
            if (pole[i] == pole[j])             
                return i;
    return -1;
}
/* B1. To iste ako A1 ale s retazcom */
/* Zajacove riesenie */
typedef struct { int hour, minute; } Time;
int first_repeated(const char *str) {
    int index;
    //alternativa s testovanim konca retazca, usetrim tak cas pre dlhe retazce...
    //da sa pouzit aj: int len = strlen(str);  a v podmienke: index < len
    for (index = 0; str[index] != '\0'; index++) {
        //s vyuzitim kniznicnej funkcie - pozrite si dokumentaciu, co funkcia robi:
        if ( strchr(str + index + 1, str[index]) != NULL )    
        return index;
        //alternativne, podobna funkcia sa da napisat vlastna, alebo sa da nahradit cyklom:
        /*
        for ( j = index+1; str[j] != '\0'; j++ )    
            if ( str[j] == str[index] )             
                return index;
        */ 
    }   
    return -1;
}

/* A2. Definujte strukturu Cas, so zlozkami hodina a minuta. Napiste funkciu, ktora
 * "posunie" casovy udaj (vstupom je smernik na udaj typu Cas) dopredu o zadany pocet
 * minut (cyklicky, po 23:59 nasleduje 00:00, zmena moze byt aj viacdenna). HINT:
 * trocha matematiky usetri vela roboty. */
/* Riesenie je to iste, ako pri B2, ale v riadku minutes = (minutes + delta) % (24*60);
 * bude miesto - znamienko + */
/* B2. To iste ako A2 ale s posunom dozadu */
/* Zajacove riesenie */
void update_time(Time *ptr, int delta) {
    int minutes = 60 * ptr->hour + ptr->minute;
    
    minutes = (minutes - delta) % (24*60);  // posun a orezanie v ramci 1 dna
    
    // ak sme zliezli do zapornych cisel, posunieme sa cez datumovu hranicu
    if (minutes < 0) minutes += 24*60;      

    //teraz uz je udaj v minutach, v rozsahu 0 - (23*60-1), skonverujem na hodiny a minuty
    ptr->hour   = minutes / 60;  //celociselne delenie
    ptr->minute = minutes % 60;  //zvysok sa zapise ako minuty
}

/* A3. Napiste funkciu, ktorej vstupom je retazec. Funkcia zisti, ci retazec je palindrom,
 * t.j. ci sa cita rovnako odpredu a odzadu, ak vsetky znaky, ktore nie su alfanumericke
 * (pismena a cisla) sa ignoruju a velke a male pismena sa stotoznuju ("Kobyla ma maly bok."
 * je palindrom). HINT: spravte aspon verziu, ktora neberie do uvahy specialne osetrenie
 * medzier. */
int funkciaA3(char *slovo) {
    return 0; /* TODO */
}
/* B3. Napiste funkciu, ktorej vstupom je retazec. Funkcia obrati retazec (zapise ho
 * do povodneho miesta v pamati od konca), pricom ale vynecha nealfanumericke znaky a velke
 * znaky sa zmenia na male (napr. z "Hello world!" sa stane "dlrowolleh"). HINT: spravte
 * aspon verziu, ktora neberie do uvahy specialne osetrenie nealfanum. znakov ... */
void funkciaB3(char *slovo) {
    return 0; /* TODO */
}
/* A4. Napiste funkciu, ktorej vstupom je matica s rozmermi NxN. Zvolte vhodnu reprezentaciu
 * matice a strucne ju popiste. Funkcia rozhodne (vrati logicku hodnotu), ci matica je dolna
 * trojuholnikova (t.j. vsetky prvky nad hlavnou diagonalou su nulove. */
/* Upravene Zajacove riesenie */
#define N 3
int funkciaA4(int matrix[N][N]) {
    int i,j;
    // pricip: matica je ... trojuholnikova, ak vsetky prvky nad diagonalou su nulove. 
    // Tzn. ak je akykolvek pod a na diagonale nenulovy, mozem hned skoncit - nie je
    // trojuholnikova naopak, trojuholnikova je len vtedy, ak prejdem vsetky cielove prvky
    // a vsetky budu nulove
    // tzv. univerzalna verzia:
    for (i=0;i<N;i++)    //aj rozmery matice sa cisluju od 0 po N-1
        for (j=0;j<N;j++)
            if (j > i && matrix[i][j] != 0)
                return 0;    // nie je dolna trojuholnikova 
    return 1;  // je trojuholnikova
}
/* B4. To iste ako A4, ale zistovala sa horna trojuholnikova matica. Miesto podmienky
 * j > i bude j < i*/

/* A5. Napiste funkciu, ktorej vstupom je pole retazcov. Funkcia ho usporiada inverzne
 * lexikograficky (t.j. "zoo", "zebra", "tvaroh", ...) HINT: mozete vyuzit aj standardne
 * funkcie jazyka C. */
/* Zajacove riesenie */
// inverzne usporiadanie: komparacna funkcia porovna retazce cez strcmp, ale v opacnom poradi
// tie "hviezdicky/zatvorky" su kvoli spravnemu pretypovaniu 
// parameter "a" ukazuje na ukazatel na retazec, ale ta funkcia o tom explicitne nevie
int invstrcmp(const void* a,const void* b) { 
    return strcmp( *((char**) b), *((char**) a) ); 
}  
//pole retazcov je vlastne pole ukazatelov na retazce, musime mat tiez velkost pola
void sort_string_array(char* array[], int n) {
    qsort(array, n, sizeof(array[0]), invstrcmp); 
}
/* B5. To iste ako A5, ale usporiadat lexikograficky (od a po z) */
/* V Zajacovom riesenie staci zmenit v strcmp poradie argumentov, pridavam
 * aj verziu cez bubblesort, mozno pre niekoho na zaciatku skor pochopitelne 
 * ako komparacna funkcia v qsorte */
void funkciaB5(char *retazce[], int dlzka_pola) {
    int i=0,j=0;
    char *pom;
    for (i=0;i<dlzka_pola;i++)
        for (j=i+1;j<dlzka_pola;j++)
            if (strcmp(retazce[j],retazce[i]) > 0) {
                pom = retazce[i];
                retazce[i] = retazce[j];
                retazce[j] = pom;
            }
}


/* A6. Nech existuje funkcia const char* DateTime( ), ktora vrati retazec, predstavujuci
 * textovy zapis aktualneho datumu a casu. Napiste funkciu, ktorej vstupom je meno suboru
 * (textovy retazec). Funkcia na koniec suboru na samostatny riadok pripise (zvolte vhodny
 * mod otvorenia suboru) aktualny datum a cas, a kolkykrat sa vola funkcia v ramci spusteneho
 * programu (aky druh alokacie premennych sa hodi?). Ak pride k akejkolvek chybe, funkcia
 * predcasne ukonci cely program. */
/* Upravene Zajacove riesenie */
const char* DateTime(){return "datum";};  //nech existuje = deklaracia

void add_to_log(const char* filename, const char* text)
{
   static int ctr = 0;  //nastavi sa na nulu len pri prvom volani funkcie, a zachova si hodnotu
   FILE *fp;

   ctr++;     //zvysime pocet volani

   fp = fopen(filename, "a");   //otvorime subor na pridavanie na koniec
   if (fp == NULL)   //nepodarilo sa ?
      exit(-1);      //vyskocime z programu

   fprintf(fp, "%s: %3i. %s\n", DateTime(), ctr, text);

   fclose(fp);
}
/* B6. To iste co A6, az na to ze sa zapisovalo do suboru run.log, teda argumentom funkcie nebol
 * filename */

/* A7/B7. Vytah s elektronickym riadenim uchovava udaje o svojom stave v strukture Stav. Tato
 * struktura obsahuje pole N cisel 0/1, ktore reprezentuju volacie tlacidla na N poschodiach;
 * druhe pole N cisel 0/1 reprezentujuce volacie tlacidla v kabine vytahu; poschodie, na ktorom
 * sa vytah nachadza; a smer posledneho pohybu (-1 nadol, 0 stal na poschodi, 1 nahor).
 * Definujte tuto strukturu ako udajovy typ v jazyku C. Napiste funkciu, ktorej vstupom je
 * smernik na strukturu Stav. Funkcia na zaklade stavu vytahu rozhodne, ktorym smerom sa ma
 * vytah pohnut (-1 nadol, 0 zostat stat na poschodi, 1 nahor) po zatvoreni dveri vytahu.
 * Strucne slovne napiste, ake vlastnosti ma vas algoritmus z hladiska pouzivatelov vytahu
 * (napr. dorucite cestujuceho v kabine kam treba, alebo ho budete vozit hore-dole?). */
typedef struct stav{
    int poschodia[N], kabina[N], poschodie, smer;
} Stav;

void funkciaA7(Stav *akt_stav) {
    /* TODO */
}

/* testovaci main */
int main() {
    int i=0;
    int triangle[N][N] = {{1,0,0},{1,1,0},{1,1,1}}; 
    /* dolna trojuholnikova matica vyzera napriklad takto
    * 1 0 0
    * 1 1 0
    * 1 1 1 */
    char *mena[] = { "hopla","afrika","belarus","pravitko","stol","izba","rozum","hipster","zazula","zubor","ypsilon"};
    funkciaB5(mena,11);
    for (i=0;i<11;i++)
        printf("%s ",mena[i]);
    return 0;
}
