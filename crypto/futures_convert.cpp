#include"bits/stdc++.h"
using namespace std;

int main(){
	fstream file;
	string line;
	file.open("futures_history.txt");
	
	vector<string> final;
	int i = 0;
	while(getline(file, line)){
		if(i % 6 == 4) final.push_back(line);
		// cout << i;
		i++;
	}
	
	file.close();
	
	fstream f2;
	f2.open("futures_calc.txt", ios::out);
	for(auto i : final) f2 << i << " ";
	for(auto i : final) cout << i << "\n";
	cout << final.size();
	
}