#pragma once
#ifndef _RC4_H
#define _RC4_H

#include <iostream>
#include <string>
#include<cstring>
#include<stdlib.h>

using namespace std;

class RC4
{
	unsigned char *message;
	//message to be encrypted

	unsigned char *key;
	//key according to which the message will be ciphered

	int S[256];
	//array for key generation algorithm
	//it is always same for RC4

	unsigned char *encrypted;
	//will store the encrypted text


public:

	RC4();

	unsigned char * encrypt(unsigned char *m, unsigned char *t);
	//encrypts the message under the key

	void key_scheduling_algorithm();
	//generates a randomized and shuffled key array that will be XORed with the original text

	void PRG_algorithm();
	//algorithm for further shuffling the array before encryption

	unsigned char* decrypt(unsigned char *m, unsigned char *k);
	//decrypts the message 
};

#endif

