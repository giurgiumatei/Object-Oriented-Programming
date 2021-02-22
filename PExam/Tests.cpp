#include "Tests.h"
#include <assert.h>

void test__add_star__works()
{
    Repository<Astronomer> astronomers{ "astronomers.txt" };
    Repository<Star> stars{ "stars.txt" };
    Service service(astronomers, stars);

    Star new_star("test", "test", 1, 1, 1);
    service.add_star(new_star);
    assert(new_star.getName() == "test");

}

void test__add_star___does_not_add()
{
	try
	{
        Repository<Astronomer> astronomers{ "astronomers.txt" };
        Repository<Star> stars{ "stars.txt" };
        Service service(astronomers, stars);

        Star new_star("test", "test", 1, 1, 1);
        service.add_star(new_star);
        

	}
	catch (const std::exception& exception)
	{
        assert(true);
	}
}

void test_all()
{
    test__add_star__works();
    test__add_star___does_not_add();
}
