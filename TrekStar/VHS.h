#pragma once

#include "Material.h"

class VHS : public Material {
public:
	// Constructor & deconstructor
	VHS(unsigned int id, unsigned int project_id, string title, string video_format, string audio_format, string run_time, string language, string retail_price, string subtitles, string frame_aspect, string packaging_material);
	~VHS();

	// Methods
	virtual void print() const;
	virtual string get_savable();
};