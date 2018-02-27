#include "Tour.hpp"

int main()
{
	int i = 0, j = 0, iterations = 0;
	int index_of_shortest_tour = 0;
	double best_distance = 0.0;
	double best_iteration_distance = 0.0;
	double improvement_factor = 0.3;

	Tour  *population, *parents, *crosses, *temp_tour, *child;
	City *cities_to_visit;

	population = new Tour[2];
	crosses = new Tour[2];
	
	return 0;
}