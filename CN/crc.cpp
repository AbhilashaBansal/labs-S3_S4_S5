#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>
#define pb push_back
#define YES cout<<"YES \n"
#define NO cout<<"NO \n"

#define mod (ll)1000000007

string xor1(string a, string b){
	
	string result = "";
	
	int n = b.length();

	for(int i = 1; i < n; i++){
		if (a[i] == b[i])
			result += "0";
		else
			result += "1";
	}
	return result;
}

// Performs Modulo-2 division
string mod2div(string divident, string divisor){
	
	// Number of bits to be XORed at a time.
	int pick = divisor.length();
	
	// Slicing the divident to appropriate length for particular step
	string tmp = divident.substr(0, pick);
	
	int n = divident.length();
	
	while (pick < n){
		if (tmp[0] == '1')
		
			// Replace the divident by the result of XOR and pull 1 bit down
			tmp = xor1(divisor, tmp) + divident[pick];
		else
		
			// If leftmost bit is '0'.
			// If the leftmost bit of the dividend (or the
			// part used in each step) is 0, the step cannot
			// use the regular divisor; we need to use an
			// all-0s divisor.
			tmp = xor1(std::string(pick, '0'), tmp) +
				divident[pick];
				
		// Increment pick to move further
		pick += 1;
	}
	
	// For the last n bits, we have to carry it out normally as increased value of pick will cause Index Out of Bounds.
	if (tmp[0] == '1')
		tmp = xor1(divisor, tmp);
	else
		tmp = xor1(std::string(pick, '0'), tmp);
		
	return tmp;
}

void encodeData(string data, string key){
    cout << "Data Word : "<< data << "\n";
	int l_key = key.length();
	
	// Appends n-1 zeroes at end of data
	string appended_data = (data + std::string(l_key - 1, '0'));
	
	string remainder = mod2div(appended_data, key);
	
	// Append remainder in the original data
	string codeword = data + remainder;
	cout << "Remainder : "<< remainder << "\n";
	cout << "Code Word (Data Word + Remainder) :"
		<< codeword << "\n";
}

int main(){
	string data = "100100";
	string key = "1101";
	
	encodeData(data, key);
	return 0;
}
