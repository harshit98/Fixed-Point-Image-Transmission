#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "tmwtypes.h"
#include "stdlib.h"
// #include <bits/stdc++.h>

using namespace std;

vector<int> decToBinary(vector<int> &v) { 

	vector<int> b;    // binary vector
    int N = v.size();
	int binaryNum[N]; 
  
    int i = 0;
    while (v[i] > 0) { 
        binaryNum[i] = v[i] % 2;
		b.push_back(binaryNum[i]); 
        v[i] = v[i] / 2; 
        i++; 
    } 

    // for (int j = i - 1; j >= 0; j--) 
    //    cout << binaryNum[j] << "\n";
	return b;
}

int binaryToDec(int n) { 
    int num = n; 
    int dec_value = 0; 
      
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
      
    int temp = num; 
    
	while (temp) 
    { 
        int last_digit = temp % 10; 
        temp = temp/10; 
          
        dec_value += last_digit*base; 
          
        base = base*2; 
    } 
      
    return dec_value; 
}

void decoding(int x2[], int xd[], int length){
	for(int i=0; i < length/6; i++) {
		/****************************** First Quadrant ************************************************/
		/**********************************************************************************************/
		if (x2[i*2]==7 && x2[i*2+1]==7) {
			xd[i*6]=0; xd[i*6+1]=0; xd[i*6+2]=0; xd[i*6+3]=1; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		if (x2[i*2]==7 && x2[i*2+1]==5) {
			xd[i*6]=0;xd[i*6+1]=0; xd[i*6+2]=0;xd[i*6+3]=1; xd[i*6+4]=0;xd[i*6+5]=1;
		}
		if (x2[i*2]==7 && x2[i*2+1]==3) {
			xd[i*6]=0;xd[i*6+1]=0; xd[i*6+2]=0; xd[i*6+3]=1; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==7 && x2[i*2+1]==1) {
			xd[i*6]=0; xd[i*6+1]=0; xd[i*6+2]=0; xd[i*6+3]=1; xd[i*6+4]=1; xd[i*6+5]=0;
		}
		/**********************************************************************************************/
		if (x2[i*2]==5 && x2[i*2+1]==7) {
			xd[i*6]=0; xd[i*6+1]=0; xd[i*6+2]=1; xd[i*6+3]=1; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		if (x2[i*2]==5 && x2[i*2+1]==5) {
			xd[i*6]=0; xd[i*6+1]=0; xd[i*6+2]=1; xd[i*6+3]=1; xd[i*6+4]=0; xd[i*6+5]=1;
		}
		if (x2[i*2]==5 && x2[i*2+1]==3) {
			xd[i*6]=0; xd[i*6+1]=0; xd[i*6+2]=1; xd[i*6+3]=1; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==5 && x2[i*2+1]==1) {
			xd[i*6]=0; xd[i*6+1]=0; xd[i*6+2]=1;xd[i*6+3]=1;xd[i*6+4]=1; xd[i*6+5]=0;
		}
		/**********************************************************************************************/
		if (x2[i*2]==3 && x2[i*2+1]==7) {
			xd[i*6]=0; xd[i*6+1]=1; xd[i*6+2]=1; xd[i*6+3]=1; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		if (x2[i*2]==3 && x2[i*2+1]==5) {
			xd[i*6]=0; xd[i*6+1]=1; xd[i*6+2]=1;xd[i*6+3]=1; xd[i*6+4]=0;xd[i*6+5]=1;
		}
		if (x2[i*2]==3 && x2[i*2+1]==3) {
			xd[i*6]=0; xd[i*6+1]=1; xd[i*6+2]=1; xd[i*6+3]=1; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==3 && x2[i*2+1]==1) {
			xd[i*6]=0; xd[i*6+1]=1; xd[i*6+2]=1; xd[i*6+3]=1; xd[i*6+4]=1; xd[i*6+5]=0;
		}
		/**********************************************************************************************/
		if (x2[i*2]==1 && x2[i*2+1]==7) {
			xd[i*6]=0; xd[i*6+1]=1; xd[i*6+2]=0; xd[i*6+3]=1; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		if (x2[i*2]==1 && x2[i*2+1]==5) {
			xd[i*6]=0; xd[i*6+1]=1; xd[i*6+2]=0; xd[i*6+3]=1; xd[i*6+4]=0; xd[i*6+5]=1;
		}
		if (x2[i*2]==1 && x2[i*2+1]==3) {
			xd[i*6]=0; xd[i*6+1]=1; xd[i*6+2]=0; xd[i*6+3]=1; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==1 && x2[i*2+1]==1) {
			xd[i*6]=0; xd[i*6+1]=1; xd[i*6+2]=0; xd[i*6+3]=1; xd[i*6+4]=1; xd[i*6+5]=0;
		}
		/****************************** End Of First Quadrant ***************************************/
		
		/****************************** Second Quadrant ***********************************************/
		/**********************************************************************************************/
		if (x2[i*2]==-1 && x2[i*2+1]==7) {
			xd[i*6]=0; xd[i*6+1]=0; xd[i*6+2]=0; xd[i*6+3]=0; xd[i*6+4]=1;xd[i*6+5]=0;
		}
		if (x2[i*2]==-3 && x2[i*2+1]==7) {
			xd[i*6]=0; xd[i*6+1]=0; xd[i*6+2]=0; xd[i*6+3]=0; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==-5 && x2[i*2+1]==7) {
			xd[i*6]=0;xd[i*6+1]=0; xd[i*6+2]=0; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=1;
		}
		if (x2[i*2]==-7 && x2[i*2+1]==7) {
			xd[i*6]=0;xd[i*6+1]=0; xd[i*6+2]=0; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		/**********************************************************************************************/
		if (x2[i*2]==-1 && x2[i*2+1]==5) {
			xd[i*6]=0; xd[i*6+1]=0; xd[i*6+2]=1;xd[i*6+3]=0; xd[i*6+4]=1; xd[i*6+5]=0;
		}
		if (x2[i*2]==-3 && x2[i*2+1]==5) {
			xd[i*6]=0; xd[i*6+1]=0; xd[i*6+2]=1; xd[i*6+3]=0; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==-5 && x2[i*2+1]==5) {
			xd[i*6]=0; xd[i*6+1]=0; xd[i*6+2]=1; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=1;
		}
		if (x2[i*2]==-7 && x2[i*2+1]==5) {
			xd[i*6]=0;xd[i*6+1]=0; xd[i*6+2]=1; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		/**********************************************************************************************/
		if (x2[i*2]==-1 && x2[i*2+1]==3) {
			xd[i*6]=0; xd[i*6+1]=1; xd[i*6+2]=1; xd[i*6+3]=0; xd[i*6+4]=1; xd[i*6+5]=0;
		}
		if (x2[i*2]==-3 && x2[i*2+1]==3) {
			xd[i*6]=0; xd[i*6+1]=1; xd[i*6+2]=1; xd[i*6+3]=0; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==-5 && x2[i*2+1]==3) {
			xd[i*6]=0; xd[i*6+1]=1; xd[i*6+2]=1; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=1;
		}
		if (x2[i*2]==-7 && x2[i*2+1]==3) {
			xd[i*6]=0; xd[i*6+1]=1; xd[i*6+2]=1; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		/**********************************************************************************************/
		if (x2[i*2]==-1 && x2[i*2+1]==1) {
			xd[i*6]=0; xd[i*6+1]=1;xd[i*6+2]=0; xd[i*6+3]=0; xd[i*6+4]=1; xd[i*6+5]=0;
		}
		if (x2[i*2]==-3 && x2[i*2+1]==1) {
			xd[i*6]=0; xd[i*6+1]=1; xd[i*6+2]=0;xd[i*6+3]=0; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==-5 && x2[i*2+1]==1) {
			xd[i*6]=0;xd[i*6+1]=1; xd[i*6+2]=0; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=1;
		}
		if (x2[i*2]==-7 && x2[i*2+1]==1) {
			xd[i*6]=0; xd[i*6+1]=1; xd[i*6+2]=0; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		/****************************** End Of Second Quadrant ***************************************/
		
		/****************************** Third Quadrant ***********************************************/
		/**********************************************************************************************/
		if (x2[i*2]==-1 && x2[i*2+1]==-1) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=0; xd[i*6+3]=0; xd[i*6+4]=1; xd[i*6+5]=0;
		}
		if (x2[i*2]==-3 && x2[i*2+1]==-1) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=0; xd[i*6+3]=0; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==-5 && x2[i*2+1]==-1) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=0; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=1;
		}
		if (x2[i*2]==-7 && x2[i*2+1]==-1) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=0; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		/**********************************************************************************************/
		if (x2[i*2]==-1 && x2[i*2+1]==-3) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=1; xd[i*6+3]=0; xd[i*6+4]=1; xd[i*6+5]=0;
		}
		if (x2[i*2]==-3 && x2[i*2+1]==-3) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=1; xd[i*6+3]=0; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==-5 && x2[i*2+1]==-3) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=1; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=1;
		}
		if (x2[i*2]==-7 && x2[i*2+1]==-3) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=1; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		/**********************************************************************************************/
		if (x2[i*2]==-1 && x2[i*2+1]==-5) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=1; xd[i*6+3]=0; xd[i*6+4]=1; xd[i*6+5]=0;
		}
		if (x2[i*2]==-3 && x2[i*2+1]==-5) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=1; xd[i*6+3]=0; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==-5 && x2[i*2+1]==-5) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=1; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=1;
		}
		if (x2[i*2]==-7 && x2[i*2+1]==-5) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=1; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		/**********************************************************************************************/
		if (x2[i*2]==-1 && x2[i*2+1]==-7) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=0; xd[i*6+3]=0; xd[i*6+4]=1; xd[i*6+5]=0;
		}
		if (x2[i*2]==-3 && x2[i*2+1]==-7) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=0; xd[i*6+3]=0; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==-5 && x2[i*2+1]==-7) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=0; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=1;
		}
		if (x2[i*2]==-7 && x2[i*2+1]==-7) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=0; xd[i*6+3]=0; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		/****************************** End Of Third Quadrant ***************************************/
		
		/****************************** Fourth Quadrant ***********************************************/
		/**********************************************************************************************/
		if (x2[i*2]==7 && x2[i*2+1]==-1) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=0; xd[i*6+3]=1; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		if (x2[i*2]==5 && x2[i*2+1]==-1) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=0; xd[i*6+3]=1; xd[i*6+4]=0; xd[i*6+5]=1;
		}
		if (x2[i*2]==3 && x2[i*2+1]==-1) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=0; xd[i*6+3]=1; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==1 && x2[i*2+1]==-1) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=0; xd[i*6+3]=1; xd[i*6+4]=1; xd[i*6+5]=0;
		}
		/**********************************************************************************************/
		if (x2[i*2]==7 && x2[i*2+1]==-3) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=1; xd[i*6+3]=1; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		if (x2[i*2]==5 && x2[i*2+1]==-3) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=1; xd[i*6+3]=1; xd[i*6+4]=0; xd[i*6+5]=1;
		}
		if (x2[i*2]==3 && x2[i*2+1]==-3) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=1; xd[i*6+3]=1; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==1 && x2[i*2+1]==-3) {
			xd[i*6]=1; xd[i*6+1]=1; xd[i*6+2]=1; xd[i*6+3]=1; xd[i*6+4]=1; xd[i*6+5]=0;
		}
		/**********************************************************************************************/
		if (x2[i*2]==7 && x2[i*2+1]==-5) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=1; xd[i*6+3]=1; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		if (x2[i*2]==5 && x2[i*2+1]==-5) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=1; xd[i*6+3]=1; xd[i*6+4]=0; xd[i*6+5]=1;
		}
		if (x2[i*2]==3 && x2[i*2+1]==-5) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=1; xd[i*6+3]=1; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==1 && x2[i*2+1]==-5) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=1; xd[i*6+3]=1; xd[i*6+4]=1; xd[i*6+5]=0;
		}
		/**********************************************************************************************/
		if (x2[i*2]==7 && x2[i*2+1]==-7) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=0; xd[i*6+3]=1; xd[i*6+4]=0; xd[i*6+5]=0;
		}
		if (x2[i*2]==5 && x2[i*2+1]==-7) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=0; xd[i*6+3]=1; xd[i*6+4]=0; xd[i*6+5]=1;
		}
		if (x2[i*2]==3 && x2[i*2+1]==-7) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=0; xd[i*6+3]=1; xd[i*6+4]=1; xd[i*6+5]=1;
		}
		if (x2[i*2]==1 && x2[i*2+1]==-7) {
			xd[i*6]=1; xd[i*6+1]=0; xd[i*6+2]=0; xd[i*6+3]=1; xd[i*6+4]=1; xd[i*6+5]=0;
		}
		/****************************** End Of Fourth Quadrant ***************************************/
	}
}

