//
//  main.cpp
//  task 8
//
//  Created by Виталий on 30.11.2020.
//

#include <iostream>
using namespace std;
const int n=5;
int compare, countpr;

//Пузырёк
void bubble() {
    int a[n], k;
    compare=0;
    countpr=0;
    cout<<"Введите массив из 5 элементов: ";
    for (int i=0; i<n; i++) cin>>a[i];
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-1-i; j++) {
            compare++;
          if (a[j]>a[j+1]) {
            countpr++;
            k=a[j];
            a[j]=a[j+1];
            a[j+1]=k;
          }
        }
      }
    cout << "\nОтсортированный массив: ";
    for (int i=0; i<n; i++) cout << a[i] << " ";
    cout << "\nКоличество сравнений = " << compare << "\nКоличество перестановок = " << countpr << "\n\n";
}



//qsort
int* quicksort(int *a, int first, int last){
    int mid, count;
    int f=first, l=last;
    mid=a[(f+l) / 2]; //вычисление опорного элемента
    do{
        compare++;
        while (a[f]<mid) f++;
        while (a[l]>mid) l--;
        if (f<=l) {
            if (f!=l) {
                countpr++;
                count=a[f];
                a[f]=a[l];
                a[l]=count;
            }
            f++;
            l--;
        }
    } while (f<l);
    if (first<l) quicksort(a, first, l);
    if (f<last) quicksort(a, f, last);
    cout<<"yes";
    return a;
}

void qsort(){
    int a[n];
    compare=0;
    countpr=0;
    cout<<"Введите массив из 5 элементов: ";
    for (int i=0; i<n; i++) cin>>a[i];
    int *c = quicksort(a, 0, n-1);
    cout << "\nОтсортированный массив: ";
    for (int i=0; i<n; i++) cout << c[i] << " ";
    
    cout << "\nКоличество сравнений = " << compare << "\nКоличество перестановок = " << countpr;
    cout<<"\n\n";
    
    
}



//insert
int* insertsort(int *a, int n){
    int i, j, key=0, temp=0;
    for ( i=0; i<n-1; i++){
        key=i+1;
        temp=a[key];
        for ( j=i+1; j>0; j--){
            compare++;
            if (temp<a[j-1]){
                countpr++;
                a[j]=a[j-1];
                key=j-1;
            }
        }
        a[key]=temp;
    }
    return a;
}

void insert(){
    int a[n];
    compare=0;
    countpr=0;
    cout<<"Введите массив из 5 элементов: ";
    for (int i=0; i<n; i++) cin>>a[i];
    int *c = insertsort(a, n);
    cout << "\nОтсортированный массив: ";
    for (int i=0; i<n; i++) cout << c[i] << " ";
    
    cout << "\nКоличество сравнений = " << compare << "\nКоличество перестановок = " << countpr;
    cout<<"\n\n";
}



int main(){
    int x=1, q;
    while (x>0){
        cout<<"Введите номер нужной сортировки"<<"\nПузырёк - 1"<<"\nQuickSort - 2"<<"\nВставками - 3\n";
        cin >> q;
        if (q==1) bubble();
        if (q==2) qsort();
        if (q==3) insert();
    }
}

