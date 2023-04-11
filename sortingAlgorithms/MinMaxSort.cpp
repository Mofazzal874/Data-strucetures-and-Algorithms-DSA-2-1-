#include<bits/stdc++.h>
using namespace std;
void swp(int &a , int &b){
    a = a+ b ;
    b = a- b ;
    a = a- b ;
}

void MinMaxIndex(int a[], int n, int &mindx, int &maxdx) {

    mindx = 0 ,  maxdx = 0 ; 
    for (int i = 1; i < n; i++) {
        if (a[i] < a[mindx]) {
            mindx = i;
        }
        if (a[i] > a[maxdx]) {
            maxdx = i;
        }
    }
}

void minMaxSort(int a[], int n) {
    
    for (int i = 0; i < n/2; i++) {

        int minIndex, maxIndex;
        MinMaxIndex(a + i, n - 2*i, minIndex, maxIndex);
        minIndex += i;
        maxIndex += i;
        swp(a[i], a[minIndex]);
        if (maxIndex == i) {
            maxIndex = minIndex;
        }
        swap(a[n - 1 - i], a[maxIndex]);
    }
}
int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i = 0 ; i < n ; i++) cin >> a[i] ;
    minMaxSort(a , n) ;
    for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;
}