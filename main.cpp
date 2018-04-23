#include <bits/stdc++.h>
#include "Tree.h"
#include "HuffmanEncoder.h"
#include "HuffmanDecoder.h"

using namespace std;


int main() {

     int n;
     string s ;
     int i=0;
     bool choice  ;
     cout <<"Enter the size of your Set"<<endl;
     cin>>n;
     char arr[n];
     cout <<"Enter the symbols of the set"<<endl;

    int counter =n;
        while(counter--){
            cin>>arr[i];
            i++;
         }

     cout<<"If you want to use our Adaptive Huffman algorithm please Enter\n-0- for Encoding \n-1- for Decoding "<<endl;
     cin>>choice;

    if (!choice){
        cout<<"Enter your message"<<endl;
        cin>>s;
        HuffmanEncoder en = HuffmanEncoder(arr, n);
        en.setMessage(s);
        cout <<"The binary encoded message is : \n"<< en.encode()<<endl;
    }
    if(choice){
        cout<<"Enter your stream of bits"<<endl;
        cin>>s;
        HuffmanDecoder d = HuffmanDecoder(arr, n);
        d.setMessage(s);
        cout <<"The readable message is : \n"<<d.decode()<<endl;
    }


return 0;
}
