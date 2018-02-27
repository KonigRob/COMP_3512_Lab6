#include "Tour.hpp"


void Tour::shuffle_cities(City *permutation)
{
	int index_one = 0, index_two = 0;
	for (int i = 0; i < SHUFFLES; ++i) {
		index_one = random(0.0, CITIES_IN_TOUR - 1);
		index_two = random(0.0, CITIES_IN_TOUR - 1);

		swap_cities(index_one, index_two, permutation);
	}
}

double Tour::get_distance_between_cities(City x, City y)
{
	return sqrt(pow((double)x.x_coordinate - y.x_coordinate, 2.0) +
		pow((double)x.y_coordinate - y.y_coordinate, 2.0));
}

double Tour::get_tour_distance(Tour city_list)
{
	double distance = 0.0;
	for (int i = 0; i < CITIES_IN_TOUR; ++i) {
		distance += get_distance_between_cities
		(city_list.permutation[i], city_list.permutation[(i + 1) % CITIES_IN_TOUR]);
	}
	return distance;
}

int Tour::determine_fitness(Tour *population, int population_size)
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

void Tour::swap_cities(int index_one, int index_two, City *permutation)
{
	//can we use the swap method here?  Try after.
	City* tmp = new City;
	*tmp = *(permutation + index_one);
	*(permutation + index_one) = *(permutation + index_two);
	*(permutation + index_two) = *tmp;
	delete tmp;

}

Tour* Tour::select_parents(Tour *population)
{
	Tour *parents = new Tour[NUMBER_OF_PARENTS];
	Tour *parent_pool = new Tour[PARENT_POOL_SIZE];
	int parent_index = 0;

	for (int i = 0; i < NUMBER_OF_PARENTS; ++i) {
		for (int j = 0; j < PARENT_POOL_SIZE; ++j) {
			int k = random(0.0, POPULATION_SIZE - 1);
			*(parent_pool + j) = *(population + k);
		}
		parent_index = determine_fitness(parent_pool, PARENT_POOL_SIZE);
		*(parents + i) = *(parent_pool + parent_index);
	}
	delete parent_pool;
	return parents;
}

Tour* Tour::crossover(Tour *parents)
{
	Tour *child = new Tour;
	int boundary_index = random(0.0, CITIES_IN_TOUR - 1);

	child->fitness = 0.0;

	for (int i = 0; i < boundary_index; ++i) {
		child->permutation[i] = parents->permutation[i];
	}

	while (boundary_index < CITIES_IN_TOUR) {
		for (int i = 0; i < CITIES_IN_TOUR; ++i) {
			if (!contains_city(child, boundary_index, &((parents + 1)->permutation[i]))) {
				child->permutation[boundary_index] = (parents + 1)->permutation[i];
				boundary_index++;
			}
		}
	}
	return child;
}

void Tour::mutate(Tour *population)
{
	double mutates = 0.0;
	int k = 0;
	for (int i = 0 + NUMBER_OF_ELITES; i < POPULATION_SIZE; ++i) {
		for (int j = 0; j < CITIES_IN_TOUR; ++j) {
			mutates = random(0.0, rand()) / (double)RAND_MAX;
			if (mutates <= MUTATION_RATE) {
				k = random(0.0, CITIES_IN_TOUR);
				swap_cities(j, k, (population + i)->permutation);
			}
		}
	}
}

int Tour::contains_city(Tour *candidate_tour, int length, City *candidate_city)
{
	for (int i = 0; i < length; ++i) {
		if (candidate_tour->permutation[i].name == (char)candidate_city->name &&
			candidate_tour->permutation[i].x_coordinate == (int)candidate_city->x_coordinate &&
			candidate_tour->permutation[i].y_coordinate == (int)candidate_city->y_coordinate) {
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
