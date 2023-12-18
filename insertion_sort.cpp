#include <iostream>
using namespace std;

void print(int n, int a[]){
    cout<< "[ ";
    for(int i = 0; i<n; i++){
        cout << a[i]<<" ";
    }
    cout<< "]";
}

void insertion(int n, int a[]){
    for(int i = 1; i<n; i++){
        int temp = a[i];
        int j = i-1;
        for(j; j>=0 && a[j]>temp; j--){
            a[j+1] = a[j]; 
        }
        a[j+1] = temp;
    }

}

int main(){
    int n;
    int* a = new int[n];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout<<"Enter the elements: \n";
    for(int i = 0; i<n; i++){
        cout<<"Element " << i+1<<": ";
        cin>>a[i];
    }
    

    print(n,a);
    cout<<endl;
    insertion(n, a);
    print(n,a);

    }