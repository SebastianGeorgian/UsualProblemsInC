#include <stdio.h>
#include <math.h>

//Tema 1. Calcul de sume.

//1.1. Calculati suma 1^2 – 2^2 + 3^2 – ... +-n^2. Prototip: int suma_puteri(int n);
int suma_puteri(int n)
{
    int suma = 0, i;
    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            suma += pow(i, 2);
        }
        else
        {
            suma -= pow(i, 2);
        }
    }
    return suma;
}
//1.2. Calculati suma tuturor numerelor mai mici ca n, divizibile cu 3. Prototip: int suma_mult3(int n);
int suma_mult3(int n)
{
    int i, suma = 0;
    for (i = 1; i <= n; i++)
    {
        if (i % 3 == 0) suma += i;
    }
    return suma;
}
//1.3. Calculati suma 1/2 + 2/3 + ... + n/(n +1). Prototip: float suma_rapoarte(int n);
float suma_rapoarte(int n)
{
    float suma = 0;
    float i;
    for (i = 1; i <= n; i++)
    {
        suma += i / (1 + i);
    }
    return suma;
}

//Tema 2. Cifrele unui numar intreg.

//2.1. Calculati suma cifrelor unui numar intreg. Prototip: int cifre(long n);
int cifre(long int n)
{
    int suma = 0;
    while (n != 0)
    {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}
//2.2. Calculati numarul de aparitii ale unei cifre intr-un numar intreg. Prototip: int aparitii(long n, int c);
int aparitii(long int n, int c)

{
    int i = 0;
    while (n != 0)
    {
        if (n % 10 == c) i++;
        n /= 10;

    }
    return i;
}
//2.3. Calculati cea mai mare cifra a unui numar intreg. Prototip: int cifra_max(long n);
int cifra_max(long int n)
{
    int ceva = 0;
    while (n != 0)
    {
        if (n % 10 > ceva) ceva = n % 10;
        n /= 10;
    }
    return ceva;
}
//2.4. Verificati daca un numar este palindrom. Functia va returna 1 daca numarul este palindrom si 0 in caz contrar. Prototip: int palindrom(long n);
int palindrom(long int n)
{
    int inv = 0;
    long int nr = n;
    while (n != 0)
    {
        inv = inv * 10 + n % 10;
        n /= 10;
    }
    if (nr == inv) return 1;
    else return 0;
}

//Tema 3. Divizori unui numar intreg

// 1. Afisati divizorii naturali ai unui numar intreg.
void print_divizori(int n)
{
    int i;
    for (i = 1; i <= n / 2; i++)
    {
        if (n % i == 0) printf("%d, ", i);
    }
    printf("si %d.", n);
}
//3.2 Functia va returna 1 daca numarul este perfect si 0 in caz contrar.
int perfect(long int n)
{
    int nr = n, suma = 1 + n, i;
    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0) suma += i;
    }
    if (suma == 2 * nr) return 1;
    else return 0;
}
//3.3  Verificati daca un numar natural este prim. Functia va returna 1 daca numarul este prim si 0 in caz contrar.
int prim(long n)
{
    int i;
    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0) return 0;
    }
    return 1;
}
//3.4  Calculati ordinul de multiplicitate al unui numar prim k intr-un numar intreg n.
int ordin_mult(int n, int k)
{
    int contor = 0;
    while (n != 0)
    {
        if (n % 10 == k)
        {
            contor++;
            n /= 10;
        }
        else n /= 10;
    }
    return contor;

}
//3.5  Calculati CMMDC-ul nr a si b;
int cmmdc(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
            b = b - a;

    }
    return a;
}

//Tema 4. Vectori

