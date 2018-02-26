#pragma once

#include "City.hpp"

class Tour : public City{
	int CITIES_IN_TOUR = 20;
	int POPULATION_SIZE = 30;
	double fitness;
	City permutation[];

public:
	Tour() {};
	void shuffle_cities() {};
	double get_distance_between_cities() {};
	double get_tour_distance() {};
	int determine_fitness() {};
	void swap_cities() {};
	Tour select_parents() {};
	Tour crossover() {};
	void mutate() {};
	int contains_city() {};
};