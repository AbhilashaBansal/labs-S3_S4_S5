// Main function of the C++ program.

#include <iostream>
using namespace std;

void selsort(int a[], int n){
    for(int i=0; i<n-1; i++){
        int min_idx=i;
        for(int j=i+1; j<n; j++){
            if(a[j]<a[min_idx]){
                min_idx = j;
            }
        }
        int temp = a[i];
        a[i]= a[min_idx];
        a[min_idx] = temp;
    }
}

int main()
{
    int a[1000];
    int n;
    cout<<"Enter no of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: \n";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    selsort(a, n);
    cout<<"The sorted array is: \n";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
