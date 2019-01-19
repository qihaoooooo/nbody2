#pragma once

#include <vector>
#include "particle.h"
#include "octree.h"
#include "vtkwriter.h"

struct Config {
	// default simulation configuration
	int frames = 25;
	int n = 2048;
};

struct Simulation {

	Simulation(const Config config) {
		frames = config.frames;
		n = config.n;
	}

	void start();

private:

	// number of frames to be rendered
	int frames;
	// number of bodies
	int n;

	std::vector<Particle> ptlist;

	void update();
	void out(VTKWriter& vtkw);

	// for computation purposes 
	Region bounding_box;
	Node* tree;

};