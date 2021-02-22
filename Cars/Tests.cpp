#include "Tests.h"
#include <assert.h>
void test_filter_true()
{
	Repository repository("C:\\Users\\giurg\\OneDrive\\Facultate\\OOP\\Cars\\Cars\\test.txt");
	Controller controller(repository);

	assert(controller.get_number_of_cars_filtered_by_name("Fiat")==1);

}

void test_filter_false()
{
	Repository repository("C:\\Users\\giurg\\OneDrive\\Facultate\\OOP\\Cars\\Cars\\test.txt");
	Controller controller(repository);

	assert(controller.get_number_of_cars_filtered_by_name("Mercedez-Benz") != 1);
}

void test_all()
{
	test_filter_true();
	test_filter_false();
}
