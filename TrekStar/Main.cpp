#include <iostream>
#include <fstream> 

#include "BluRay.h"
#include "ComboBox.h"
#include "DoubleSidedDVD.h"
#include "SingleSidedDVD.h"
#include "VHS.h"

#include "UserInput.h"
#include "Project.h"
#include "Crew.h"
#include "ProjectLinkedList.h"
#include "MaterialLinkedList.h"

#define PRINT(x) cout << x << endl

using namespace std;

// Testing functions declarations
BluRay* createBluRay();
ComboBox* createCombo();
DoubleSidedDVD* createDoubleDVD();
SingleSidedDVD* createSingleDVD();
VHS* createVHS();
void mainMenu();
Material* createMaterial();
Project createProject();
void createCrew();
void removeProject();

// ProjectList constructor called when creating this variable which calls the read_file() method and loads of saved projects into program memory
ProjectList list;
MaterialList Mlist; 

int main() {
	mainMenu();

	// Keep window open
	cin.get();
}

void mainMenu() {
	while (true) {
		// Ask the user what they want to do
		int choice = UserInput::get_menu_input("What would you like to do?", "1) Create new project\n2) Create new material for a project\n3) Edit projects\n4) Edit materials\n5) Add crew information for a project\n6) Search projects\n7) Delete project\n8) Quit", 8);

		switch (choice) {
		case 1:
		{
			Project project;
			project = createProject();
			list.add_node(project);

			if (project.get_status() == "Released") {
				int choice = UserInput::get_menu_input("Do you want to add a material for this project?", "1) Yes\n2) No", 2);

				if (choice == 1) {
					// TODO: Get this material from this function
				
					Material* material;
					material = createMaterial();
					Mlist.add_node(&material);
				}
			}
		}
		break;
		case 2:
		{
			//Material material;
			//material = createMaterial();
			//Mlist.add_node(material);
		}
			
			break;
		case 3:
			PRINT("Edit Projects Coming Soon!");
		case 4:
			PRINT("Edit Materials Coming Soon!");
			break;
		case 5:
			PRINT("Add Crew Information Coming Soon!");
			break;
		case 6:
			PRINT("Project Searching Coming Soon!");
			break;
		case 7:
		{
			list.print_project_list();
			string deleteProject = UserInput::get_string_input("What project do you want to delete?");

			try {
				list.delete_node(deleteProject);
			}
			catch (const invalid_argument& e) {
				cout << e.what() << endl;
			}

			list.print_project_list();
		}
		break;
		case 8:
			PRINT("Saving data...");
			list.write_file();
			Mlist.write_file();
			PRINT("Data saved!");
			PRINT("Thank you for using TrekStar Project Management!");
			return;
		default:
			PRINT("Something went wrong... please try again!");
		}
	}
}

void remove_project() {

}

// All of the functions below are just for testing and will probably be moved elsewhere - also
Material* createMaterial() {
	// Ask user for type of material
	int choice = UserInput::get_menu_input("What type of material would you like to add?", "1) Single-Sided DVD\n2) Double-Sided DVD\n3) BluRay\n4) Combo Boxset\n5) VHS", 5);

	if (choice == 1) {
		return createSingleDVD();
		//new_single_sided_dvd.print();
	}
	else if (choice == 2) {
		return createDoubleDVD();
		//new_double_sided_dvd.print();
	}
	else if (choice == 3) {
		return createBluRay();
		//new_blu_ray.print();
	}
	else if (choice == 4) {
		return createCombo();
		//new_combo.print();
	}
	else if (choice == 5) {
		return createVHS();
		//new_vhs.print();
	}

}

BluRay* createBluRay() {
	string title = UserInput::get_string_input("Enter title:");
	string video_format = UserInput::get_string_input("Enter Video Format:");
	string audio_format = UserInput::get_string_input("Enter Audio Format:");
	string run_time = UserInput::get_string_input("Enter Run Time:");
	string language = UserInput::get_string_input("Enter Language:");
	string retail_price = UserInput::get_string_input("Enter Retail Price:");
	string subtitles = UserInput::get_string_input("Enter Subtitles:");
	string frame_aspect = UserInput::get_string_input("Enter Frame Aspect:");
	string packaging_material = UserInput::get_string_input("Enter Packaging Material (PLASTIC or CARDBOARD):");
	vector<string> additional_languages = UserInput::get_vector_input("Enter Additional Languages:");
	vector<string> additional_subtitles = UserInput::get_vector_input("Enter Additional Subtitles:");
	vector<string> bonus_features = UserInput::get_vector_input("Enter Bonus Features:");

	// TOOD 1st parameter 1 will be auto generated - probably have a text file store next available ID number?
	return new BluRay(1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material, additional_languages, additional_subtitles, bonus_features);
}

