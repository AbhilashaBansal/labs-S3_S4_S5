#include <iostream>
using namespace std;

void merge(int a[], int s, int e){
    int mid = (s+e)/2;
    int i = s, j = mid+1, k=s;
    int temp[1000];
    while(i<=mid && j<=e){
        if(a[i]<=a[j]){
            temp[k] = a[i];
            i++, k++;
        }
        else{
            temp[k] = a[j];
            k++, j++;
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++] = a[j++];
    }
    for(int m=s; m<=e; m++){
        a[m] = temp[m];
    }
    return;
}

void merge1(int a[], int s, int e, int mid){
    int i = s, j = mid+1, k=s;
    int temp[1000];
    while(i<=mid && j<=e){
        if(a[i]<=a[j]){
            temp[k] = a[i];
            i++, k++;
        }
        else{
            temp[k] = a[j];
            k++, j++;
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++] = a[j++];
    }
    for(int m=s; m<=e; m++){
        a[m] = temp[m];
    }
    return;
}

void mergeSortIterative(int a[], int n){
    int cur_size, start;

    for(cur_size=1; cur_size<=n; cur_size*=2){
        for(start=0; start<=n-1; start += 2*cur_size){
            int mid = min(start+cur_size-1, n-1);
            int end = min(start+cur_size+cur_size-1, n-1);
            merge1(a, start, end, mid);
        }
    }
}

void mergeSortRecursive(int a[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergeSortRecursive(a, s, mid);
    mergeSortRecursive(a, mid+1, e);
    merge(a, s, e);
    return;
}

int main()
{
    cout<<"Enter the no of elements in array: ";
    int n;
    cin>>n;
    
    int *a = new int[n];
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    int choice;
    cout<<"Enter 1 for ITERATIVE merge sort and 2 for RECURSIVE merge sort: ";
    cin>>no;
    
    if(no==1){
        cout<<"PERFORMING ITERATIVE MERGE SORT\n";
        mergeSortIterative(a, n);
    }
    
    else if(no==2){
        cout<<"PERFORMING RECURSIVE MERGE SORT\n";
        mergeSortRecursive(a, n);
    }
    
    else{
        cout<<"Invalid Input\n";
    }
    cout<<"Sorted elements are: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