void citire_vector(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}
void citire_vector_reale(float v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%f", &v[i]);
    }
}
//4.1. Afisati elementele pozitive dintr-un vector de dimensiune n.
void print_pozitive(int v[], int n)
{
    int i;
    citire_vector(v, n);
    printf(" Elementele pozitive din vector sunt : ");
    for (i = 0; i < n - 1; i++)
    {
        if (v[i] > 0)
        {
            printf("%d, ", v[i]);
        }
    }
    if (v[n - 1] > 0) printf("%d.", v[i]);
}
//4.2. Afisati pozitiile dintr-un vector de dimensiune n pe care se gasesc numere pozitive.
void print_poz_pozitive(int v[], int n)
{
    int i;
    citire_vector(v, n);
    printf(" Pozitiile pe care se gasesc numere pozitive sunt : ");
    for (i = 0; i < n - 1; i++)
    {
        if (v[i] > 0) printf("%d, ", i);
    }
    if (v[n - 1] > 0) printf("%d.", i);
}
//4.3. Afisati elementele de pe pozitii impare dintr-un vector de dimensiune n.
void print_poz_impare(int v[], int n)
{
    int i;
    citire_vector(v, n);
    printf(" Elemntele de pe pozitii impare sunt : ");
    for (i = 0; i < n - 1; i++)
    {
        if (i % 2 == 1) printf("%d, ", v[i]);
    }
    if ((n - 1) % 2 == 1) printf("%d.", v[i]);
}
//4.4. Afisati elementele unui vector de dimensiune n in ordine inversa.
void print_reverse(int v[], int n)
{
    int i;
    citire_vector(v, n);
    printf("Inversul vectorului este : ");
    for (i = n - 1; i > 1; i--)
    {
        printf("%d", v[i]);
    }
    printf("%d", v[0]);
}
//4.5. Verificati daca elementele unui vector de dimensiune n formeaza o progresie aritmetica.
int progresie_aritm(float v[], int n)
{
    int i;
    citire_vector_reale(v, n);
    for (i = 0; i < n - 2; i++)
    {
        if ((v[i] + v[i + 2]) / 2 != v[i + 1]) return 0;

    }
    return 1;
}
//4.6. Verificati daca elementele unui vector de dimensiune n formeaza o progresie geometrica.
int progresie_geom(float v[], int n)
{
    int i;
    citire_vector_reale(v, n);
    for (i = 0; i < n - 2; i++)
    {
        if (sqrt(v[i] * v[i + 2]) != v[i + 1]) return 0;

    }
    return 1;
}
//4.7. Calculati produsul scalar al doi vectori de dimensiune n.
float produs_scalar(float v[], float u[], int n)
{
    int i, p = 0;
    citire_vector_reale(v, n);
    citire_vector_reale(u, n);
    for (i = 0; i < n; i++)
    {
        p += v[i] * u[i];
    }
    return p;
}
//4.8. Calculati media aritmetica a elementelor nenule dintr-un vector de dimensiune n.
float media_aritmetica(int v[], int n)
{
    int i, c = 0;
    float sum = 0;
    citire_vector(v, n);
    for (i = 0; i < n; i++)
    {
        if (v[i] != 0)
        {
            c++;
            sum += v[i];
        }
    }
    return (sum / c);
}
//4.9. Calculati numarul de aparitii ale valorii maxime dintr-un vector de dimensiune n.
int aparitii_maxim(int v[], int n)
{
    int i, max = 0, c = 0;
    citire_vector(v, n);
    for (i = 0; i < n; i++)
    {
        if (max < v[i]) max = v[i];
    }
    for (i = 0; i < n; i++)
    {
        if (max == v[i]) c++;
    }
    return c;
}
//4.10. Afisati ultima pozitie pe care se gaseste un element intr-un vector de dimensiune n.
int cauta_ultim(float v[], int n, float x)
{
    int i;
    citire_vector_reale(v, n);
    for (i = n - 1; i > 0; i--)
    {
        if (v[i] == x) return i + 1;
    }
    return 0;
}


