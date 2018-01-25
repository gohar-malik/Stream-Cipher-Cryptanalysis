#include "ImageStreamCipher.h"


int main()
{
start:int choice;
	cout << "--------------------Cryptanalysis of Stream Cipher------------------" << endl;
	cout << "Enter the adjacent digit: " << endl;
	cout << "1. Encrypt and Decrypt an Image." << endl;
	cout << "2. Break the cipher using two encrypted images." << endl;
	cout << "3. Break the cipher using two encrypted images and an Original." << endl;
	cout << "4. Cryptanalysis of RC4 Stream Cipher." << endl;
	cout << "5. Exit" << endl;
	cin >> choice;

	
	

	switch (choice)
	{
	case 1:
	{
		system("cls");
		char imagename[100];
		cout << "Enter the name of the image with extension: ";
		cin >> imagename;

		CImg <unsigned char> image(imagename),
			gray(image.width(), image.height(), 1, 1, 0);
		CImgDisplay main_disp(image, "image");
		RGB_to_grayscale(image, gray);
		CImgDisplay gray_disp(gray, "gray");

		int **imagematrix;
		Image_to_Matrix(gray, imagematrix);

		int**key;
		CImg <unsigned char> keyimage(image.width(), image.height(), 1, 1, 0);
		genrandom(key, image.height(), image.width());
		Matrix_to_Image(key, keyimage);
		CImgDisplay kimage(keyimage, "KEY");

		int**encryptedmatrix;
		CImg <unsigned char> encrypted(image.width(), image.height(), 1, 1, 0);
		genmatrix(encryptedmatrix, image.height(), image.width());

		streamcipher(imagematrix, key, encryptedmatrix, image.height(), image.width());

		Matrix_to_Image(encryptedmatrix, encrypted);
		CImgDisplay eimage(encrypted, "Encrypted Image");

		int **decryptedmatrix;
		CImg <unsigned char> decrypted(image.width(), image.height(), 1, 1, 0);
		genmatrix(decryptedmatrix, image.height(), image.width());

		streamcipher(encryptedmatrix, key, decryptedmatrix, image.height(), image.width());

		Matrix_to_Image(decryptedmatrix, decrypted);
		CImgDisplay dimage(decrypted, "Decrypted Image");

		system("cls");

		cout << "Images in Matrices of 1s and 0s: " << endl;

		cout << "Grayscale Image: " << endl;
		printarray(imagematrix, image.height(), image.width());
		cout << endl;

		cout << "Key: " << endl;
		printarray(key, image.height(), image.width());
		cout << endl;

		cout << "Encrypted: " << endl;
		printarray(encryptedmatrix, image.height(), image.width());
		cout << endl;

		cout << "Decrypted: " << endl;
		printarray(decryptedmatrix, image.height(), image.width());
		char sname[100];
		cout << endl << "Enter the name with .bmp to save encryptedfile: ";
		cin >> sname;
		encrypted.save(sname);
		system("pause");
		system("cls");
		goto start;
	}

	case 2:
	{
		system("cls");
		char name1[100], name2[100];
		cout << "Enter the name of the first encrypted image: ";
		cin >> name1;
		cout << "Enter the name of the second encrypted image: ";
		cin >> name2;

		CImg <unsigned char> image1(name1), image2(name2);
		CImgDisplay p1(image1, "Image 1"), p2(image2, "Image 2");

		int **matrix1, **matrix2;
		Image_to_Matrix(image1, matrix1);
		Image_to_Matrix(image2, matrix2);

		int** cracked;
		genmatrix(cracked, image1.height(), image1.width());

		streamcipher(matrix1, matrix2, cracked, image1.height(), image1.width());

		CImg<unsigned char> cimage(image1.width(), image1.height(), 1, 1, 0);
		Matrix_to_Image(cracked, cimage);
		CImgDisplay p3(cimage, "Cracked!");

		cout << "Images in Matrices of 1s and 0s: " << endl;

		cout << "Image 1: " << endl;
		printarray(matrix1, image1.height(), image1.width());
		cout << endl;

		cout << "Image 2: " << endl;
		printarray(matrix2, image1.height(), image1.width());
		cout << endl;

		cout << "Cracked: " << endl;
		printarray(cracked, image1.height(), image1.width());
		cout << endl;
		char name[100];
		cout << endl << "Enter a name for the Cracked image: ";
		cin >> name;
		cimage.save(name);
		system("pause");
		system("cls");
		goto start;
	}

	case 3:
	{
		system("cls");
		char name1[100], name2[100], name3[100];
		cout << "Enter the name of the first encrypted image: ";
		cin >> name1;
		cout << "Enter the name of the second encrypted image: ";
		cin >> name2;
		cout << "Enter the name of an Original image: ";
		cin >> name3;



		CImg <unsigned char> image1(name1), image2(name2), Oimage(name3);
		CImgDisplay p1(image1, "Image 1"), p2(image2, "Image 2"), p3(Oimage, "Original");

		int **matrix1, **matrix2, **Omatrix;
		Image_to_Matrix(image1, matrix1);
		Image_to_Matrix(image2, matrix2);
		Image_to_Matrix(Oimage, Omatrix);

		int** cracked;
		genmatrix(cracked, image1.height(), image1.width());

		int** extracted;
		genmatrix(extracted, image1.height(), image1.width());

		streamcipher(matrix1, matrix2, cracked, image1.height(), image1.width());
		streamcipher(cracked, Omatrix, extracted, image1.height(), image1.width());

		CImg<unsigned char> cimage(image1.width(), image1.height(), 1, 1, 0);
		Matrix_to_Image(extracted, cimage);
		CImgDisplay p4(cimage, "The Second Image");

		cout << "Images in Matrices of 1s and 0s: " << endl;

		cout << "Image 1: " << endl;
		printarray(matrix1, image1.height(), image1.width());
		cout << endl;

		cout << "Image 2: " << endl;
		printarray(matrix2, image1.height(), image1.width());
		cout << endl;

		cout << "Original Image: " << endl;
		printarray(Omatrix, image1.height(), image1.width());
		cout << endl;


		cout << "The Second Original Image: " << endl;
		printarray(extracted, image1.height(), image1.width());
		cout << endl;

		char name[100];
		cout << endl << "Enter a name for the Extracted image: ";
		cin >> name;
		cimage.save(name);
		system("pause");
		system("cls");
		goto start;
	}

	case 4:
	{
		system("cls");
		unsigned char * message;
		unsigned char * pwd;
		unsigned char * decrypted;
		unsigned char * encrypted;


		message = (unsigned char *)"Simple program to show how the brute force method works.";
		pwd = (unsigned char *)"good";

		RC4 A;

		encrypted = A.encrypt(message, pwd);
		decrypted = A.decrypt(encrypted, pwd);

		cout << "Message: " << message << endl;
		cout << "Message encrypted: " << encrypted << endl;
		cout << "Message decrypted: " << decrypted << endl;

		Brute_Force B;

		B.decryption_by_brute_force(encrypted);

		system("pause");
		system("cls");
		goto start;
	}

	case 5:
	{
		return 0;
	}

	}

}

