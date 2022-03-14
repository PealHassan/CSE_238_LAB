#include <bits/stdc++.h>

using namespace std;

void genRandomArray(int ar[])
{
    srand(time(0));
    for(int i=0; i<10000; i++)
    {
        int x = rand()%1000000;
        ar[i] = x;
    }
}

void merge(int ar[], int x, int y, int r)
{
    int i, j, k;
    int a = y - x + 1;
    int b = r - y;
    int left[a], Right[b];
    for (i = 0; i < a; i++) left[i] = ar[x + i];
    for (i = 0; i < b; i++) Right[i] = ar[y + 1 + i];
    i = j = 0;
    k = x;
    while (i < a && j < b)
    {
        if (left[i] <= Right[j]) {ar[k] = left[i], i++;}
        else {ar[k] = Right[j], j++;}
        k++;
    }
    while (i < a)
    {
        ar[k] = left[i];
        i++, k++;
    }
    while (j < b)
    {
        ar[k] = Right[j];
        j++, k++;
    }
}

void mergeSort(int ar[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(ar, m + 1, r);
        mergeSort(ar, l, m);
        merge(ar, l, m, r);
    }
}

int part(int ar[], int l, int h)
{
    int pivot = ar[h];
    int i = (l - 1);
    for (int j = l; j <= h - 1; j++)
        if (ar[j] <= pivot) {i++, swap(ar[i], ar[j]);}
    swap(ar[i + 1], ar[h]);
    return (i + 1);
}

int randomPivot(int ar[], int l, int h)
{
    srand(time(NULL));
    int ran = l + rand() % (h - l);
    swap(ar[ran], ar[h]);
    return part(ar, l, h);
}

void quickSort(int ar[], int l, int h)
{
    if (l < h)
    {
        int pivot = randomPivot(ar, l, h);
        quickSort(ar, pivot + 1, h);
        quickSort(ar, l, pivot - 1);
    }
}

int main()
{
    int ar[10002];
    double diff1 = 0, diff2 = 0;
    for(int i = 0; i < 1000; i++)
    {
        genRandomArray(ar);
        auto start = chrono::steady_clock::now();
        mergeSort(ar, 0, 9999);
        auto end = chrono::steady_clock::now();
        diff1 += chrono::duration <double, milli> (end - start).count();
        start = chrono::steady_clock::now();
        quickSort(ar, 0, 9999);
        end = chrono::steady_clock::now();
        diff2 += chrono::duration <double, milli> (end - start).count();
    }
    cout << "Total time for execution of Merge Sort: " << diff1 << " ms" << endl;
    cout << "Total time for execution of Quick Sort: " << diff2 << " ms" << endl;
    return 0;
}
