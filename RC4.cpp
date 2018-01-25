#include "RC4.h"

RC4::RC4()
{

}

unsigned char * RC4::encrypt(unsigned char *m, unsigned char *t)
{

	message = m;
	key = t;
	encrypted = new unsigned char[strlen((char*)message) + 1];
	//making a new array in the heap

	key_scheduling_algorithm();

	PRG_algorithm();

	return encrypted;
}

void RC4::key_scheduling_algorithm()
{

	int i, j = 0, k;
	//variables for loops

	int K[256];
	//array that will be filled from letters from the key
	//it is different for different pass keys

	for (i = 0; i < 256; i++)
	{
		S[i] = i;
		//storing ascending numbers in the array

		K[i] = key[i % strlen((char*)key)];
		//array will contain ASCII values of letters from the key
	}

	for (i = 0; i < 256; i++)
	{
		j = (j + S[i] + K[i]) % 256;
		//generates an index for swapping

		k = S[i];
		S[i] = S[j];
		S[j] = S[i];
		//swapping the values at position i and j
	}
}

void RC4::PRG_algorithm()
{

	int i = 0, j = 0;
	//for storing the indexes during swapping

	int dummy;
	//used during swapping

	int k;
	//loop variable

	int s;
	//used for filling encrypted message;

	for (k = 0; k < strlen((char*)message); k++)
	{
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		//generating pseudo random numbers for swapping;

		dummy = S[i];
		S[i] = S[j];
		S[j] = dummy;
		//swapping done

		s = (S[i] + S[j]) % 256;

		//XOR operation

		if (S[s] == message[k])
		{
			encrypted[k] = message[k];
		}
		else
		{
			encrypted[k] = S[s] ^ message[k];
		}
	}

	encrypted[k] = '\0';
	//marks the end of the message

}

unsigned char* RC4::decrypt(unsigned char *m, unsigned char *k)
{

	return encrypt(m, k);

	//we have called the encrypt method again because of a basic property of XOR
	//  A XOR B XOR B
	//= A XOR (B XOR B)
	//= A XOR 0
	//= A
}