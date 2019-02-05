/// by Mathew Walker
/// CS316 Homework 04
/// 12/04/2017


using namespace std;
#include <iostream>

typedef struct TreeType 
{
	int value;
	char data;
	TreeType *left;
	TreeType *right;
} *TreeType_wsk;

struct MyComparator {
    bool operator() (TreeType_wsk arg1, TreeType_wsk arg2) {
        return arg1->value > arg2->value; //calls your operator
    }
};
