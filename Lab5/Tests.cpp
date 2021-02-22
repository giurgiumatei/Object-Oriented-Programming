#include "Tests.h"

void test_add__Valid_data_for_dynamic_vector__Lenght_equals_1()
{

	DynamicVector<Movie> test_movies;
	string test_title = "test", test_genre = "test", test_trailer = "test";
	unsigned int test_likes = 420, test_year = 420;
	Movie test_movie = Movie(test_trailer, test_genre, test_year, test_likes, test_trailer);

	test_movies.add(test_movie);

	assert(test_movies.get_lenght() == 1);

}

void test_remove__String_of_a_title_present_in_the_vector__Lenght_equals_0()
{

	DynamicVector<Movie> test_movies;
	string test_title = "test", test_genre = "test", test_trailer = "test";
	unsigned int test_likes = 420, test_year = 420;
	Movie test_movie = Movie(test_trailer, test_genre, test_year, test_likes, test_trailer);

	test_movies.add(test_movie);
	test_movies.remove("test");

	assert(test_movies.get_lenght() == 0);

}

void test_update__Valid_data_for_dynamic_vector__True()
{

	DynamicVector<Movie> test_movies;
	string test_title = "test", test_genre = "test", test_trailer = "test",test_genre_replacement="test2";
	unsigned int test_likes = 420, test_year = 420;
	Movie test_movie = Movie(test_trailer, test_genre, test_year, test_likes, test_trailer);
	Movie test_movie__replacement = Movie(test_trailer, test_genre_replacement, test_year, test_likes, test_trailer);

	test_movies.add(test_movie);

	assert(test_movies.update(test_movie__replacement) == true);

}

void test_add_movie_controller__Valid_parameters_for_function__True()
{
	Repository repository{};
	Repository watchlist{};
	Controller controller{ repository,watchlist };
	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;

	assert(controller.add_movie_controller(test_title, test_genre, test_year, test_likes, test_trailer)==true);


}

void test_remove_movie_controller__String_of_a_title_present_in_the_repository__True()
{
	Repository repository{};
	Repository watchlist{};
	Controller controller{ repository,watchlist };
	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;

	controller.add_movie_controller(test_title, test_genre, test_year, test_likes, test_trailer);
	assert(controller.remove_movie_controller(test_title) == true);


}

void test_update_movie_controller__Valid_parameters_for_function__True()
{
	Repository repository{};
	Repository watchlist{};
	Controller controller{ repository,watchlist };
	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;

	controller.add_movie_controller(test_title, test_genre, test_year, test_likes, test_trailer);
	assert(controller.update_movie_controller(test_title, test_genre_replacement, test_year, test_likes, test_trailer) == true);


}

void test_save_movie__Existing_movie__True()
{

	Repository repository{};
	Repository watchlist{};
	Controller controller{ repository,watchlist };
	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;
	controller.add_movie_controller(test_title, test_genre, test_year, test_likes, test_trailer);
	assert(controller.add_movie_watchlist(test_title, test_genre, test_year, test_likes, test_trailer) == true);
}
