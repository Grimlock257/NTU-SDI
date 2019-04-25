#include "VHS.h"

// Constructor & deconstructors
VHS::VHS(unsigned int id, string title, string video_format, string audio_format, string run_time, string language, string retail_price, string subtitles, string frame_aspect, string packaging_material)
	: Material(id, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material) {
}

VHS::~VHS() {
}