#ifndef HUFFMANDECODER_H_
#define HUFFMANDECODER_H_
#include "Tree.h"

class HuffmanDecoder {
private:

	string message, decoded;
	char symbolsSet[255];
	int symbolsNo;
	int e , r;

public:
	Tree tree;
	HuffmanDecoder(char arr[], int n);
	void setSymbolsSet(char arr[], int n);
	void setParameters();
	void setMessage(string str);
	string decode();
	string getDecoded()const;
	virtual ~HuffmanDecoder();

};


#endif /* HUFFMANDECODER_H_ */
