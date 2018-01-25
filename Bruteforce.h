#pragma once
#ifndef _BRUTEFORCE_H
#define _BRUTEFORCE_H

#include "RC4.h"
#include<algorithm>

#define ASCII_CONSIDERED 26
//can range from 0 to 255

#define CASE 97
//equal to the minimum ASCII value considered

#endif

class Brute_Force : public RC4
{
	int keylength;
	//stores the length of key that was known for encryption

	unsigned char* plaintext;
	//the part of plain text known to us

	unsigned char* ciphertext;
	//the cipher to break

	unsigned char* hack;
	//an array for storing permutations to the key and testing them

	unsigned char *temp;
	//stores the deciphered text corresponding to a permutation

	bool m;
	//after checking temp and plain text, it becomes true if temp contains our sample plain text

public:

	Brute_Force();

	void setkeylength();
	//sets keylength to the length of the key that was used for encryption
	//the key size is upto 10 bytes

	void setplaintext();
	// sets the plaintext equal to the part of text that is known to us

	void setciphertext(unsigned char *encrypted);
	//sets the ciphertext

	void decryption_by_brute_force(unsigned char *);
	//decryption by trying permutations of the key

	bool findword(unsigned char *str, unsigned char *);
	//comparison of decrypted text and plain text
};