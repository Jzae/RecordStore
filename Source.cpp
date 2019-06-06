// Make all choices into functions
// Learn how to search in a text files
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void main_Menu();
int add_Record(std::string new_Record);
int all_Records(std::string found);

class albums {
public:
	std::string title;
	std::string artist;
	int year;
};

int main() {
	std::ifstream records("records.txt", std::ios::in);
	std::string buffer;
	int input = 0;
	while (!records.eof()) {
		getline(records, buffer);
		all_Records(buffer);
	}


	
	while (input != 6) {
		main_Menu();
		std::cin >> input;
		// Add A Record
		if (input == 1) {
			std::cout << "Write the name of the Record you are adding.\n";
			std::string add_One;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(std::cin, add_One);
			add_Record(add_One);
		}
		// Show All Records
		else if (input == 2) {
			std::string line;
			std::ifstream records("records.txt");
			while (getline(records, line))
			{
				std::cout << line << '\n';
			}
			records.close();
			std::cout << "------------------------------" << std::endl;
		}
		// Search Records
		else if (input == 3) {

		}
		//Modify A Record
		else if (input == 4) {

		}
		// Delete A Record
		else if (input == 5) {

		}
		//Exit
		else if (input == 6) {
			std::cout << "Goodbye!\n";
		}
		//Bad Input
		else {
			std::cout << "Not found!\n";
		}
	}
	
	system("PAUSE");
}

void main_Menu() {
	std::cout << "1. Add A Record\n";
	std::cout << "2. Show All Records\n";
	std::cout << "3. Search Records\n";
	std::cout << "4. Modify A Record\n";
	std::cout << "5. Delete A Record\n";
	std::cout << "6. Exit\n";
}

int add_Record(std::string new_Record) {
	std::ofstream records("all records/records.txt", std::ios::app);
	records << new_Record << "\n";
	records.close();
	return 0;
}

int all_Records(std::string found) {
	std::string title;
	std::string artist;
	std::string year;
	int place = 0;
	// Put records in class
	std::ifstream records("records.txt", std::ios::in);
	for (int i = 0; i < int(found.size()); i++) {
		if (found[i] == ',') {
			place = i + 1;
			break;
		}
		title += found[i];
	}
	for (int i = place; i < int(found.size()); i++) {
		if (found[i] == ',') {
			place = i + 1;
			break;
		}
		artist += found[i];
	}
	for (int i = place; i < int(found.size()); i++) {
		year += found[i];
	}
	
	std::cout << title << std::endl;
	std::cout << artist << std::endl;
	std::cout << year << std::endl;
	return 0;
}
