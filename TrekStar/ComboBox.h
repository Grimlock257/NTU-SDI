#pragma once

#include "Material.h"

class ComboBox : public Material {
public:
	// Constructor & deconstructor
	ComboBox(unsigned int id, string title, string video_format, string audio_format, string run_time, string language, string retail_price, string subtitles, string frame_aspect, PackagingMaterial packaging_material);
	~ComboBox();
};