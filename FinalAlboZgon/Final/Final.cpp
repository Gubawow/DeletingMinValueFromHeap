#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
//#include <tuple>
using namespace std;

string a, b, c;
int T[15], n = 0;


/*tuple<int, int> krotka() {
    int a, b;
    std::tuple<int, double> result(a, b);
    return result;
}
*/


void drzewo(string x, string y, int z)
{
    string tree;

    if (z < n)
    {
        tree = x;
        if (y == a) tree[tree.length() - 2] = ' ';
        drzewo(tree + c, a, 2 * z + 2);

        tree = tree.substr(0, x.length() - 2);

        cout << tree << y << T[z] << endl;

        tree = x;
        if (y == b) tree[tree.length() - 2] = ' ';
        drzewo(tree + c, b, 2 * z + 1);
    }
}

void wstaw(int v)
{
    int i, j;

    i = n++;
    j = (i - 1) / 2;

    while (i > 0 && T[j] < v)
    {
        T[i] = T[j];
        i = j;
        j = (i - 1) / 2;
    }

    T[i] = v;
}

int MinElement(int kopiec[], int n)
{
    int MinElement = kopiec[0];
    for (int i = 0; i < n; ++i) {
        if (kopiec[i] < MinElement) {
            MinElement = kopiec[i];
            
        }
    }
    
    return MinElement;
}

/*
int MinIndeks(int kopiec[], int n)
{
    int MinElement = kopiec[0];
    int indeks;
    for (int i = 0; i < n; ++i) {
        if (kopiec[i] < MinElement) {
            indeks = i;

        }
    }
    
}
*/

/*
void replaceMin(int arr[], int n, int minHeap)
{
    for (int i = 0; i < n; ++i)
    {
        if (minHeap == arr[i])
        {
            swap(arr[0], arr[i]);
        }
    }
}

//algorytm usuwania korzenia z kopca
void heapPop(int arr[], int arr2[], int n)
{
    int startIdx = ((n - 1) / 2) - 1;
    swap(arr[0], arr[n - 1]);                         //zamiana korzenia z ostatnim lisciem
    for (int i = 0; i < n - 1; ++i)
    {
        arr2[i] = arr[i];                             //usuniecie ostatniego liscia
    }
    for (int i = startIdx; i >= 0; i--)
    {
        drzewo("", "", i);                           //budowa nowego kopca
    }
}
*/

int main()
{
    int i, v;
    srand(time(NULL));
    cout << "Tablica 15 losowych liczb: " << endl;
    a = b = c = "  ";
    a[0] = 201; a[1] = 205; //ASCII
    b[0] = 200; b[1] = 205;
    c[0] = 186;
    for (i = 0; i < 15; i++)
    {
        v = rand() % 100;
        cout << v << " ";
        wstaw(v);
    }
    cout << endl << "Kopiec przed usunieciem elementu minimalnego: ";
    cout << endl << endl;
    //string tlo1[2];
    //string tlo2[2];
    //tlo1[0] = 15;
    //tlo2[0] = 15;
    drzewo("    ", "  ", 0);

    cout << endl << "Oto najmniejszy element tego kopca: " << MinElement(T, 15) << endl;

    cout << endl << "Kopiec po usunieciu najmniejszego elementu: " << endl;

    
}