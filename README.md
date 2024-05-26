# Programa v3.0
**Sistemos specifikacijos**\
*CPU: 2,6 GHz 6-Core Intel Core i7*\
*RAM: 16 GB 2400 MHz DDR4*\
*HDD: Macintosh HD 500GB*\
\

## Vector ir std::vector uzpildymo tyrimas

*Vetoriams uzpildyti naudota `push_back()` funckija*\
*Tyrimas atliktas uzpildant su*\ 
*10000, 100000, 10000000, 10000000, 100000000 elementu*\
*Tyrimui naudotas -O3 optimizavimo flagas*\
*Laikai aprasyti milisekundziu formatu*

| `elementu skaicius` | std::vector | Vector |
|:-------------------:|:------------:|:-------------:|
| 10000 | 0.085 | 0.047 |
| 100000 | 0.613 | 0.228 |
| 1000000 | 5.675 | 2.458 |
| 10000000  | 68.139 | 28.273 |
| 100000000  | 585.604 | 393.132 |

*100000000 elementu uzpildymo metu ivyksta po 27 perskirstymus*

# Programos naudojimo instrukcija

Ši programa leidžia vartotojui įvesti ir išvesti duomenis keliais skirtingais būdais, priklausomai nuo pasirinkto programos veikimo būdo. Žemiau pateikiama išsami instrukcija, kaip naudoti programą.

## Įvesties perdengimo metodai

Duomenų įvestis rankiniu ir automatiniu būdu įvyksta, kai duomenų skaitymui yra naudojamas `istream` objektas (šios programos atveju `cin`), o tada žiūrima pagal vartotojo pasirinktą programos veikimo eiga:

- Jei `skaicius == 1`, tai studentų įvedimas vyksta rankiniu būdu.
- Jei `skaicius == 2`, tai studentų vardo ir pavardės įvedimas vyksta rankiniu būdu, o pažymiai yra sugeneruojami.
- Jei `skaicius == 3`, tai studentų yra sugeneruojama tiek, kiek nori vartotojas.

Duomenų įvestis iš failo įvyksta, kai duomenų skaitymui naudojamas `istringstream` objektas ir `skaicius == 4`.

## Išvesties perdengimo metodai

Duomenų išvedimas per konsolę įvyksta, kai duomenų išvedimui yra naudojamas `ostream` objektas (šios programos atveju `cout`).

Duomenų išvedimas į failą įvyksta, kai duomenų išvedimui yra naudojamas `ofstream` objektas.

# Naudotojo vadovas

## 1. Parsisiųskite ir paruoškite kodą
1. Parsisiųskite `source_code.zip` arba `source.tar.gz`.
2. Išskleiskite parsisiųstą folderį į programavimo aplinką (parsisiųskite reikalingus C++ ir Makefile plėtinius).
3. Paleiskite terminalą arba Command Prompt.
4. Nunaviguokite į `vector` folderį:
   - Naudokite komandą `cd failoPavadinimas`, kad nueitumėte į kitą folderį.
   - Norėdami grįžti vienu folderiu atgal, naudokite komandą `cd ..`.

## 2. Kompiliavimas ir paleidimas
1. Rašykite `make` ir palaukite, kol sistema sukompiliuos reikiamus failus.
2. Toliau rašykite `./run_01`,`./run_02` arba `./run_03` ir jūsų programa turėtų pasileisti. Jei programa nepasileido, vadinasi, praleidote kažkurį žingsnį.
3. Rašydami `make clean` jūs išvalysite visus `.exe` failus.

## 3. Programos naudojimas
1. Paleista programa jums parodys meniu, kuriame bus prašoma įvesti numerį nuo 1 iki 6, kad pasirinktumėte programos eigą:

    ```
    Enter number
    1 - manual input
    2 - generate grades
    3 - generate names and grades
    4 - reading from file
    5 - generate file
    6 - quit / show results
    Number:
    ```

2. Pasirinkus nuo 1 iki 3, bus prašoma įvesti numerį nuo 1 iki 2, kad pasirinktumėte programos eigą:

    ```
    Enter number
    1 - n and m is given
    2 - n and m is not given
    Number:
    ```

    - Pasirinkus skaičių 1, bus prašoma įvesti studentų skaičių ir namų darbų kiekį.
    - Toliau programos eiga skirsis, priklausomai nuo pasirinkto skaičiaus 8-ame žingsnyje.
    - Pasirinkus skaičių 2, sekite instrukcijas.

3. Pasirinkus skaičių 4 iš meniu, bus parodyti visi `.txt` failai. Vieną jų reikia pasirinkti.
   - Kad programa galėtų pasiekti jūsų `.txt` failą, šį failą reikia įdėti šalia `headers` ir `source` failų.
   - `.txt` failas privalo atitikti tokią struktūrą: `vardas pavarde nd1 nd2 ... egz`.

4. Pasirinkus skaičių 5 iš meniu, bus prašoma įvesti studentų skaičių ir namų darbų kiekį.
    
    ```
    How many students you want to generate in file?:
    Number:
    How many tasks should students have (final counts in)?: 
    Number: 
    ```

    - Įvedus studentų skaičių 10000, atitinkamai bus sukurtas `StudentaiGen10000.txt` failas.

5. Pasirinkus skaičių 6 iš meniu, bus prašoma pasirinkti rezultatų išvedimo būdą `f` arba `c`.
    
    ```
    Choose how to output the results:
    f - To file
    c - To console
    Choice:
    ```
    
    - Tuomet bus prašoma pasirinkti skirstymo strategiją, įrašant skaičių nuo 1 iki 3.
      
      ```
      Choose the strategy for sorting
      1 - to 'k' and 'l' containers
      2 - to 'l' and leaving only good students in a 's' container
      3 - optimized and best strategy
      Choice:
      ```
      
    - Tuomet bus prašoma pasirinkti pagal kokį balą norima rūšiuoti, įrašant raidę `a` arba `m`.
      
      ```
      Choose the output grade:
      a - average
      m - median
      Choice:
      ```
      
    - Tuomet bus prašoma pasirinkti rūšiavimo būdą, įrašant skaičių nuo 1 iki 3.

      ```
      Choose how to sort: 
      1 - By name
      2 - By surname
      3 - By grade
      Choice:
      ```

6. Galiausiai bus parodytas atsakymas:
    - Jei pasirinkote išvesti rezultatus terminale arba konsoleje, tai matysite rezultatus konsoleje.
    - Jei pasirinkote rezultatus rašyti į failą, tai rezultatai bus išvesti į failus `lievi.txt` ir `kieti.txt`.

Sekite šias instrukcijas, kad sėkmingai naudotumėte programą. Jei kyla klausimų ar problemų, patikrinkite, ar visus žingsnius atlikote teisingai.
