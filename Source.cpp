// Make all choices into functions
// Learn how to search in a text files
// Figure out how to make classes for text files
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void main_Menu();

int main() {
	int input = 0;
	
	while (input != 6) {
		main_Menu();
		std::cin >> input;
		// Add A Record
		if (input == 1) {
			std::ofstream records("records.txt", std::ios::app);
			std::cout << "Write the name of the Record you are adding.\n";
			std::string add_One;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(std::cin, add_One);
			//figure out how to add to next line in text
			records << add_One << "\n";
			records.close();
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
