#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;

    int start = 1;
    for(int row=1; row<=n; row++){
        int numbers = row;
        while(numbers--){
            cout<<start<<" ";
            start++;
        }
        cout<<endl;
    }
    return 0;
}
