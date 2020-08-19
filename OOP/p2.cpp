#include <iostream>
using namespace std;
int main() {
   int a[10000];
   int b[10000] = {0};
   int n;
   cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int i, j, count = 0;
    for(i=0; i<n; i++){
        if(b[i]!=-1){
            for(j=i+1; j<n; j++){
                if(a[i]==a[j]){
                    count++;
                    b[j] = -1;
                }
            }
        }
    }
    if(count==0){
        cout<<"No repeated elements"<<endl;
    }
    else{
        cout<<"Total number of repeated elements = "<<count<<endl;
    }
   return 0;
}
