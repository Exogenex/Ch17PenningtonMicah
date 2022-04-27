// Micah Pennington
// April 26 2022 ©
// Chapter 17 Program

#include <string>
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main() {
	/* In case file needs to be specified by user
	string fileName = "";

	fstream file;

	do {
		if (file.fail()) { cout << "Error opening file\nPlese re-enter file name and try again"; }

		cout << "Please enter file name: ";
		getline(cin, fileName);
	} while (file.fail());*/

	// Open file
	fstream file = fstream("forChap12.txt", ios::in);

	// Make string to hold file
	string fileString;
	set<string> words;

	// Copy file to string and remove all punctuation
	while (!file.eof()) {
		char c = file.get();
		// If needs to not be case-sensitive
		//c = tolower(c);
		switch (c) {
		case '\n': fileString += ' ';
		case '.': continue;
		case ',': continue;
		case '\"': continue;
		case '?': continue;
		default: fileString += c;
		}
	}

	// Find words in fileString and add them to words set
	string word = "";
	for (auto c : fileString) {
		if (c == ' ')
		{
			words.insert(word);
			word = "";
		}
		else { word += c; }
	}

	// Display words
	for (auto w : words) { cout << w << '\n'; }
	cout << "\nThere are: " << words.size() << " unique words in this file.";


	file.close();
	return EXIT_SUCCESS;
}