ComboBox* createCombo() {
	string title = UserInput::get_string_input("Enter title:");
	string video_format = UserInput::get_string_input("Enter Video Format:");
	string audio_format = UserInput::get_string_input("Enter Audio Format:");
	string run_time = UserInput::get_string_input("Enter Run Time:");
	string language = UserInput::get_string_input("Enter Language:");
	string retail_price = UserInput::get_string_input("Enter Retail Price:");
	string subtitles = UserInput::get_string_input("Enter Subtitles:");
	string frame_aspect = UserInput::get_string_input("Enter Frame Aspect:");
	string packaging_material = UserInput::get_string_input("Enter Packaging Material (PLASTIC or CARDBOARD):");

	// TOOD 1st parameter 1 will be auto generated - probably have a text file store next available ID number?
	return new ComboBox(1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material);
}

DoubleSidedDVD* createDoubleDVD() {
	string title = UserInput::get_string_input("Enter title:");
	string video_format = UserInput::get_string_input("Enter Video Format:");
	string audio_format = UserInput::get_string_input("Enter Audio Format:");
	string run_time = UserInput::get_string_input("Enter Run Time:");
	string language = UserInput::get_string_input("Enter Language:");
	string retail_price = UserInput::get_string_input("Enter Retail Price:");
	string subtitles = UserInput::get_string_input("Enter Subtitles:");
	string frame_aspect = UserInput::get_string_input("Enter Frame Aspect:");
	string packaging_material = UserInput::get_string_input("Enter Packaging Material (PLASTIC or CARDBOARD):");
	vector<string> additional_languages = UserInput::get_vector_input("Enter Additional Languages:");
	vector<string> additional_subtitles = UserInput::get_vector_input("Enter Additional Subtitles:");
	vector<string> bonus_features = UserInput::get_vector_input("Enter Bonus Features:");
	string side_a_content = UserInput::get_string_input("Enter Side A Content:");
	string side_b_content = UserInput::get_string_input("Enter Side B Content:");

	// TOOD 1st parameter 1 will be auto generated - probably have a text file store next available ID number?
	return new DoubleSidedDVD(1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material, additional_languages, additional_subtitles, bonus_features, side_a_content, side_b_content);
}

SingleSidedDVD* createSingleDVD() {
	string title = UserInput::get_string_input("Enter title:");
	string video_format = UserInput::get_string_input("Enter Video Format:");
	string audio_format = UserInput::get_string_input("Enter Audio Format:");
	string run_time = UserInput::get_string_input("Enter Run Time:");
	string language = UserInput::get_string_input("Enter Language:");
	string retail_price = UserInput::get_string_input("Enter Retail Price:");
	string subtitles = UserInput::get_string_input("Enter Subtitles:");
	string frame_aspect = UserInput::get_string_input("Enter Frame Aspect:");
	string packaging_material = UserInput::get_string_input("Enter Packaging Material (PLASTIC or CARDBOARD):");
	vector<string> additional_languages = UserInput::get_vector_input("Enter Additional Languages:");
	vector<string> additional_subtitles = UserInput::get_vector_input("Enter Additional Subtitles:");
	vector<string> bonus_features = UserInput::get_vector_input("Enter Bonus Features:");

	// TOOD 1st parameter 1 will be auto generated - probably have a text file store next available ID number?
	return new SingleSidedDVD(1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material, additional_languages, additional_subtitles, bonus_features);
}

VHS* createVHS() {
	string title = UserInput::get_string_input("Enter title:");
	string video_format = UserInput::get_string_input("Enter Video Format:");
	string audio_format = UserInput::get_string_input("Enter Audio Format:");
	string run_time = UserInput::get_string_input("Enter Run Time:");
	string language = UserInput::get_string_input("Enter Language:");
	string retail_price = UserInput::get_string_input("Enter Retail Price:");
	string subtitles = UserInput::get_string_input("Enter Subtitles:");
	string frame_aspect = UserInput::get_string_input("Enter Frame Aspect:");
	string packaging_material = UserInput::get_string_input("Enter Packaging Material (PLASTIC or CARDBOARD):");

	// TOOD 1st parameter 1 will be auto generated - probably have a text file store next available ID number?
	return new VHS(1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material);
}

