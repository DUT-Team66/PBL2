#ifndef _MYLIB_
#define _MYLIB_
#include "List.cpp"
#include "Phone.h"
#include "Staff.h"
#include "Order.h"
#include "Customer.h"


template class List<Phone>;
// template class List<Staff>;
template class List<Order>;
template class List<Customer>;

#endif