// int norm(creal_T h) {
//	return ((int)pow(h.re,2) + (int)pow(h.im,2));
// }

int main() {
	
	FILE *fp1;
	fp1 = fopen("new.bmp", "rb");
	
	char code[1024];
	int n=0;
   	do {
		code[n]=(char)fgetc(fp1);
		n++;
    } while(!feof(fp1));

	int h[n];
    for(int i=0;i<n;i++){
    	h[i]=code[i]+128;
	}
    		
    vector<int> x;
	for(int i=0; i<n; i++) {
		int a=h[i];
		int reva=x.size();
		int t=0;
		while(a||t<8){
			x.push_back(a%2);
			a=a/2;
			t++;	
		}
		reverse(x.begin()+reva,x.end());			
	}

	int length = x.size();
	// int y[length/2];
	int y[length/6];
	
	for(int i=0; i<length/6; i++){
		/****************************** First Quadrant ************************************************/
		/**********************************************************************************************/
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = 7; y[i*2+1] = 7;
		}
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = 7; y[i*2+1] = 5;
		}
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = 7; y[i*2+1] = 3;
		}
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = 7; y[i*2+1] = 1;
		}
		/*********************************************************************************************/
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = 5; y[i*2+1] = 7;
		}
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = 5; y[i*2+1] = 5;
		}
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = 5; y[i*2+1] = 3;
		}
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = 5; y[i*2+1] = 1;
		}
		/*********************************************************************************************/
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = 3; y[i*2+1] = 7;
		}
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = 3; y[i*2+1] = 5;
		}
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = 3; y[i*2+1] = 3;
		}
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = 3; y[i*2+1] = 1;
		}
		/*********************************************************************************************/
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = 1; y[i*2+1] = 7;
		}
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = 1; y[i*2+1] = 5;
		}
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = 1; y[i*2+1] = 3;
		}
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = 1; y[i*2+1] = 1;
		}
		/****************************** End Of First Quadrant ***************************************/
		
		/****************************** Second Quadrant ***********************************************/
		/**********************************************************************************************/
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = -1; y[i*2+1] = 7;
		}
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = -3; y[i*2+1] = 7;
		}
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = -5; y[i*2+1] = 7;
		}
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = -7; y[i*2+1] = 7;
		}
		/**********************************************************************************************/
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = -1; y[i*2+1] = 5;
		}
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = -3; y[i*2+1] = 5;
		}
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = -5; y[i*2+1] = 5;
		}
		if (x[i*6]==0 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = -7; y[i*2+1] = 5;
		}
		/**********************************************************************************************/
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = -1; y[i*2+1] = 3;
		}
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = -3; y[i*2+1] = 3;
		}
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = -5; y[i*2+1] = 3;
		}
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = -7; y[i*2+1] = 3;
		}
		/**********************************************************************************************/
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = -1; y[i*2+1] = 1;
		}
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = -3; y[i*2+1] = 1;
		}
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = -5; y[i*2+1] = 1;
		}
		if (x[i*6]==0 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = -7; y[i*2+1] = 1;
		}
		/****************************** End Of Second Quadrant ***************************************/
	
		/****************************** Third Quadrant ***********************************************/
		/**********************************************************************************************/
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = -1; y[i*2+1] = -1;
		}
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = -3; y[i*2+1] = -1;
		}
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = -5; y[i*2+1] = -1;
		}
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = -7; y[i*2+1] = -1;
		}
		/**********************************************************************************************/
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = -1; y[i*2+1] = -3;
		}
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = -3; y[i*2+1] = -3;
		}
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = -5; y[i*2+1] = -3;
		}
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = -7; y[i*2+1] = -3;
		}
		/**********************************************************************************************/
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = -1; y[i*2+1] = -5;
		}
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = -3; y[i*2+1] = -5;
		}
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = -5; y[i*2+1] = -5;
		}
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = -7; y[i*2+1] = -5;
		}
		/**********************************************************************************************/
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = -1; y[i*2+1] = -7;
		}
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = -3; y[i*2+1] = -7;
		}
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = -5; y[i*2+1] = -7;
		}
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==0 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = -7; y[i*2+1] = -7;
		}
		/****************************** End Of Third Quadrant ***************************************/
		
		/****************************** Fourth Quadrant ***********************************************/
		/**********************************************************************************************/
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = 7; y[i*2+1] = -1;
		}
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = 5; y[i*2+1] = -1;
		}
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = 3; y[i*2+1] = -1;
		}
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = 1; y[i*2+1] = -1;
		}
		/**********************************************************************************************/
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = 7; y[i*2+1] = -3;
		}
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = 5; y[i*2+1] = -3;
		}
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = 3; y[i*2+1] = -3;
		}
		if (x[i*6]==1 && x[i*6+1]==1 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = 1; y[i*2+1] = -3;
		}
		/**********************************************************************************************/
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = 7; y[i*2+1] = -5;
		}
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = 5; y[i*2+1] = -5;
		}
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = 3; y[i*2+1] = -5;
		}
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==1 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = 1; y[i*2+1] = -5;
		}
		/**********************************************************************************************/
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==0) {
			y[i*2] = 7; y[i*2+1] = -7;
		}
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==0 && x[i*6+5]==1) {
			y[i*2] = 5; y[i*2+1] = -7;
		}
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==1) {
			y[i*2] = 3; y[i*2+1] = -7;
		}
		if (x[i*6]==1 && x[i*6+1]==0 && x[i*6+2]==0 && x[i*6+3]==1 && x[i*6+4]==1 && x[i*6+5]==0) {
			y[i*2] = 1; y[i*2+1] = -7;
		}
		/****************************** End Of Fourth Quadrant ***************************************/
	}
	
	ofstream fp3;
	fp3.open("QAMDATA.txt");
	fp3 << "TEXT" << endl;
	
	// for (int i=0;i<length/2;i+=4){
	//	fp3 << y[i] << ", " << y[i+1] << ", " << y[i+2] << ", " << y[i+3] << endl;
	// }
	
	for (int i = 0; i < length/6; i += 6) {
		fp3 << y[i] << ", " << y[i+1] << ", " << y[i+2] << ", " << y[i+3] << ", " << y[i+4] << ", " << y[i+5] << endl;
	}
	
	fp3.close();
	
	//int xd[n*8];
	int xd[n*32];
	decoding(y,xd,n*32);
	//decoding(y,xd,n*8);

	vector<int>v;
	/* for(int i=0;i<n*8;i+=8){	
		int u=0;
		u+=xd[i]*pow(2,7);
		u+=xd[i+1]*pow(2,6);
		u+=xd[i+2]*pow(2,5);
		u+=xd[i+3]*pow(2,4);
		u+=xd[i+4]*pow(2,3);
		u+=xd[i+5]*pow(2,2);
		u+=xd[i+6]*pow(2,1);
		u+=xd[i+7]*pow(2,0);
		v.push_back(u);	
	} */
	for (int i=0; i < n*32; i += 32) {
		int u=0;
		u+=xd[i]*pow(2,31);
		u+=xd[i+1]*pow(2,30);
		u+=xd[i+2]*pow(2,29);
		u+=xd[i+3]*pow(2,28);
		u+=xd[i+4]*pow(2,27);
		u+=xd[i+5]*pow(2,26);
		u+=xd[i+6]*pow(2,25);
		u+=xd[i+7]*pow(2,24);
		u+=xd[i+7]*pow(2,23);
		u+=xd[i+7]*pow(2,22);
		u+=xd[i+7]*pow(2,21);
		u+=xd[i+7]*pow(2,20);
		u+=xd[i+7]*pow(2,19);
		u+=xd[i+7]*pow(2,18);
		u+=xd[i+7]*pow(2,17);
		u+=xd[i+7]*pow(2,16);
		u+=xd[i+7]*pow(2,15);
		u+=xd[i+7]*pow(2,14);
		u+=xd[i+7]*pow(2,13);
		u+=xd[i+7]*pow(2,12);
		u+=xd[i+7]*pow(2,11);
		u+=xd[i+7]*pow(2,10);
		u+=xd[i+7]*pow(2,9);
		u+=xd[i+7]*pow(2,8);
		u+=xd[i+7]*pow(2,7);
		u+=xd[i+7]*pow(2,6);
		u+=xd[i+7]*pow(2,5);
		u+=xd[i+7]*pow(2,4);
		u+=xd[i+7]*pow(2,3);
		u+=xd[i+7]*pow(2,2);
		u+=xd[i+7]*pow(2,1);
		u+=xd[i+7]*pow(2,0);
		v.push_back(u);
	}

	char q[n];
	for(int i=0;i<n;i++){
		q[i]=(char)(v[i]-128);	
	}
	
	FILE *fp5;
	fp5=fopen("finalbaldman.bmp","wb");
	
	for(int i=0;i<n;i++) {
		fputc(q[i],fp5);
	}
	
	fclose(fp1);
	fclose(fp5);
	return 0;
}
