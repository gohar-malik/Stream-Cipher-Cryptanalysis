#pragma once

#include "Bruteforce.h"
#include "CImg.h"

using namespace cimg_library;

void printarray(int **& arr, int rows, int columns);

//It takes a pointer to a pointer to an integer and makes a 2-D array out of it
//The size of the array is given as the arguments
void genmatrix(int **&matrix, int rows, int columns);

//It also takes a pointer to a pointer to an integer and makes a 2-D array
//It also assign value of 1 or 0 randomly to all the elements
void genrandom(int **&arr, int rows, int columns);

int XOR(int a, int b);

void streamcipher(int **&m, int**&k, int **&e, int rows, int columns);

void RGB_to_grayscale(CImg<unsigned char> &RGB1, CImg<unsigned char>&grayscale);

void Image_to_Matrix(CImg <unsigned char> & picture, int **&matrix);

void Matrix_to_Image(int **&matrix, CImg<unsigned char>&picture);


