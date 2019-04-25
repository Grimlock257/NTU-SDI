#pragma once

#include <vector>

#include "DVD.h"

class BluRay : public DVD {
public:
	// Constructor & deconstructor
	BluRay(unsigned int id, string title, string video_format, string audio_format, string run_time, string language, string retail_price, string subtitles, string frame_aspect, string packaging_material, vector<string> additional_languages, vector<string> additional_subtitles, vector<string> bonus_features);
	~BluRay();
};