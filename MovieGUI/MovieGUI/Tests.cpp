#include "Tests.h"



void test_add_movie_controller__Valid_parameters_for_function__True()
{
	File_Repository repository{"test.txt"};
	Repository watchlist{};
	Validator validator;
	Controller controller{ repository,&watchlist,validator };
	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;

	assert(controller.add_movie_controller(test_title, test_genre, test_year, test_likes, test_trailer) == true);


}

void test_remove_movie_controller__String_of_a_title_present_in_the_repository__True()
{
	File_Repository repository{"test.txt"};
	Repository watchlist{};
	Validator validator;
	Controller controller{ repository,&watchlist,validator };
	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;

	controller.add_movie_controller(test_title, test_genre, test_year, test_likes, test_trailer);
	assert(controller.remove_movie_controller(test_title) == true);


}

void test_remove_movie_controller__String_of_a_title_present_in_the_repository__False()
{
	File_Repository repository{ "test.txt" };
	Repository watchlist{};
	Validator validator;
	Controller controller{ repository,&watchlist,validator };
	string test_title = "test_negative", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;

	
	assert(controller.remove_movie_controller(test_title) == false);


}

void test_remove_movie_file_repository__String_of_a_title_present_in_the_repository__False()
{
	File_Repository repository{ "test.txt" };
	
	string test_title = "test_negative";

	assert(repository.remove_movie(test_title) == false);


}



void test_update_movie_controller__Valid_parameters_for_function__True()
{
	File_Repository repository{"test.txt"};
	Repository watchlist{};
	Validator validator;
	Controller controller{ repository,&watchlist,validator };
	
	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;

	controller.add_movie_controller(test_title, test_genre, test_year, test_likes, test_trailer);
	assert(controller.update_movie_controller(test_title, test_genre_replacement, test_year, test_likes, test_trailer) == true);


}

void test_update_movie_controller__Valid_parameters_for_function__False()
{
	File_Repository repository{ "test.txt" };
	Repository watchlist{};
	Validator validator;
	Controller controller{ repository,&watchlist,validator };
	string test_title = "test_negative", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;

	assert(controller.update_movie_controller(test_title, test_genre_replacement, test_year, test_likes, test_trailer) == false);

}

void test_update_movie_file_repository__Valid_parameters_for_function__False()
{
	File_Repository repository{ "test.txt" };
	
	string test_title = "test_negative", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;

	Movie new_movie = Movie(test_title, test_genre_replacement, test_year, test_likes, test_trailer);

	assert(repository.update_movie(new_movie) == false);

}



void test_save_movie__Existing_movie__True()
{

	File_Repository repository{"test.txt"};
	Repository watchlist{};
	Validator validator;
	Controller controller{ repository,&watchlist,validator };
	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;
	controller.add_movie_controller(test_title, test_genre, test_year, test_likes, test_trailer);
	assert(controller.add_movie_watchlist(test_title, test_genre, test_year, test_likes, test_trailer) == true);
}

void test_get_length_controller__Has_Four_Items_in_List__4()
{
	File_Repository repository{ "test.txt" };
	Repository watchlist{};
	Validator validator;
	Controller controller{ repository,&watchlist,validator };
	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;

	controller.add_movie_controller(test_title, test_genre, test_year, test_likes, test_trailer);
	
	assert(controller.get_length_of_data() == 4);

}

void test_read_from_file__Reading_Data_from_File__Vector_not_Empty()
{
	File_Repository repository{ "test.txt" };
	Repository watchlist{};
	Validator validator;
	Controller controller{ repository,&watchlist,validator };

	vector<Movie> movies = controller.get_data_controller();
	assert(movies.empty() == false);

}





void test_get_data_watchlist__Try_Getting_Data_from_Watchlist__Wachlist_is_Empty()
{
	File_Repository repository{ "test.txt" };
	Repository watchlist{};
	Validator validator;
	Controller controller{ repository,&watchlist,validator };

	vector<Movie> movies = controller.get_data_watchlist();
	assert(movies.empty() == true);


}



