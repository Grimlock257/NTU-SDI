#include <iostream>
#include <fstream> 

#include "BluRay.h"
#include "ComboBox.h"
#include "DoubleSidedDVD.h"
#include "SingleSidedDVD.h"
#include "VHS.h"

#include "UserInput.h"
#include "Project.h"

using namespace std;

void createMaterial();

// Testing functions declarations
BluRay createBluRay();
ComboBox createCombo();
DoubleSidedDVD createDoubleDVD();
SingleSidedDVD createSingleDVD();
VHS createVHS();
void createProject();

int main() {
	// Everything in this main function is purely for testing
	BluRay myBluRay(10, "First Film", "mp4", "DTS", "2 hours, 34 minutes", "English", "£29.99", "English", "16:9", PackagingMaterial::PLASTIC, vector<string>(), vector<string>(), vector<string>());
	myBluRay.print();

	cout << "\n\n";

	// createMaterial();
	createProject();

	// Keep window open
	cin.get();
}

// All of the functions below are just for testing and will probably be moved elsewhere - also
void createMaterial() {
	// Ask user for type of material
	int choice = UserInput::get_menu_input("What type of material would you like to add?", "1) Single-Sided DVD\n2) Double-Sided DVD\n3) BluRay\n4) Combo Boxset\n5) VHS", 5);

	if (choice == 1) {
		SingleSidedDVD newSingleSidedDVD = createSingleDVD();
		newSingleSidedDVD.print();
	} else if (choice == 2) {
		DoubleSidedDVD newDoubleSidedDVD = createDoubleDVD();
		newDoubleSidedDVD.print();
	} else if (choice == 3) {
		BluRay newBluRay = createBluRay();
		newBluRay.print();
	} else if (choice == 4) {
		ComboBox newCombo = createCombo();
		newCombo.print();
	} else if (choice == 5) {
		VHS newVHS = createVHS();
		newVHS.print();
	}
}

BluRay createBluRay() {
	string title = UserInput::get_string_input("Enter title:");
	string video_format = UserInput::get_string_input("Enter Video Format:");
	string audio_format = UserInput::get_string_input("Enter Audio Format:");
	string run_time = UserInput::get_string_input("Enter Run Time:");
	string language = UserInput::get_string_input("Enter Language:");
	string retail_price = UserInput::get_string_input("Enter Retail Price:");
	string subtitles = UserInput::get_string_input("Enter Subtitles:");
	string frame_aspect = UserInput::get_string_input("Enter Frame Aspect:");
	PackagingMaterial packaging_material = PackagingMaterial::PLASTIC;

	// TOOD 1st parameter 1 will be auto generated - probably have a text file store next available ID number?
	BluRay bluRay(1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material, vector<string>(), vector<string>(), vector<string>());

	return bluRay;
}

ComboBox createCombo() {
	string title = UserInput::get_string_input("Enter title:");
	string video_format = UserInput::get_string_input("Enter Video Format:");
	string audio_format = UserInput::get_string_input("Enter Audio Format:");
	string run_time = UserInput::get_string_input("Enter Run Time:");
	string language = UserInput::get_string_input("Enter Language:");
	string retail_price = UserInput::get_string_input("Enter Retail Price:");
	string subtitles = UserInput::get_string_input("Enter Subtitles:");
	string frame_aspect = UserInput::get_string_input("Enter Frame Aspect:");
	PackagingMaterial packaging_material = PackagingMaterial::PLASTIC;

	// TOOD 1st parameter 1 will be auto generated - probably have a text file store next available ID number?
	ComboBox comboBox(1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material);

	return comboBox;
}

