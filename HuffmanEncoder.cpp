#include"HuffmanEncoder.h"
HuffmanEncoder::HuffmanEncoder(char arr[], int n ) {
	tree= Tree();
	encoded="";
	setSymbolsSet(arr, n);
	setParameters();
}

void HuffmanEncoder:: setSymbolsSet(char arr[], int n){

	for (int i = 0; i<n ; i++){
		symbolsSet[i]= arr[i];
	}
	symbolsNo= n;
}
void HuffmanEncoder::setParameters(){
	e = log2(symbolsNo);
	r = symbolsNo - pow(2, e);
}
void HuffmanEncoder::setMessage(string str){
	message = str;
}
// aiding methods
char toChar(int x){
	if (x==1) return '1';
	else return '0';
}

string intToBinary(int x){
	if (x==0) return "0";
	else return intToBinary(x/2)+ toChar(x%2);
}

string binary(int x, int bits){
	string res = intToBinary(x);
	if ((int)res.length()>bits){
			 return res.substr(res.length()-bits,bits );
		}

		while ((int)res.length()<bits){
			res= '0'+res;
		}
		return res;
}
//
string HuffmanEncoder:: getFixedCode(char ch){
	//search in symbols array
	int i;
	for (i=0; i<symbolsNo; i++){
		if (ch == symbolsSet[i] ) break;
	}
	//i+1 = k
      if (1<=i+1 && i+1<=2*r ){
    	  // represent k-1 / i in e+1 bits
    	  return binary(i, e+1);
      }
      else if (i+1>2*r){
    	  // represent k-r-1 / i-r in e bits
    	  return  binary(i-r , e);
      }

}

string HuffmanEncoder::encode(){
		char c;
		for (int i = 0; i<(int)message.length(); i++){
			c = message[i];

			if ( tree.search(c, tree.getRoot())){ //just print char code
				encoded+=tree.binaryCode(c, tree.getRoot());

			}
			else { // print nyt code+ char fixed code
				encoded+=tree.binaryCode(1,  tree.getRoot()) + getFixedCode(c);
			}

			tree.insert(c);
	}
		return encoded;
}
string HuffmanEncoder:: getEncoded()const{
	return encoded;
}
HuffmanEncoder::~HuffmanEncoder() {
	}

