#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[100][100];
    int count = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j] = count++;
        }
    }

    int sum = 0;
    //for main diagonal elements, row=col
    for(int i=0; i<n; i++){
        sum += a[i][i];
    }
    cout<<sum;
    return 0;
}
