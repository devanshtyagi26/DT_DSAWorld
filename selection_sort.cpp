#include <iostream>
using namespace std;

void selection_sort(int n, int a[]){
    for(int i = 0; i<n-1; i++){
        int min = i;
        for(int j = i+1; j<n; j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        if(min !=i){
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

void print(int n, int a[]){
    cout<<"\n[ ";
    for(int i = 0; i<n; i++){
        cout<< a[i]<<" ";
    }
    cout<<"]";
}

int main(){
    int n;
    cout<< "Enter the number of elements: ";
    cin >> n;
    int* a = new int[n];
    cout<<"Enter the elememts\n";
    for(int i = 0; i<n; i++){
        cout<<"Element "<<i+1<<": ";
        cin >> a[i];
    }
    
    print(n, a);
    selection_sort(n,a);
    print(n,a);
    return 0;
}