int main()
{
    int tema, exercitiu, x;
    printf(" Alegeti tema va rog frumos: \n");
    printf(" Petru tema Calcul Sume apasati 1 \n");
    printf(" Petru tema Cifrele unui numar intreg apasati 2 \n");
    printf(" Petru tema Divizori unui numar intreg apasati 3 \n");
    printf(" Petru tema Vectori apasati 4 \n");
    printf(" Petru tema Siruri de caractere apasati 5 \n");
    printf(" Pentru tema Structuri de date apasati tasta 6\n");
    scanf("%d", &tema);

    //Conditii de ales tema + afisare tema aleasa
    while (tema != 1 && tema != 2 && tema != 3 && tema != 4 && tema != 5 && tema != 6)
    {
        printf(" Va rog sa alegeti o tema care exista \n");
        scanf("%d", &tema);

    }
    if (tema == 1 || tema == 2)
    {
        printf(" Ai ales tema: %s", tema == 1 ? "Calcul Sume" : "Cifrele unui numar intreg");
    }
    if (tema == 3 || tema == 4)
    {
        printf(" Ai ales tema: %s", tema == 3 ? "Divizori unui numar intreg" : "Vectori");
    }

    //Sfarsitul alegerii si afisarii

    //Secvente inutile pentru alegerea exercitiului, apelare functie + rezolvare
    if (tema == 1)
    {
        printf(" Acum va rog fumos sa alegeti exercitiul \n");
        printf(" Exercitiul 1 : Calculati suma 1^2 ~ 2^2 + 3^2 ~... +-n^2. (Introduceti 1) \n");
        printf(" Exercitiul 2 : Calculati suma tuturor numerelor mai mici ca n, divizibile cu 3.(Introduceti 2) \n");
        printf(" Exercitiul 3 : Calculati suma 1/2 + 2/3 + ... + n/(n +1).(Introduceti 3) \n");
        scanf("%d", &exercitiu);
        while (exercitiu != 1 && exercitiu != 2 && exercitiu != 3)
        {
            printf(" Va rog sa alegeti un exercitiu care exista. \n");
            scanf("%d", &exercitiu);
        }
        //TEMA 1 EXERCITIUL 1
        if (exercitiu == 1)
        {
            printf(" Ai ales exercitiul 1 : Calculati suma 1^2 ~ 2^2 + 3^2 ~ ... +-n^2 \n");
            int numar;
            printf(" Introduceti o valoare naturala > 0 pentru n: ");
            scanf("%d", &numar);
            printf("\n Numarul n = %d \n", numar);
            printf(" Suma puterilor = %d \n", suma_puteri(numar));
        }
        //TEMA 1 EXERCITIUL 2
        if (exercitiu == 2)
        {
            printf(" Ai ales exercitiul 2 : Calculati suma tuturor numerelor mai mici ca n, divizibile cu 3. \n");
            int numar;
            printf(" Introduceti o valoare naturala > 0 pentru n: ");
            scanf("%d", &numar);
            printf("\n Numarul n = %d \n", numar);
            printf(" Suma tuturor numerelor mai mici ca %d, divizibile cu 3 este : %d \n", numar, suma_mult3(numar));
        }
        //TEMA 1 EXERCITIUL 3
        if (exercitiu == 3)
        {
            printf(" Ai ales exercitiul 3 : Calculati suma tuturor numerelor mai mici ca n, divizibile cu 3. \n");
            int numar;
            printf(" Introduceti o valoare naturala > 0 pentru n: ");
            scanf("%d", &numar);
            printf(" Suma rapoartelor este %f \n", suma_rapoarte(numar));
        }
    }
    if (tema == 2)
    {
        printf(" Acum va rog frumos sa alegeti exercitiul \n");
        printf(" Exercitiul 1: Calculati suma cifrelor unui numar intreg.(Introduceti 1) \n");
        printf(" Exercitiul 2: Calculati numarul de aparitii ale unei cifre intr-un numar intreg.(Introduceti 2) \n");
        printf(" Exercitiul 3: Calculati cea mai mare cifra a unui numar intreg.(Introduceti 3) \n");
        printf(" Exercitiul 4: Verificati daca un numar este palindrom.(Introduceti 4) \n");
        scanf("%d", &exercitiu);
        while (exercitiu != 1 && exercitiu != 2 && exercitiu != 3 && exercitiu != 4)
        {
            printf(" Va rog sa alegeti un exercitiu care exista. \n");
            scanf("%d", &exercitiu);
        }
        // TEMA 2 EXERCITIUL 1
        if (exercitiu == 1)
        {
            long int numar;
            printf(" Ai ales exercitiul 1 : Calculati suma cifrelor unui numar intreg.");
            printf(" Introduceti un numar n : ");
            scanf("%li", &numar);
            printf(" Ai introdus n = %li", numar);
            printf(" Suma cifrelor lui %li este %d", numar, cifre(numar));
        }
        // TEMA 2 EXERCITIUL 2
        if (exercitiu == 2)
        {
            int cifra;
            long int numar;
            printf(" Ai ales exercitiul 2 : Calculati numarul de aparitii ale unei cifre intr-un numar intreg. \n");
            printf(" Introduceti un numar n : ");
            scanf("%li", &numar);
            printf(" Introduceti o cifra c : ");
            scanf("%d", &cifra);
            printf(" Ai introdus: \n Numarul = %li \n Cifra = %d \n", numar, cifra);
            printf(" Numarul de aparitii al cifrei %d in numarul %li este de %d ori", cifra, numar, aparitii(numar, cifra));
        }
        // TEMA 2 EXERCITIUL 3
        if (exercitiu == 3)
        {
            long int numar;
            printf(" Ai ales exercitiul 3: Calculati cea mai mare cifra a unui numar intreg. \n");
            printf(" Introduceti un numar n : ");
            scanf("%li", &numar);
            printf(" Ai introdus n = %li", numar);
            printf(" Cea mai mare cifra a numarului %li este %d", numar, cifra_max(numar));
        }
        // TEMA 2 EXERCITIUL 4
        if (exercitiu == 4)
        {
            long int numar;
            printf(" Ai ales exercitiul 4 : Verificati daca un numar este palindrom. Functia va returna 1 daca numarul este palindrom si 0 in caz contrar. \n");
            printf(" Introduceti un numar n : ");
            scanf("%li", &numar);
            printf(" Ai introdus n = %li", numar);
            printf(" Numarul %li %s este palindrom", numar, palindrom(numar) == 1 ? "" : " NU");
        }
    }
    if (tema == 3)
    {
        printf(" Acum va rog fumos sa alegeti exercitiul \n");
        printf(" Exercitiul 1 : Afisati divizorii naturali ai unui numar intreg. (Introduceti 1) \n");
        printf(" Exercitiul 2 : Aratati ca numarul este perfect.(Introduceti 2) \n");
        printf(" Exercitiul 3 : Verificati daca un numar natural este prim.(Introduceti 3) \n");
        printf(" Exercitiul 4 : Calculati ordinul de multiplicitate al unui numar prim k intr-un numar intreg n.(Introduceti 4) \n");
        printf(" Exercitiul 5 : Calculati cel mai mare divizor comun a doua numere intregi.(Introduceti 5) \n");
        scanf("%d", &exercitiu);
        while (exercitiu < 0 || exercitiu > 5)
        {
            printf(" Va rog sa alegeti un exercitiu care exista. \n");
            scanf("%d", &exercitiu);
        }
        if (exercitiu == 1)
        {
            int numar;
            printf(" Ai ales exercitiul 1 : Afisati divizorii naturali ai unui numar intreg. \n");
            printf(" n = ");
            scanf("%d", &numar);
            printf(" Divizorii naturali ai numarului %d sunt : ", numar);
            print_divizori(numar);
        }
        if (exercitiu == 2)
        {
            long int numar;
            printf(" Ai ales exercitiul 2 : Aratati ca numarul este perfect. \n");
            printf(" n = ");
            scanf("%li", &numar);
            printf("\n Numarul %li%s este perfect. \n", numar, perfect(numar) == 1 ? "" : " NU");
        }
        if (exercitiu == 3)
        {
            long int numar;
            printf(" Ai ales exercitiul 3 : Verificati daca un numar natural este prim \n");
            printf(" n = ");
            scanf("%li", &numar);
            printf(" Numarul %li%s este prim. \n", numar, prim(numar) == 1 ? "" : " NU");
        }
        if (exercitiu == 4)
        {
            int numar, k;
            printf(" Ai ales exercitiul 4 : Calculati ordinul de multiplicitate al unui numar prim k intr-un numar intreg n. \n");
            printf(" n = ");
            scanf("%d", &numar);
            printf(" k = ");
            scanf("%d", &k);
            printf(" Ordinul de multiplicitate a numarului %d in numarul %d este de %d ori.", k, numar, ordin_mult(numar, k));
        }
        if (exercitiu == 5)
        {
            int a, b;
            printf(" Ai ales exercitiul 5 : Calculati cel mai mare divizor comun a doua numere intregi. \n");
            printf(" a = ");
            scanf("%d", &a);
            printf(" b = ");
            scanf("%d", &b);
            printf("CMMDC(%d,%d) = %d", a, b, cmmdc(a, b));

        }
    }
    if (tema == 4)
    {
        printf(" Acum va rog fumos sa alegeti exercitiul \n");
        printf(" Exercitiul 1 : Afisati elementele pozitive dintr-un vector de dimensiune n. (Introduceti 1) \n");
        printf(" Exercitiul 2 : Afisati pozitiile dintr-un vector de dimensiune n pe care se gasesc numere pozitive.(Introduceti 2) \n");
        printf(" Exercitiul 3 : Afisati elementele de pe pozitii impare dintr-un vector de dimensiune n.(Introduceti 3) \n");
        printf(" Exercitiul 4 : Afisati elementele unui vector de dimensiune n in ordine inversa.(Introduceti 4) \n");
        printf(" Exercitiul 5 : Verificati daca elementele unui vector de dimensiune n formeaza o progresie aritmetica.(Introduceti 5) \n");
        printf(" Exercitiul 6 : Verificati daca elementele unui vector de dimensiune n formeaza o progresie geometrica.(Introduceti 6) \n");
        printf(" Exercitiul 7 : Calculati produsul scalar al doi vectori de dimensiune n.(Introduceti 7) \n");
        printf(" Exercitiul 8 : Calculati media aritmetica a elementelor nenule dintr-un vector de dimensiune n.(Introduceti 8) \n");
        printf(" Exercitiul 9 : Calculati numarul de aparitii ale valorii maxime dintr-un vector de dimensiune n.(Introduceti 9) \n");
        printf(" Exercitiul 10 : Afisati ultima pozitie pe care se gaseste un element intr-un vector de dimensiune n.(Introduceti 10) \n");
        scanf("%d", &exercitiu);

        while (exercitiu < 0 || exercitiu > 10)
        {
            printf(" Va rog sa alegeti un exercitiu care exista. \n");
            scanf("%d", &exercitiu);
        }
        if (exercitiu == 1)
        {
            int v[100], dimensiune;
            printf(" Ai ales exercitiul 1 : Afisati elementele pozitive dintr-un vector de dimensiune n.\n");
            printf(" n = ");
            scanf("%d", &dimensiune);
            print_pozitive(v, dimensiune);
        }
        if (exercitiu == 2)
        {
            int v[100], dimensiune;
            printf(" Ai ales exercitiul 2 : Afisati pozitiile dintr-un vector de dimensiune n pe care se gasesc numere pozitive.\n");
            printf(" n = ");
            scanf("%d", &dimensiune);
            print_poz_pozitive(v, dimensiune);
        }
        if (exercitiu == 3)
        {
            int v[100], dimensiune;
            printf(" Ai ales exercitiul 3 : Afisati elementele de pe pozitii impare dintr-un vector de dimensiune n.\n");
            printf(" n = ");
            scanf("%d", &dimensiune);
            print_poz_impare(v, dimensiune);

        }
        if (exercitiu == 4)
        {
            int v[100], dimensiune;
            printf(" Ai ales exercitiul 4 : Afisati elementele unui vector de dimensiune n in ordine inversa.\n");
            printf(" n = ");
            scanf("%d", &dimensiune);
            print_reverse(v, dimensiune);
        }
        if (exercitiu == 5)
        {
            int dimensiune;
            float v[100];
            printf(" Ai ales exercitiul 5 : Verificati daca elementele unui vector de dimensiune n formeaza o progresie aritmetica.\n");
            printf(" n = ");
            scanf("%d", &dimensiune);
            printf(" Elementele din vector %s foarmeaza o progresie aritmetica", progresie_aritm(v, dimensiune) == 1 ? " " : " NU ");
        }
        if (exercitiu == 6)
        {
            int dimensiune;
            float v[100];
            printf(" Ai ales exercitiul 6 : Verificati daca elementele unui vector de dimensiune n formeaza o progresie geometrica.\n");
            printf(" n = ");
            scanf("%d", &dimensiune);
            printf(" Elementele din vector%sfoarmeaza o progresie geometrica", progresie_geom(v, dimensiune) == 1 ? " " : " NU ");
        }
        if (exercitiu == 7)
        {
            int dimensiune;
            float v[100], u[100];
            printf(" Ai ales exercitiul 7 : Calculati produsul scalar al doi vectori de dimensiune n.\n");
            printf(" n = ");
            scanf("%d", &dimensiune);
            printf(" Produsul scalar = %f", produs_scalar(v, u, dimensiune));
        }
        if (exercitiu == 8)
        {
            int dimensiune;
            int v[100];
            printf(" Ai ales exercitiul 8 : Calculati media aritmetica a elementelor nenule dintr-un vector de dimensiune n.\n");
            printf(" n = ");
            scanf("%d", &dimensiune);
            printf(" Media aritmetica = %f", media_aritmetica(v, dimensiune));
        }
        if (exercitiu == 9)
        {
            int dimensiune;
            int v[100];
            printf(" Ai ales exercitiul 9 : Calculati numarul de aparitii ale valorii maxime dintr-un vector de dimensiune n.\n");
            printf(" n = ");
            scanf("%d", &dimensiune);
            printf(" Aparitii maxim : %d", aparitii_maxim(v, dimensiune));
        }
        if (exercitiu == 10)
        {
            int dimensiune, x;
            float v[100];
            printf(" Ai ales exercitiul 10 : Afisati ultima pozitie pe care se gaseste un element intr-un vector de dimensiune n.\n");
            printf(" n = ");
            scanf("%d", &dimensiune);
            printf(" Numarul pe care vreti sa il cautati este : ");
            scanf("%d", &x);
            printf(" Numarul cautat se afla pe pozitia : %d", cauta_ultim(v, dimensiune, x));
        }
    }

    printf("\n Daca doriti sa continuati introduceti 1 daca nu introduceti 0.\n");
    scanf("%d", &x);
    printf("\n \n \n \n");
    if (x == 1)
    {
        return main();
    }
    else return 0;
}
s
