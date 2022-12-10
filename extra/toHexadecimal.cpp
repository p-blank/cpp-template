string toHex(int n){
	stringstream ss;
	ss << hex << n;
	string s;
	ss >> s;
	return s;
}