#include "BluRay.h"

// Constructor & deconstructor
BluRay::BluRay(unsigned int id, string title, string video_format, string audio_format, string run_time, string language, string retail_price, string subtitles, string frame_aspect, string packaging_material, vector<string> additional_languages, vector<string> additional_subtitles, vector<string> bonus_features)
	: DVD(id, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material, additional_languages, additional_subtitles, bonus_features) {
}

BluRay::~BluRay() {
}