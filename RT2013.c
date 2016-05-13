#include <stdio.h>

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
 
/* A2. Definujte strukturu Cas, so zlozkami hodina a minuta. Napiste funkciu, ktora
 * "posunie" casovy udaj (vstupom je smernik na udaj typu Cas) dopredu o zadany pocet
 * minut (cyklicky, po 23:59 nasleduje 00:00, zmena moze byt aj viacdenna). HINT:
 * trocha matematiky usetri vela roboty. */
 
/* A3. Napiste funkciu, ktorej vstupom je retazec. Funkcia zisti, ci retazec je palindrom,
 * t.j. ci sa cita rovnako odpredu a odzadu, ak vsetky znaky, ktore nie su alfanumericke
 * (pismena a cisla) sa ignoruju a velke a male pismena sa stotoznuju ("Kobyla ma maly bok."
 * je palindrom). HINT: spravte aspon verziu, ktora neberie do uvahy specialne osetrenie
 * medzier. */
 
/* A4. Napiste funkciu, ktorej vstupom je matica s rozmermi NxN. Zvolte vhodnu reprezentaciu
 * matice a strucne ju popiste. Funkcia rozhodne (vrati logicku hodnotu), ci matica je dolna
 * trojuholnikova (t.j. vsetky prvky nad hlavnou diagonalou su nulove. */

/* A5. Napiste funkciu, ktorej vstupom je pole retazcov. Funkcia ho usporiada inverzne
 * lexikograficky (t.j. "zoo", "zebra", "tvaroh", ...) HINT: mozete vyuzit aj standardne
 * funkcie jazyka C. */

/* A6. Nech eixstuje funkcia const char* DateTime( ), ktora vrati retazec, predstavujuci
 * textovy zapis aktualneho datumu a casu. Napiste funkciu, ktorej vstupom je meno suboru
 * (textovy retazec). Funkcia na koniec suboru na samostatny riadok pripise (zvolte vhodny
 * mod otvorenia suboru) aktualny datum a cas, a kolkykrat sa vola funkcia v ramci spusteneho
 * programu (aky druh alokacie premennych sa hodi?). Ak pride k akejkolvek chybe, funkcia
 * predcasne ukonci cely program. */

/* A7. Vytah s elektronickym riadenim uchovava udaje o svojom stave v strukture Stav. Tato
 * struktura obsahuje pole N cisel 0/1, ktore reprezentuju volacie tlacidla na N poschodiach;
 * druhe pole N cisel 0/1 reprezentujuce volacie tlacidla v kabine vytahu; poschodie, na ktorom
 * sa vytah nachadza; a smer posledneho pohybu (-1 nadol, 0 stal na poschodi, 1 nahor).
 * Definujte tuto strukturu ako udajovy typ v jazyku C. Napiste funkciu, ktorej vstupom je
 * smernik na strukturu Stav. Funkcia na zaklade stavu vytahu rozhodne, ktorym smerom sa ma
 * vytah pohnut (-1 nadol, 0 zostat stat na poschodi, 1 nahor) po zatvoreni dveri vytahu.
 * Strucne slovne napiste, ake vlastnosti ma vas algoritmus z hladiska pouzivatelov vytahu
 * (napr. dorucite cestujuceho v kabine kam treba, alebo ho budete vozit hore-dole?). */



/* testovaci main */
int main() {
    return 0;
}
