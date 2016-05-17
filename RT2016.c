/* RT 2016 - druha strana zadani, kazda otazka (A1-A6) je hodnotena 5 bodmi.
 * 
 * A1 - Co je to smernik? Rozdiel medzi void a typovym smernikom? Ako funguje smernikova
 * aritmetika? Na co sa pouzivaju smerniky v C?
 * 
 * A2 - Napisat funkciu, ktora vypocita kombinaciu cisel n nad k - C(n,k) = n!/((n-k)!*k!)
 * V zadani bolo, ze sa to ma riesit efektivnejsie, ako pocitanie horneho faktorialu a
 * nasledne delenie, aby sa znizila sanca na pretecenie ... potom napisat funkciu, ktora
 * tuto funkciu bude volat a vypise n-ty riadok pascalovho trojuholnika
 * 
 * A3 - Napiste funkciu, ktora ma 2 parametre - pole celych cisel a cele cislo "x". Na prvom
 * mieste v poli je zadany pocet cisel, ktore budu nasledovat za nim. Vasou ulohou je zvacsit
 * alokovanu pamat pola a na poslednu poziciu zapisat cislo "x". Po zapise na prvej pozicii
 * treba aktualizovat velkost a vratit smernik na pole. (Nie som si isty ci bolo v zadani, ze
 * treba vraciat aj ten smernik, ale to je detail.)
 * 
 * A4 - Zadana je matica ako pole smernikov na cisla, cele cislo "n" - pocet riadkov matice,
 * cele cislo "m" - pocet stlpcov matice. Naplnte maticu tak, ze v neparnych riadkoch budu
 * cisla zoradene od najmensieho po najvacsie a v parnych naopak. Priklad naplnenej matice:
 * 1 2 3 4
 * 8 7 6 5
 * 9 10 11 12
 * K tomu bonus za 3 body - ak to spravite v jednom cykle bez vetvenia cize bez pouzitia
 * ifov a ternarneho operatora.
 * 
 * A5 - Zadefinovat strukturu komplexneho cisla, ktora obsahuje cisla s desatinnou ciarkou
 * reprezentujuce realnu cast a imaginarnu cast. Funkcia na vypocet abs. hodnoty komplexneho
 * cisla |Z| = sqrt(realna^2+imag^2). Funkcia, ktora najde v poli komplexnych cisel prvok s
 * najvacsou absolutnou hodnotou (pouzite svoju funkciu na abs. hodnotu). Ak su 2 cisla s
 * rovnakou abs. hodnotou, tak za maximum sa povazuje to, ktore ma vacsiu realnu cast.
 * 
 * A6 - Na vstupe do funkcie mate retazec - nazov suboru. Napriklad "data.bin", druhy parameter 
 * je cele cislo "v". Cislo "v" reprezentuje pocet bajtov. Rozdelte zadany subor na casti
 * o velkosti "v" s tym, ze kazdu cast zapisete do noveho suboru. Nazvy suborov, kam zapisujete
 * maju tvar v tomto pripade "data.bin.001","data.bin.002","data.bin.003",...
 * Velka napoveda od Zajaca k tomuto prikladu bola - doporucujem pouzivat funkcie fopen, fclose,
 * fread, fwrite a sprintf.
 * 
 * BONUS - napisat algoritmus na prazenicu/caj tak, aby mu porozumel robot.
 */
