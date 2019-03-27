#include "UserInput.h"

using namespace std;

namespace UserInput {
	/**
	 * Get a menu input from the user
	 *
	 * @param question - The question to pose to the user
	 * @param options - The available options to the user in the form of a string
	 * @param amountOptions - The amount of available optoins to the user (used to determine whether the inputted option is valid)
	 *
	 * @return The option the user chose
	 */
	int get_menu_input(string question, string options, short int amountOptions) {
		cout << question << endl << options << endl;

		string userInput;
		short int choice;

		while (true) {
			cout << "> ";
			getline(cin, userInput);

			stringstream ss(userInput);
			if (ss >> choice && (choice > 0 && choice <= amountOptions)) {
				break;
			}

			cout << "Invalid choice, please enter a valid option (1 - " << amountOptions << ")" << endl;
		}

		return choice;
	}

	/**
	 * Get an integer input from the user
	 *
	 * @param question - The question to pose to the user
	 * @param displayInline - Whether to have the question and the user input on the same line (default is false)
	 *
	 * @return The integer the user entered
	 */
	int get_integer_input(string question, bool displayInline) {
		cout << question << " ";

		string userInput;
		short int choice;

		while (true) {
			if (!displayInline)
				cout << endl << "> ";

			getline(cin, userInput);

			stringstream ss(userInput);
			if (ss >> choice) {
				break;
			}

			cout << "Invalid choice, please enter a valid integer: ";
		}

		return choice;
	}

	/**
	 * Get a double input from the user
	 *
	 * @param question - The question to pose to the user
	 * @param displayInline - Whether to have the question and the user input on the same line (default is false)
	 * @param allowNegative - Whether to allow negative numbers to be selected (default is true)
	 *
	 * @return The double the user entered
	 */
	double get_double_input(string question, bool displayInline, bool allowNegative) {
		cout << question << " ";

		string userInput;
		double choice;

		while (true) {
			if (!displayInline)
				cout << endl << "> ";

			getline(cin, userInput);

			stringstream ss(userInput);
			if (allowNegative) {
				if (ss >> choice) {
					break;
				}
			} else {
				if (ss >> choice && choice >= 0) {
					break;
				}
			}

			cout << "Invalid choice, please enter a valid decimal number: ";
		}

		return choice;
	}

	/**
	 * Get a string input from the user
	 *
	 * @param question - The question to pose to the user
	 * @param displayInline - Whether to have the question and the user input on the same line (default is false)
	 *
	 * @return The string the user entered
	 */
	string get_string_input(string question, bool displayInline) {
		cout << question << " ";

		if (!displayInline)
			cout << endl << "> ";

		string userInput;
		getline(cin, userInput);

		return userInput;
	}
}