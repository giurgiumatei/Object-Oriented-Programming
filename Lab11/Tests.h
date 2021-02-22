#include "Domain.h"
#include "Controller.h"
#include <assert.h>

//Redescrie testele cu True/False, foloseste getteri si rearanjeaza-le

void test_add_movie_controller__Valid_parameters_for_function__True();
void test_remove_movie_controller__String_of_a_title_present_in_the_repository__True();
void test_remove_movie_repository__String_of_a_title_absent_from_the_repository__False();
void test_remove_movie_repository__String_of_a_title_present_in_the_repository__True();

void test_remove_movie_repository_HTML__String_of_a_title_present_in_the_repository__True();

void test_remove_movie_repository_HTML__String_of_a_title_present_in_the_repository__False();

void test_remove_movie_repository__Movie_absent_from_the_repository__False();

void test_remove_movie_controller__String_of_a_title_present_in_the_repository__False();
void test_remove_movie_file_repository__String_of_a_title_present_in_the_repository__False();
void test_update_movie_controller__Valid_parameters_for_function__True();
void test_update_movie_controller__Valid_parameters_for_function__False();
void test_update_movie_file_repository__Valid_parameters_for_function__False();

void test_save_movie__Existing_movie__True();
void test_get_length_controller__Has_Four_Items_in_List__4();
void test_read_from_file__Reading_Data_from_File__Vector_not_Empty();


void test_get_data_watchlist__Try_Getting_Data_from_Watchlist__Wachlist_is_Empty();

void test_update_movie_repository__Movie_present_in_the_repository__True();

void test_get_length_repository__Has_Zero_Items_in_List__0();

void test_is_in_list_repository__Item_not_in_List__False();

void test_is_in_list_repository__Item_in_List__True();

void testAll();