#include <iostream>
#include <bitset>
#include <fstream>
using namespace std;
#define SIZE 7 // for 7-bit string
int main()
{
	char ch; // char to read single char
	const char *keyfile = "key.txt";
	const char *textfile = "plaintext.txt";
	//char keyarray[SIZE+1]; // To store the 7 bit-key and '\0' at the end
	string keystr; //To read the key from the file.
	ifstream fin; //To read input files.
				  // Read key file and save key in bitset
	fin.open(keyfile, ios::in); //ios::in file open for reading
	if (!fin) {
		cout << "Unable to open input file : " << keyfile << endl;
		return 1;
	}
	// read the file if opened.
	getline(fin, keystr); // read a line(key) from the file.
						  //fin.read(keyarray, SIZE); // Read 7-bit key to key array.
						  //keyarray[7] = '\0'; //Making Null for last char.
	keystr.substr(0, 7);
	//cout << "Key Read: " << keystr.substr(0, 7) << endl;
	// key bit string.
	bitset<SIZE> key(keystr.substr(0, 7)); //Sending only 7 chars to avoid any other letters after the 7bit key
										   //cout << "Bit Key: " << key << endl;
	fin.close(); // closing key.txt file.
				 // Reading the plain text file.
	fin.open(textfile, ios::in);
	if (!fin) {
		cout << "Unable to open input file : " << textfile << endl;
		return 1;
	}
	//cout << "File Contents: " << endl;
	bitset<SIZE> original_bits; // To store the character read from file.
	bitset<SIZE> permuated_bits; // To store the permuted bit char
								 // Read the file character by character and encrypt the char.
	while (!fin.eof()) { // read till we reach the end of file.
		fin >> noskipws >> ch; //noskipws = no skip white space. i.e. it will read the spaces or tabs etc.
							   //cout << ch << endl;
		bitset<SIZE> original_bits((int)ch); //Create bitset for the read char
											 //cout << "Original Bits" << original_bits << endl;
											 // Permutation - Given in question
		permuated_bits[0] = original_bits[2];
		permuated_bits[1] = original_bits[5];
		permuated_bits[2] = original_bits[6];
		permuated_bits[3] = original_bits[4];
		permuated_bits[4] = original_bits[1];
		permuated_bits[5] = original_bits[3];
		permuated_bits[6] = original_bits[0];
		// XOR and output to console the cipher
		cout << (permuated_bits ^ key) << endl;
	}
	fin.close(); // close the plaintext.txt

	system("pause");
	return 0;
}