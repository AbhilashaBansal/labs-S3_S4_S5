#include <iostream>
using namespace std;
int main() {
    char str[100];
    char output[100];
    int j=0;
    cin>>str;
    for(int i=0; str[i]!='\0'; i++){
        if(isalpha(str[i])){
            output[j] = str[i];
            j++;
        }
    }
    output[j] = '\0';
    cout<<output;
    return 0;
}
