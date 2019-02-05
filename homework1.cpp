/* Claudia Rodriguez
HW 1: read and decrypt lines from a text file

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//function decrypts character
char decrypt(char letter, int rotations) {
	//restores it to original character
	letter = (letter - 'a' - rotations + 26) % 26 + 'a';
	return letter;
}

//function changes string
void decryptString(string& line, int rotations) {
	for (int index = 0; index < line.size(); index++) {
		//pases lowercase characters to decrypt
		if (islower(line[index])) {
			char new_letter = decrypt(line[index], rotations);
			//overwrites old character
			line[index] = new_letter;
		}
	}
}

//function prints vector in reverse
void printReverse(const vector <string>& finaloutput) {
	for (int index = finaloutput.size(); index>0; --index) {
		cout << finaloutput[index - 1] << endl;
	}
}

int main() {
	ifstream encry("encrypted.txt");
	if (!encry) {
		cerr << "Could not open the file\n";
		exit(1);
	}
	//collects the number of rotations
	int rotation;
	encry >> rotation;
	vector<string> vLines;
	string line;
	//skipping over the first
	getline(encry, line);
	//adding lines into vector
	while (getline(encry, line)){
		cout << line << endl;
		vLines.push_back(line);
	}
	for (string& line : vLines) {
		decryptString(line,rotation);
	}
	printReverse(vLines);
	encry.close();
}*/