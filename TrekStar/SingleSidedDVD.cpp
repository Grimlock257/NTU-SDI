#include "SingleSidedDVD.h"

// Constructor & deconstructors
SingleSidedDVD::SingleSidedDVD(unsigned int id, unsigned int project_id, string title, string video_format, string audio_format, string run_time, string language, string retail_price, string subtitles, string frame_aspect, string packaging_material, vector<string> additional_languages, vector<string> additional_subtitles, vector<string> bonus_features)
	: DVD(id, project_id, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material, additional_languages, additional_subtitles, bonus_features) {
}

SingleSidedDVD::~SingleSidedDVD() {
}

// Methods
void SingleSidedDVD::print() const {
	cout << "Material Details\n";
	cout << "Title: " << title << "\n";
	cout << "Video Format: " << video_format << "\n";
	cout << "Audio Format: " << audio_format << "\n";
	cout << "Run Time: " << run_time << "\n";
	cout << "Default Language: " << language << "\n";
	cout << "Retail Price: " << retail_price << "\n";
	cout << "Default Subtitles: " << subtitles << "\n";
	cout << "Aspect Ratio: " << frame_aspect << "\n";
	cout << "Packaging Material: " << packaging_material << "\n";
	cout << "Additional Languages: " << additional_languages << "\n";
	cout << "Additional Subtitles: " << additional_subtitles << "\n";
	cout << "Bonus Features: " << bonus_features << "\n";
}

string SingleSidedDVD::get_savable() {
	string s = ";";
	return "SINGLESIDEDDVD;" + to_string(get_id()) + ";" + get_title() + ";" + get_video_format() + ";" + get_audio_format() + ";" + get_run_time() + ";" + get_language() + ";" + get_retail_price() + ";" + get_subtitles() + ";" + get_frame_aspect() + ";" + get_packaging_material() + ";" + vector_to_string(get_additional_languages()) + ";" + vector_to_string(get_additional_subtitles()) + ";" + vector_to_string(get_bonus_features()) + ";\n";;
}