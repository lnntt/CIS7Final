#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

// Function Declarations used in program
string VignereCipher (string plaintext, string keyword);
string VignereDecipher (string cipheredText, string keyword);
void DIMInterface(int option);
void DIMRepeatInterface();
void DIMOption1();
void DIMOption2();
void DIMOption3();

//Main function
int main () {

	//variable used for menu navigation
	int number ;

	cout << "Initializing Program..."
			<< "\n Welcome Agent 00 to VCipher. My name is D.I.M. "
			<< "\n short for Deciphering Intelligence Machina "
			<< "\n What can I assist you with today? ";
	cout << "\n Choose from the following by entering the "
			<< "corresponding number \n (1) Cipher Message \n (2) "
			<< "Decipher Message \n (3) Send "
			<< "Ciphered Message  \n (4) Nothing \n" ;

	cin >> number;
	DIMInterface(number) ;

	return 0;
}

void DIMInterface(int option)
{
	if (option == 1)
	{
		DIMOption1() ;		// Cipher
	}
	if (option == 2)
	{
		DIMOption2() ;		// Decipher
	}

	if (option == 3)
	{
		DIMOption3() ;		// Send
	}

	if (option == 4)
	{
		cout << "\n ..........." << "\n ..........." << "\n ..........."
				<< "\n So ... you booted me up for nothing ??"
				<< "\n Disdainfully terminating program..." ;
	}
}

/* VignereCipher
 * String function to perform Vignere Cipher
 * 	- accepts 2 strings as parameters one for the keyword
 * 		both given by user
 * 	- returns ciphered text
 */

string VignereCipher (string plaintext, string keyword )
{
	string cipheredText;
	char convert;
	unsigned int makeKey = plaintext.size() ;

	// repeats key until it reaches length of plain text
	for (unsigned int i = 0 ; ; i++)
	{
		if (makeKey == i)
			i = 0;
		if (keyword.size() == plaintext.size())
			break;
		keyword.push_back(keyword[i]) ;
	}

	// ciphers each letter of plain text using keyword
	for (unsigned int i = 0; i < plaintext.size(); i++)
	{
		convert = (plaintext[i] + keyword[i]) %26;
		convert += 'A' ;

		cipheredText.push_back(convert) ;
	}

	return cipheredText ;
}

/* DIMOption1
 * 	Cipher text option
 * 	Ask user for plain text and keyword then
 * 	calls on VignereCipher
 * 	Outputs ciphered text
 */

void DIMOption1() {
	string message;		// plain text
	string passcode;	// key
	string optional;	// hold for ciphered text

	char answer;

	cout << "\n Please enter your message: " ;
	cin >> message ;

	cout << "Please enter your chosen keyword: " << endl ;
	cin >> passcode ;

	cout << "\n Original Message: " << message ;
	cout << "\n Key: " << passcode ;
	cout << "\n Ciphered Message: \n" ;
	optional = VignereCipher(message, passcode);
	cout << optional;
	cout << "\n Would you like me to send this message? (Enter Y or N) ";
	cin >> answer ;
	if (answer == 'Y' || answer == 'y')
	{
		DIMOption3() ;
	}
	else
	DIMRepeatInterface() ;	// continue to menu
}

/* DIMOption2
 * 	Decipher option
 * 	Asks user for ciphered text and key
 * 	then calls on VigenereDecipher
 * 	Outputs the deciphered, plain text
 */

void DIMOption2() {
	string cipheredText;
	string keyword;

	cout << "\n Enter the Ciphered Text: ";
	cin >> cipheredText ;

	cout << "\n Enter the Keyword: " ;
	cin >> keyword ;

	cout << "\n Deciphered Message: " ;
	cout << VignereDecipher(cipheredText,keyword);

	DIMRepeatInterface() ;	// continue to menu
}

/* VignereDecipher
 * String Function to perform decipher
 * 	-accept 2 strings as parameters; one for the keyword and
 * 		the other for the ciphered text, both inputed by user
 * 	-returns ciphered text
 */

string VignereDecipher (string cipheredText, string keyword)
{
	string decipheredText;
	char convert;
	unsigned int makeKey = cipheredText.size();

	// Repeat key until it reaches length of ciphered text
	for (unsigned int i = 0 ; ; i++)
	{
			if (makeKey == i)
				i = 0;
			if (keyword.size() == cipheredText.size())
				break;
			keyword.push_back(keyword[i]) ;
	}

	// deciphers each letter of ciphered text string
	for (unsigned int i = 0; i < cipheredText.size(); i++)
	{
		convert = (cipheredText[i] - keyword[i] + 26) %26;
		convert += 'A' ;
		decipheredText.push_back(convert) ;
	}

	return decipheredText;
}

/*
 * DIMOption3
 * 	Option to send your coded message
 * 	For fun
 */

void DIMOption3()
{
	string destination;

	cout << "\n Please enter your destination: " ;
	cin >> destination ;
	cout << "\n Processing Request..." ;

	cout << "\n Your message has been sent to " ;
	cout << destination << "." << endl ;

	DIMRepeatInterface() ;
}

/*
 * DIMRepeatInterface
 * 	Is called on by each of the other functions after completing
 * 	their respective tasks
 * 	Asks the user where they want to navigate in the menu or if
 * 	they want to terminate the program
 * 	Then calls on DIMInterface to select the option
 */

void DIMRepeatInterface()
{
	int number ;
	char answer;
	cout << "\n Is there anything else I can assist you with? "
				<<	"\n (Enter Y or N)" ;
		cin >> answer ;

	if (answer == 'N' || answer == 'n')
		{
			cout << "\n Good luck on your mission Agent 00. "
					<<	"\n Terminating Program..." ;
		}
	if (answer == 'Y' || answer == 'y')
	{
	cout << "\n What else can I assist you with today Agent 00? ";
	cout << "Choose from the following by entering the corresponding"
			<< " number \n (1) Cipher Message \n (2) Decipher"
			<< " Message \n (3) Send Ciphered "
			<< " Message \n (4) Nothing " ;
	cin >> number;
	DIMInterface(number);
	}
}
