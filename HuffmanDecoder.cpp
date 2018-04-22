
#include "HuffmanDecoder.h"
HuffmanDecoder::HuffmanDecoder(char arr[], int n) {
		tree= Tree();
		decoded="";
		setSymbolsSet(arr, n);
		setParameters();
}


void HuffmanDecoder:: setSymbolsSet(char arr[], int n){

	for (int i = 0; i<n ; i++){
		symbolsSet[i]= arr[i];
	}
	symbolsNo= n;
}
void HuffmanDecoder::setParameters(){
	e = log2(symbolsNo);
	r = symbolsNo - pow(2, e);
}

int  binartToInt(string str){
	int res = 0;
	reverse(str.begin(),str.end());
	for(int i = 0 ; i < (int) str.size() ; ++i){
		res += (str[i]-'0') * pow(2, i);
	}
	return res;
}
string HuffmanDecoder::decode(){
	string::iterator it= message.begin();
	string str;
	int i = 0;
	char c;

	while (i < (int)message.length()){
		str="";
		if(tree.getRoot()->value==1) { /// No insertion yet
			str= message.substr(0, e);
			i+=e;

			if (binartToInt(str) < r){
				str+= message[i];
				i++;
		    }

			c = symbolsSet[binartToInt(str)];
			decoded+= c;
			tree.insert(c);
		}else { /// Not the first insertion
            str= message[i];
            i++;

            Node *nodetarget=tree.findByBinaryCode(str);

            while( nodetarget->right!=NULL && nodetarget->left!=NULL ){
                str+=message[i];
                i++;
                nodetarget=tree.findByBinaryCode(str);
            }

            c = tree.findByBinaryCode(str)->value;
            if (c==1){ // nyt code
                str= message.substr(i, e);
                i+=e;


                if (binartToInt(str) < r){
                    str+= message[i];
                    i++;

					c = symbolsSet[binartToInt(str)];
                }else{
                	c = symbolsSet[binartToInt(str)+r];
                }

            }

            decoded+= c;
			tree.insert(c);
        }


	}

	return decoded;
}
void HuffmanDecoder::setMessage(string str){
	message = str;
}
string HuffmanDecoder:: getDecoded()const{
	return decoded;
}
HuffmanDecoder::~HuffmanDecoder() {
	// TODO Auto-generated destructor stub
}