DoubleSidedDVD createDoubleDVD() {
	string title = UserInput::get_string_input("Enter title:");
	string video_format = UserInput::get_string_input("Enter Video Format:");
	string audio_format = UserInput::get_string_input("Enter Audio Format:");
	string run_time = UserInput::get_string_input("Enter Run Time:");
	string language = UserInput::get_string_input("Enter Language:");
	string retail_price = UserInput::get_string_input("Enter Retail Price:");
	string subtitles = UserInput::get_string_input("Enter Subtitles:");
	string frame_aspect = UserInput::get_string_input("Enter Frame Aspect:");
	PackagingMaterial packaging_material = PackagingMaterial::PLASTIC;
	string side_a_content = UserInput::get_string_input("Enter Side A Content:");
	string side_b_content = UserInput::get_string_input("Enter Side B Content:");

	// TOOD 1st parameter 1 will be auto generated - probably have a text file store next available ID number?
	DoubleSidedDVD doubleSidedDvd(1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material, vector<string>(), vector<string>(), vector<string>(), side_a_content, side_b_content);

	return doubleSidedDvd;
}

SingleSidedDVD createSingleDVD() {
	string title = UserInput::get_string_input("Enter title:");
	string video_format = UserInput::get_string_input("Enter Video Format:");
	string audio_format = UserInput::get_string_input("Enter Audio Format:");
	string run_time = UserInput::get_string_input("Enter Run Time:");
	string language = UserInput::get_string_input("Enter Language:");
	string retail_price = UserInput::get_string_input("Enter Retail Price:");
	string subtitles = UserInput::get_string_input("Enter Subtitles:");
	string frame_aspect = UserInput::get_string_input("Enter Frame Aspect:");
	PackagingMaterial packaging_material = PackagingMaterial::PLASTIC;

	// TOOD 1st parameter 1 will be auto generated - probably have a text file store next available ID number?
	SingleSidedDVD singleSidedDvd(1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material, vector<string>(), vector<string>(), vector<string>());

	return singleSidedDvd;
}

VHS createVHS() {
	string title = UserInput::get_string_input("Enter title:");
	string video_format = UserInput::get_string_input("Enter Video Format:");
	string audio_format = UserInput::get_string_input("Enter Audio Format:");
	string run_time = UserInput::get_string_input("Enter Run Time:");
	string language = UserInput::get_string_input("Enter Language:");
	string retail_price = UserInput::get_string_input("Enter Retail Price:");
	string subtitles = UserInput::get_string_input("Enter Subtitles:");
	string frame_aspect = UserInput::get_string_input("Enter Frame Aspect:");
	PackagingMaterial packaging_material = PackagingMaterial::PLASTIC;

	// TOOD 1st parameter 1 will be auto generated - probably have a text file store next available ID number?
	VHS vhs(1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material);

	return vhs;
}

void createProject() {
	ofstream outProjectFile;

	outProjectFile.open("ProjectFile.txt", ios::app);

	string projectTitle = UserInput::get_string_input("Enter project title:");
	string projectSummary = UserInput::get_string_input("Enter project summary:");;
	string projectGenre = UserInput::get_string_input("Enter project genre:");
	string projectDateRelease = UserInput::get_string_input("Enter release date:");
	string projectFilmingLoc = UserInput::get_string_input("Enter filming location:");
	string projectLanguage = UserInput::get_string_input("Enter language:");
	int projectRuntime = UserInput::get_integer_input("Enter runtime:");
	string projectKeywords = UserInput::get_string_input("Enter keyword:");
	double projectTicketSale = UserInput::get_double_input("Enter ticket sales:");
	string projectStatus = UserInput::get_string_input("Enter status:");

	// TOOD 1st parameter 1 will be auto generated - probably have a text file store next available ID number?
	Project newProject(1, projectTitle, projectSummary, projectGenre, projectDateRelease, projectFilmingLoc, projectLanguage, projectRuntime, projectKeywords, projectTicketSale, projectStatus);

	outProjectFile << newProject.get_projectTitle() << "; " << newProject.get_projectSummary() << "; " << newProject.get_projectGenre() << "; " << newProject.get_projectDateRelease() << "; " << newProject.get_projectFilmingLoc() << "; " << newProject.get_projectLanguage() << "; " << newProject.get_projectRuntime() << "; " << newProject.get_projectKeywords() << "; " << newProject.get_projectTicketSale() << "; " << newProject.get_projectStatus() << ";\n" << endl;
	cout << "The data has been stored...";

	outProjectFile.close();
	cout << "\n";
	system("PAUSE");
}
