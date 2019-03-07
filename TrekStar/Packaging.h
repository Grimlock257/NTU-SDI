#pragma once
#pragma once

#include "PackagingMaterial.h"

class Packaging {
public:
	// Constructor & deconstructor
	Packaging(PackagingMaterial packaging_material, float width, float height, float depth);
	~Packaging();

	// Methods
	void print() const;

	// Getters and setters for member attributes
	float get_width() const;
	void set_width(const float& value);

	float get_height() const;
	void set_height(const float& value);
	
	float get_depth() const;
	void set_depth(const float& value);

private:
	PackagingMaterial packaging_material;
	float width;
	float height;
	float depth;
};