void test_remove_movie_repository__String_of_a_title_absent_from_the_repository__False()
{

	Repository repository{};

	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;
	Movie new_movie = Movie(test_title, test_genre_replacement, test_year, test_likes, test_trailer);

	repository.add_movie(new_movie);
	string test_title_negative = "negative";
	assert(repository.remove_movie(test_title_negative) == false);


}


void test_remove_movie_repository__String_of_a_title_present_in_the_repository__True()
{

	Repository repository{};

	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;
	Movie new_movie = Movie(test_title, test_genre_replacement, test_year, test_likes, test_trailer);

	repository.add_movie(new_movie);
	
	assert(repository.remove_movie(test_title) == true);


}


void test_remove_movie_repository_HTML__String_of_a_title_present_in_the_repository__True()
{

	HTML_Repository repository{ "test.html" };

	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;
	Movie new_movie = Movie(test_title, test_genre_replacement, test_year, test_likes, test_trailer);

	repository.add_movie(new_movie);

	assert(repository.remove_movie(test_title) == true);


}

void test_remove_movie_repository_HTML__String_of_a_title_present_in_the_repository__False()
{

	HTML_Repository repository{ "test.html" };

	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;
	Movie new_movie = Movie(test_title, test_genre_replacement, test_year, test_likes, test_trailer);

	

	assert(repository.remove_movie(test_title) == false);


}









void test_remove_movie_repository__Movie_absent_from_the_repository__False()
{

	Repository repository{};

	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;
	Movie new_movie = Movie(test_title, test_genre_replacement, test_year, test_likes, test_trailer);

	assert(repository.update_movie(new_movie) == false);


}



void test_update_movie_repository__Movie_present_in_the_repository__True()
{

	Repository repository{};

	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;
	Movie new_movie = Movie(test_title, test_genre_replacement, test_year, test_likes, test_trailer);

	repository.add_movie(new_movie);

	assert(repository.update_movie(new_movie) == true);


}

void test_get_length_repository__Has_Zero_Items_in_List__0()
{
	
	Repository repository{};
	

	

	assert(repository.get_lenght_repository() == 0);

}


void test_is_in_list_repository__Item_not_in_List__False()
{
	Repository repository{};


	string title = "test_title";

	assert(repository.is_in_list_repository(title) == false);

}


void test_is_in_list_repository__Item_in_List__True()
{
	Repository repository{};

	string test_title = "test", test_genre = "test", test_trailer = "test", test_genre_replacement = "test2";
	unsigned int test_likes = 420, test_year = 420;
	Movie new_movie = Movie(test_title, test_genre_replacement, test_year, test_likes, test_trailer);

	repository.add_movie(new_movie);

	assert(repository.is_in_list_repository(test_title) == true);

}








void testAll()
{
	test_add_movie_controller__Valid_parameters_for_function__True();
	test_remove_movie_controller__String_of_a_title_present_in_the_repository__True();
	test_remove_movie_controller__String_of_a_title_present_in_the_repository__False();
	test_remove_movie_file_repository__String_of_a_title_present_in_the_repository__False();
	test_update_movie_controller__Valid_parameters_for_function__True();
	test_update_movie_controller__Valid_parameters_for_function__False();
	test_update_movie_file_repository__Valid_parameters_for_function__False();
	test_save_movie__Existing_movie__True();
	//test_get_length_controller__Has_Four_Items_in_List__4();
	test_read_from_file__Reading_Data_from_File__Vector_not_Empty();
	test_get_data_watchlist__Try_Getting_Data_from_Watchlist__Wachlist_is_Empty();
	test_remove_movie_repository__String_of_a_title_absent_from_the_repository__False();
	test_remove_movie_repository__String_of_a_title_present_in_the_repository__True();
	test_remove_movie_repository__Movie_absent_from_the_repository__False();
	test_update_movie_repository__Movie_present_in_the_repository__True();
	test_is_in_list_repository__Item_not_in_List__False();
	test_is_in_list_repository__Item_in_List__True();
	//test_get_length_repository__Has_Zero_Items_in_List__0();
	test_remove_movie_repository_HTML__String_of_a_title_present_in_the_repository__True();
	test_remove_movie_repository_HTML__String_of_a_title_present_in_the_repository__False();
}
