#include "Controller.h"
#include <algorithm>


vector<Bill> Controller::get_data()
{
	return this->repository.get_data();
}



bool sorting_criteria(Bill first_bill, Bill second_bill)
{
	return first_bill.get_name() < second_bill.get_name();
}
vector<Bill> Controller::get_sorted_data()
{
	vector<Bill> bills_list = this->repository.get_data();

	sort(bills_list.begin(), bills_list.end(), sorting_criteria);

	return bills_list;

}