/*
void createProject() {
	ofstream outProjectFile;
	outProjectFile.open("ProjectFile.txt", ios::app);
	string title = UserInput::get_string_input("Enter project title:");
	string summary = UserInput::get_string_input("Enter project summary:");;
	string genre = UserInput::get_string_input("Enter project genre:");
	string date_release = UserInput::get_string_input("Enter release date:");
	string filming_loc = UserInput::get_string_input("Enter filming location:");
	string language = UserInput::get_string_input("Enter language:");
	int runtime = UserInput::get_integer_input("Enter runtime:");
	string keywords = UserInput::get_string_input("Enter keyword:");
	double ticket_sale = UserInput::get_double_input("Enter ticket sales:");
	string status = UserInput::get_string_input("Enter status:");
	// TOOD 1st parameter 1 will be auto generated - probably have a text file store next available ID number?
	Project newProject(1, title, summary, genre, date_release, filming_loc, language, runtime, keywords, ticket_sale, status);
	if (status == "RELEASED") {
		createMaterial();
	}
	outProjectFile << newProject.get_title() << "; " << newProject.get_summary() << "; " << newProject.get_genre() << "; " << newProject.get_date_release() << "; " << newProject.get_filming_loc() << "; " << newProject.get_language() << "; " << newProject.get_runtime() << "; " << newProject.get_keywords() << "; " << newProject.get_ticket_sale() << "; " << newProject.get_status() << ";\n" << endl;
	cout << "The data has been stored...";
	outProjectFile.close();
	cout << "\n";
	system("PAUSE");
}
*/

Project createProject() {
	string projectTitle = UserInput::get_string_input("Enter title:");
	string projectSummary = UserInput::get_string_input("Enter summary:");
	string projectGenre = UserInput::get_string_input("Enter genre:");
	string projectDateRelease = UserInput::get_string_input("Enter release date:");
	string projectFilmingLoc = UserInput::get_string_input("Enter filming location:");
	string projectLanguage = UserInput::get_string_input("Enter language:");
	int projectRuntime = UserInput::get_integer_input("Enter runtime:");
	string projectKeywords = UserInput::get_string_input("Enter keyword:");
	double projectTicketSale = UserInput::get_double_input("Enter ticket sales:");
	string projectStatus = UserInput::get_string_input("Enter status (Unreleased / Now Playing / Released) :");

	// TOOD 1st parameter 1 will be auto generated - probably have a text file store next available ID number?
	return Project(1, projectTitle, projectSummary, projectGenre, projectDateRelease, projectFilmingLoc, projectLanguage, projectRuntime, projectKeywords, projectTicketSale, projectStatus);
}

void createCrew() {
	ofstream outCrewFile;
	outCrewFile.open("crewFile.txt", ios::app);

	string producer = UserInput::get_string_input("Enter Producer's name:");
	string director = UserInput::get_string_input("Enter Director's name:");
	string writer = UserInput::get_string_input("Enter Writer's name:");
	string editor = UserInput::get_string_input("Enter Editor's name:");
	string prodDesign = UserInput::get_string_input("Enter Production Designer's name:");
	string setDeco = UserInput::get_string_input("Enter Set Decorator's name:");
	string customeDesign = UserInput::get_string_input("Enter Costume Designer's name:");
	int numCast = UserInput::get_integer_input("Enter number of Actors and Actresses in Film:");

	string *cast = new string[numCast];

	// TOOD 1st parameter 1 will be auto generated - probably have a text file store next available ID number?
	Crew crew(1, producer, director, writer, numCast, editor, prodDesign, setDeco, customeDesign);

	for (int i = 0; i < numCast; i++) {
		cout << "Enter Actor's or Actress's name:";
		cin >> cast[i];
	}

	outCrewFile << crew.get_producer() << ";" << crew.get_director() << ";" << crew.get_writer() << ";" << crew.get_editor() << ";" << crew.get_prodDesign() << ";" << crew.get_setDeco() << ";" << crew.get_costumeDesign() << ";";
	for (int i = 0; i < numCast; i++) {
		outCrewFile << cast[i] << ";";
		if (i > numCast) {
			outCrewFile << endl;
		}
	}
	cout << "The data has been stored";
	cout << "\n";
	outCrewFile.close();

	system("PAUSE");
}