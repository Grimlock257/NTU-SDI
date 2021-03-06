#pragma once

#include <string>
#include <vector>

/* Functions relating to gathering user input from the command line*/
namespace UserInput {
	/**
	 * Get a menu input from the user
	 *
	 * @param question - The question to pose to the user
	 * @param options - The available options to the user in the form of a string
	 * @param amountOptions - The amount of available options to the user (used to determine whether the inputted option is valid)
	 *
	 * @return The option the user chose
	 */
	int get_menu_input(std::string question, std::string options, short int amountOptions);

	/**
	 * Get an integer input from the user
	 *
	 * @param question - The question to pose to the user
	 * @param displayInline - Whether to have the question and the user input on the same line (default is true)
	 *
	 * @return The integer the user entered
	 */
	int get_integer_input(std::string question, bool displayInline = true);

	/**
	 * Get a double input from the user
	 *
	 * @param question - The question to pose to the user
	 * @param displayInline - Whether to have the question and the user input on the same line (default is true)
	 * @param allowNegative - Whether to allow negative numbers to be selected (default is true)
	 *
	 * @return The double the user entered
	 */
	double get_double_input(std::string question, bool displayInline = true, bool allowNegative = true);

	/**
	 * Get a string input from the user
	 *
	 * @param question - The question to pose to the user
	 * @param displayInline - Whether to have the question and the user input on the same line (default is true)
	 *
	 * @return The string the user entered
	 */
	std::string get_string_input(std::string question, bool displayInline = true);

	/**
	* Get a vector input from the user
	*
	* @param question - The question to pose to the user
	*/
	std::vector<std::string> get_vector_input(std::string question);
}