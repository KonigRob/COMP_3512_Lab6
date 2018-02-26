#include "Tour.hpp"


void Tour::shuffle_cities(City)
{

}

double Tour::get_distance_between_cities(City, City)
{
	return 0.0;
}

double Tour::get_tour_distance(Tour)
{
	return 0.0;
}

int Tour::determine_fitness(Tour, int)
{
	return 0;
}

void Tour::swap_cities(int, int, City)
{
}

Tour Tour::select_parents(Tour)
{
	return Tour();
}

Tour Tour::crossover(Tour)
{
	return Tour();
}

void Tour::mutate(Tour population)
{
	double mutates = 0.0;
	for (int i = 0 + NUMBER_OF_ELITES; i < POPULATION_SIZE; ++i) {
		for (int j = 0; j < CITIES_IN_TOUR; ++j) {
			
		}
	}

}

int Tour::contains_city(Tour* candidate_tour, int length, City candidate_city)
{
	for (int i = 0; i < length; ++i) {
		if (candidate_tour->permutation[i].getname() == (char)candidate_city.getname() &&
			candidate_tour->permutation[i].getxCoord() == (int)candidate_city.getxCoord() &&
			candidate_tour->permutation[i].getyCoord() == (int)candidate_city.getyCoord()) {
			return 1;
		}
	}
	return 0;
}

double Tour::random(double x, double y)
{
		std::default_random_engine a(time(0));
		std::uniform_real_distribution<double> b(x, y);
		return b(a);

}
