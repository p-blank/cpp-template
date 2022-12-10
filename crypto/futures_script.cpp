#include"bits/stdc++.h"
using namespace std;

int main(){
	fstream file;
	string line;
	file.open("futures_calc.txt");
	
	//vector<string> final;
	//int i = 0;
	double res = 0;
	double p = 0, n = 0;
	while(file >> line){
		auto x = stod(line);
		res += x;
		if(abs(x) > 100) cout << x << endl;
		if(x > 0) p += x;
		else n += x;
	}
	cout << res <<  " " << p << " " << n << endl;
	
	//file.close();
	
	//file.open("futures_history.txt");
	//for(auto i : final) file << i << "\n";
	
}