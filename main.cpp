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
    cout<<"Введите массив из N элементов(N можно поменять в 10 строке кода): ";
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
    mid=a[(f+l)/2]; //вычисление опорного элемента
    int midindex=(f+l)/2;
    cout<<"f="<<f<<"   l="<<l<<endl;
    do{

        while (a[f]<mid and f!=midindex) {
            cout<<f<<"   "<<compare<<"   "<<mid<<endl;
            f++;
            compare++;
            
        }
        if (f!=midindex) compare++;
        cout<<f<<"     "<<compare<<"   "<<mid<<endl;
        while (a[l]>mid and l!=midindex) {
            cout<<l<<"   "<<compare<<"   "<<mid<<endl;
            l--;
            compare++;
            
        }
        if (l!=midindex) compare++;
        cout<<l<<"     "<<compare<<"   "<<mid<<endl;
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
    return a;
}


void qsort(){
    int a[n];
    compare=0;
    countpr=0;
    cout<<"Введите массив из N элементов(N можно поменять в 10 строке кода): ";
    for (int i=0; i<n; i++) cin>>a[i];
    int *c = quicksort(a, 0, n-1);
    cout<<"\nОтсортированный массив: ";
    for (int i=0; i<n; i++)
    cout <<c[i]<<" ";
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
    cout<<"Введите массив из N элементов(N можно поменять в 10 строке кода): ";
    for (int i=0; i<n; i++) cin>>a[i];
    int *c=insertsort(a,n);
    cout<<"\nОтсортированный массив: ";
    for (int i=0; i<n; i++)
    cout <<c[i]<<" ";
    cout << "\nКоличество сравнений = " << compare << "\nКоличество перестановок = " << countpr;
    cout<<"\n\n";
}



int main(){
    setlocale(LC_ALL, "Russian");
    int x=1, q;
    while (x>0){
        cout<<"Введите номер нужной сортировки"<<"\nПузырёк - 1"<<"\nQuickSort - 2"<<"\nВставками - 3\n";
        cin >> q;
        if (q==1) bubble();
        if (q==2) qsort();
        if (q==3) insert();
    }
}


//QUICKSORT: Здесь каждый элемент сравнивается с выбранным(средним), а перестановки производятся сразу между двумя элементами. Если сортируемый массив состоит из 5 элементов: 1 2 3 4 5, то перестановок не будет, а сравнений будет 6, так как в первый заход сначала с 3 сравниваются 1 и 2, а потом 5 и 4. Во второй (контрольный) заход с первым элементом 1 сравнивается 2, а в третий(также контрольный) заход с 3 сравнивается 4. Итого - 6 сравнений. Если наш массив: 5 4 3 2 1, то сравнений будет уже 8, так как во втором и третьем заходе сравнивается 2 с 1 и 3, и 4 с 5 и 3, то есть происходит на 2 сравнения больше. Перестановок же будет 2(5 с 1, а 4 с 1).

//INSERT: при массиве из 5 элементов происходит 1+2+3+4=10 сравнений, так как при каждом i(выбранный элемент) i+1 элемент сравнивается с каждым элементом до него. Количество перестановок же зависит от сортируемого массива. Так, при массиве 5 4 3 2 1 перестановок будет столько же, сколько сравнений - 10: (5 4 3 2 1) -> (4 5 3 2 1), (4 5 3 2 1) -> (3 4 5 2 1) и так далее. Отличие от пузырька заключается в том, что, если пузырек меняет выбранный элемент, постепенно сравнивая и меняя его с каждым предыдущим, то insert сразу ставит элемент на нужное место.
