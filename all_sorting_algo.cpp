#include <iostream>
using namespace std;

template <class T>
class sort
{
private:
    void swap(T a[], int x, int y){
        T temp = a[x];
        a[x] = a[y];
        a[y] = temp; 
    }
    
public:
    void print(int n, T a[]){
        cout << "[ ";
        for(int i = 0; i<n; i++){
            cout << a[i] << " ";
        }
        cout << "]\n";
    }
    void bubble_sort(int n, T a[]){
        cout << "\nBubble Sort\n";
        for(int i = 0; i<n-1; i++){
            for(int j = 0; j < n-i-1; j++){
                if(a[j]>a[j+1]){
                    swap(a,j,j+1);
                }
            }
        }
    }
    void insertion_sort(int n, T a[]){
        cout <<"\nInsertion Sort\n";
        for(int i = 1; i<n; i++){
            T temp = a[i];
            int j = i-1;
            for(j; j>=0 && a[j] > temp; j--){
                a[j+1] = a[j];
            }
            a[j+1] = temp;
        }
    }
    void selection_sort(int n, T a[]){
        cout << "\nSelection Sort\n";
        for(int i = 0; i<n-1; i++){
            T min = i;
            for(int j = i+1; j<n; j++){
                if(a[j]<a[min]){
                    min = j;
                }
                if(min !=i){
                    swap(a,i,min);
                }
            }

        }
    }
};


int main(){
    sort <int> S;
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int* a = new int[n];
    cout<<"Enter the Elements\n";
    for(int i = 0; i<n; i++){
        cout<<"Element "<<i+1<<" : ";
        cin >> a[i];
    }
    S.print(n,a);
    int c;
    cout<<"\nChoose the sorting Algorithm:\n";
    cout << "1. Bubble Sort\n";    
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "\nChoose: ";
    cin >> c;

    switch (c)
    {
    case 1:
        S.bubble_sort(n,a);
        S.print(n,a);
        break;
    case 2:
        S.selection_sort(n,a);
        S.print(n,a);
        break;
    case 3:
        S.insertion_sort(n,a);
        S.print(n,a);
        break;
    default:
        cout << "Invalid Argument";
        break;
    }    
    cout << "\nEnd";
    
    return 0;
}