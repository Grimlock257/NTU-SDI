#pragma once

#include <iostream>
#include <string>
#include <sstream>

/* Functions relating to gathering user input from the command line*/
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
	int get_menu_input(std::string question, std::string options, short int amountOptions);

	/**
	 * Get an integer input from the user
	 *
	 * @param question - The question to pose to the user
	 *
	 * @return The integer the user entered
	 */
	int get_integer_input(std::string question);

	/**
	 * Get a double input from the user
	 *
	 * @param question - The question to pose to the user
	 * @param allowNegative - Whether to allow negative numbers to be selected (default is true)
	 *
	 * @return The double the user entered
	 */
	double get_double_input(std::string question, bool allowNegative = true);

	/**
	 * Get a string input from the user
	 *
	 * @param question - The questoin to pose to the user
	 *
	 * @return The string the user entered
	 */
	std::string get_string_input(std::string question);
}