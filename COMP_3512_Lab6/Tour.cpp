#include "Tour.hpp"


void Tour::shuffle_cities(City* permutation)
{
	int index_one = 0, index_two = 0;
	for (int i = 0; i < SHUFFLES; ++i) {
		index_one = rand() % CITIES_IN_TOUR;
		index_two = rand() % CITIES_IN_TOUR;

		swap_cities(index_one, index_two, permutation);
	}
}

double Tour::get_distance_between_cities(City x, City y)
{
	return sqrt(pow((double)x.getxCoord() - y.getxCoord(), 2.0) +
		pow((double)x.getxCoord() - y.getyCoord(), 2.0));
}

double Tour::get_tour_distance(Tour)
{
	return 0.0;
}

int Tour::determine_fitness(Tour* population, int population_size)
{
	int index_of_shortest_tour = 0;
	double shortest_tour_in_population = (double) RAND_MAX;
	double candidate_distance = 0.0;

	for (int i = 0; i < population_size; ++i) {
		candidate_distance = get_tour_distance(population[i]);
		population[i].fitness = FITNESS_SCALER / candidate_distance;
		if (candidate_distance <= shortest_tour_in_population) {
			index_of_shortest_tour = i;
			shortest_tour_in_population = candidate_distance;
		}
	}
	return shortest_tour_in_population;
}

void Tour::swap_cities(int index_one, int index_two, City* permutation)
{
	//can we use the swap method here?  Try after.
	City* tmp = new City;
	*tmp = *(permutation + index_one);
	*(permutation + index_one) = *(permutation + index_two);
	*(permutation + index_two) = *tmp;
	delete tmp;

}

Tour* Tour::select_parents(Tour* population)
{
	Tour* parents = new Tour[NUMBER_OF_PARENTS];
	Tour* parent_pool = new Tour[PARENT_POOL_SIZE];
	int parent_index = 0;

	for (int i = 0; i < NUMBER_OF_PARENTS; ++i) {
		for (int j = 0; j < PARENT_POOL_SIZE; ++j) {
			int k = rand() % POPULATION_SIZE;
			*(parent_pool + j) = *(population + k);
		}
		parent_index = determine_fitness(parent_pool, PARENT_POOL_SIZE);
		*(parents + i) = *(parent_pool + parent_index);
	}
	delete parent_pool;
	return parents;
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

int Tour::contains_city(Tour* candidate_tour, int length, City* candidate_city)
{
	for (int i = 0; i < length; ++i) {
		if (candidate_tour->permutation[i].getname() == (char)candidate_city->getname() &&
			candidate_tour->permutation[i].getxCoord() == (int)candidate_city->getxCoord() &&
			candidate_tour->permutation[i].getyCoord() == (int)candidate_city->getyCoord()) {
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
