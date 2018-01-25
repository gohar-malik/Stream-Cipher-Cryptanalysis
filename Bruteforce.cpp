#include "Bruteforce.h"

Brute_Force::Brute_Force()
{

}

void Brute_Force::setkeylength()
{
	cout << "Enter the key length" << endl;
	cin >> keylength;
}

void Brute_Force::setplaintext()
{
	plaintext = new unsigned char[1000];
	cout << "Enter the plain text known to you" << endl;
	cin >> plaintext;
}

void Brute_Force::setciphertext(unsigned char *encrypted)
{

	ciphertext = encrypted;
}


bool Brute_Force::findword(unsigned char *str, unsigned char *word)
{
	for (int i = 0; i < strlen((char*)str); i++)
	{
	try_again:
		if (str[i] == word[0])
		{
			for (int j = 0; j < strlen((char*)word); j++)
			{
				if (str[i + j] != word[j])
				{
					i++;
					goto try_again;
				}

			}
			return true;
		}
	}
	return false;
}


void Brute_Force::decryption_by_brute_force(unsigned char *encrypted)
{
	setkeylength();
	setciphertext(encrypted);
	setplaintext();

	hack = new unsigned char[keylength + 1];
	//setting this hack array to one greater than keylength because
	//the last character will be \0

	temp = new unsigned char[strlen((char*)ciphertext)];

	hack[keylength] = '\0';

	//selecting how to proceed by using switch case

	system("cls");

	switch (keylength)
	{
	case 1:

		for (int a = 0; a < ASCII_CONSIDERED; a++)
		{
			hack[0] = a + CASE;
			cout << hack << "\t";

			temp = decrypt(ciphertext, hack);

			m = findword(temp, plaintext);

			if (m)
			{
				goto exit;
			}

		}
		break;

	case 2:

		for (int a = 0; a < ASCII_CONSIDERED; a++)
		{
			hack[0] = a + CASE;

			for (int b = 0; b < ASCII_CONSIDERED; b++)
			{
				hack[1] = b + CASE;
				cout << hack << "\t";

				temp = decrypt(ciphertext, hack);

				m = findword(temp, plaintext);

				if (m)
				{
					goto exit;
				}
			}
		}
		break;

	case 3:

		for (int a = 0; a < ASCII_CONSIDERED; a++)
		{
			hack[0] = a + CASE;

			for (int b = 0; b < ASCII_CONSIDERED; b++)
			{
				hack[1] = b + CASE;

				for (int c = 0; c < ASCII_CONSIDERED; c++)
				{
					hack[2] = c + CASE;

					cout << hack << "\t";

					temp = decrypt(ciphertext, hack);

					m = findword(temp, plaintext);

					if (m)
					{
						goto exit;
					}

				}
			}
		}
		break;

	case 4:

		for (int a = 0; a < ASCII_CONSIDERED; a++)
		{
			hack[0] = a + CASE;

			for (int b = 0; b < ASCII_CONSIDERED; b++)
			{
				hack[1] = b + CASE;

				for (int c = 0; c < ASCII_CONSIDERED; c++)
				{
					hack[2] = c + CASE;

					for (int d = 0; d < ASCII_CONSIDERED; d++)

					{
						hack[3] = d + CASE;

						cout << hack << "\t";

						temp = decrypt(ciphertext, hack);

						m = findword(temp, plaintext);

						if (m)
						{
							goto exit;
						}
					}
				}
			}
		}
		break;

	case 5:

		for (int a = 0; a < ASCII_CONSIDERED; a++)
		{
			hack[0] = a + CASE;

			for (int b = 0; b < ASCII_CONSIDERED; b++)
			{
				hack[1] = b + CASE;

				for (int c = 0; c < ASCII_CONSIDERED; c++)
				{
					hack[2] = c + CASE;

					for (int d = 0; d < ASCII_CONSIDERED; d++)

					{
						hack[3] = d + CASE;

						for (int e = 0; e < ASCII_CONSIDERED; e++)
						{
							hack[4] = e + CASE;

							cout << hack << "\t";

							temp = decrypt(ciphertext, hack);

							m = findword(temp, plaintext);

							if (m)
							{
								goto exit;
							}

						}
					}
				}
			}
		}
		break;

	case 6:

		for (int a = 0; a < ASCII_CONSIDERED; a++)
		{
			hack[0] = a + CASE;

			for (int b = 0; b < ASCII_CONSIDERED; b++)
			{
				hack[1] = b + CASE;

				for (int c = 0; c < ASCII_CONSIDERED; c++)
				{
					hack[2] = c + CASE;

					for (int d = 0; d < ASCII_CONSIDERED; d++)

					{
						hack[3] = d + CASE;

						for (int e = 0; e < ASCII_CONSIDERED; e++)
						{
							hack[4] = e + CASE;

							for (int f = 0; f < ASCII_CONSIDERED; f++)
							{
								hack[5] = f + CASE;

								cout << hack << "\t";

								temp = decrypt(ciphertext, hack);

								m = true;

								m = findword(temp, plaintext);

								if (m)
								{
									goto exit;
								}

							}
						}
					}
				}
			}
		}
		break;

	case 7:

		for (int a = 0; a < ASCII_CONSIDERED; a++)
		{
			hack[0] = a + CASE;

			for (int b = 0; b < ASCII_CONSIDERED; b++)
			{
				hack[1] = b + CASE;

				for (int c = 0; c < ASCII_CONSIDERED; c++)
				{
					hack[2] = c + CASE;

					for (int d = 0; d < ASCII_CONSIDERED; d++)

					{
						hack[3] = d + CASE;

						for (int e = 0; e < ASCII_CONSIDERED; e++)
						{
							hack[4] = e + CASE;

							for (int f = 0; f < ASCII_CONSIDERED; f++)
							{
								hack[5] = f + CASE;

								for (int g = 0; g < ASCII_CONSIDERED; g++)
								{
									hack[6] = g + CASE;
									cout << hack << "\t";

									temp = decrypt(ciphertext, hack);

									m = findword(temp, plaintext);

									if (m)
									{
										goto exit;
									}

								}
							}
						}
					}
				}
			}
		}
		break;
	case 8:

		for (int a = 0; a < ASCII_CONSIDERED; a++)
		{
			hack[0] = a + CASE;

			for (int b = 0; b < ASCII_CONSIDERED; b++)
			{
				hack[1] = b + CASE;

				for (int c = 0; c < ASCII_CONSIDERED; c++)
				{
					hack[2] = c + CASE;

					for (int d = 0; d < ASCII_CONSIDERED; d++)

					{
						hack[3] = d + CASE;

						for (int e = 0; e < ASCII_CONSIDERED; e++)
						{
							hack[4] = e + CASE;

							for (int f = 0; f < ASCII_CONSIDERED; f++)
							{
								hack[5] = f + CASE;

								for (int g = 0; g < ASCII_CONSIDERED; g++)
								{
									hack[6] = g + CASE;

									for (int h = 0; h < ASCII_CONSIDERED; h++)
									{
										hack[7] = h + CASE;

										cout << hack << "\t";

										temp = decrypt(ciphertext, hack);

										m = findword(temp, plaintext);

										if (m)
										{
											goto exit;
										}


									}
								}
							}
						}
					}
				}
			}
		}
		break;

	case 9:

		for (int a = 0; a < ASCII_CONSIDERED; a++)
		{
			hack[0] = a + CASE;

			for (int b = 0; b < ASCII_CONSIDERED; b++)
			{
				hack[1] = b + CASE;

				for (int c = 0; c < ASCII_CONSIDERED; c++)
				{
					hack[2] = c + CASE;

					for (int d = 0; d < ASCII_CONSIDERED; d++)

					{
						hack[3] = d + CASE;

						for (int e = 0; e < ASCII_CONSIDERED; e++)
						{
							hack[4] = e + CASE;

							for (int f = 0; f < ASCII_CONSIDERED; f++)
							{
								hack[5] = f + CASE;

								for (int g = 0; g < ASCII_CONSIDERED; g++)
								{
									hack[6] = g + CASE;

									for (int h = 0; h < ASCII_CONSIDERED; h++)
									{
										hack[7] = h + CASE;

										for (int i = 0; i < ASCII_CONSIDERED; i++)
										{
											hack[8] = i + CASE;
											cout << hack << "\t";

											temp = decrypt(ciphertext, hack);

											m = findword(temp, plaintext);

											if (m)
											{
												goto exit;
											}

										}
									}
								}
							}
						}
					}
				}
			}
		}
		break;

	case 10:

		for (int a = 0; a < ASCII_CONSIDERED; a++)
		{
			hack[0] = a + CASE;

			for (int b = 0; b < ASCII_CONSIDERED; b++)
			{
				hack[1] = b + CASE;

				for (int c = 0; c < ASCII_CONSIDERED; c++)
				{
					hack[2] = c + CASE;

					for (int d = 0; d < ASCII_CONSIDERED; d++)

					{
						hack[3] = d + CASE;

						for (int e = 0; e < ASCII_CONSIDERED; e++)
						{
							hack[4] = e + CASE;

							for (int f = 0; f < ASCII_CONSIDERED; f++)
							{
								hack[5] = f + CASE;

								for (int g = 0; g < ASCII_CONSIDERED; g++)
								{
									hack[6] = g + CASE;

									for (int h = 0; h < ASCII_CONSIDERED; h++)
									{
										hack[7] = h + CASE;

										for (int i = 0; i < ASCII_CONSIDERED; i++)
										{
											hack[8] = i + CASE;
											for (int j = 0; j < ASCII_CONSIDERED; j++)
											{
												hack[9] = j + CASE;

												cout << hack << "\t";

												temp = decrypt(ciphertext, hack);

												m = findword(temp, plaintext);

												if (m)
												{
													goto exit;
												}
											}

										}
									}
								}
							}
						}
					}
				}
			}
		}
		break;
	}

	cout << endl << "BRUTE FORCE ATTACK FAILED" << endl;

exit:
	system("cls");
	cout << endl << endl << "The secret message is " << temp << " coded under the key " << hack << endl;


}