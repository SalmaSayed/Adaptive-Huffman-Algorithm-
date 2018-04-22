#ifndef HUFFMANENCODER_H_
#define HUFFMANENCODER_H_

#include "Tree.h"
using namespace std;

class HuffmanEncoder {
private:
	char symbolsSet[255];
	int symbolsNo;
	Tree tree;
	int e , r;
	string message, encoded;
	string getFixedCode(char ch);

public:

	HuffmanEncoder(char arr[], int n);
	void setSymbolsSet(char arr[],int n);
	void setMessage(string str);
	void setParameters();
	string encode();
	string getEncoded()const;
	virtual ~HuffmanEncoder();
};

#endif /* HUFFMANENCODER_H_ */
