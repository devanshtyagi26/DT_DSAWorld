#include <iostream>
using namespace std;

void bubble_sort(int n, int a[]){
    for(int i = 0; i < n-1; i++){
        bool swapped = false;
        for(int j = 0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                swapped = true;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(!swapped){
            break;
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
    bubble_sort(n,a);
    print(n,a);
    return 0;
}