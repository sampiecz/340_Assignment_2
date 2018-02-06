/***********************************************************
 CSCI 340 - Assignment 2 - Spring 2018
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 1
 TA: 
 Date Due: February 5, 2018
 
 Purpose: Implement linear search and binary search on random
 integers stored within vectors.
 ************************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using std::setw;
using std::cout;
using std::endl;
using std::vector;
using std::srand;
using std::rand;
using std::sort;

const int DATA_SIZE = 100;
const int SEARCH_SIZE = 50;
const int DATA_SEED = 11;
const int SEARCH_SEED = 7;

/***************************************************************
 genRndNums

 Use: This function generates random numbers using the srand()
 and rand() functions.

 Parameters: A reference to a vector v and an integer seed. 

 Returns: None 
 ***************************************************************/
void genRndNums( vector<int>& v, int seed ) 
{
    // calls srand with the seed value seed
    srand(seed);

    // generates random integers by calling rand()
    int randomIntegers = rand();

}

/***************************************************************
 linearSearch

 Use: Performs a slow linear search across a vector. Also uses
 the find method, which is slow.

 Parameters: A reference to a constant vector called inputVec.
 Plus an integer named x.

 Returns: Either true or false.  

 ***************************************************************/
bool linearSearch( const vector<int>& inputVec, int x) 
{
    vector<int>::const_iterator it;
	it = find (inputVec.begin(), inputVec.end(), x);

	if (it != inputVec.end())
    {
		return true;
    }
	else
	{
		return false;
	}
}

/***************************************************************
 binarySearch

 Use: Implement the binary search algorithm using STL algorithm
 binary_search().

 Parameters: A reference to a vector of type integer called
 called inputVec. Plus an integer called x. 

 Returns: A bool.  

 ***************************************************************/
bool binarySearch( const vector<int>& inputVec, int x) 
{
    if(binary_search (inputVec.begin(), inputVec.end(), x))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/***************************************************************
 search

 Use:  

 Parameters: Two references to a constant vector of type integer
 named inputVec and searchVec. A pointer to a function called p
 that takes a reference to a constant vector of type integer.

 Returns: An integer. 

 ***************************************************************/
int search( const vector<int>& inputVec, const vector<int>& searchVec,
            bool (*p)( const vector<int>&, int) )
{
}

/***************************************************************
 sortVector

 Use: Sorts a vector in ascending order. 

 Parameters: Takes a reference to a vector of type integer 
 name inputVec.

 Returns: None. 

 ***************************************************************/
void sortVector (vector<int>& inputVec) 
{
    sort(inputVec.begin(), inputVec.end());
}

/***************************************************************
 printStat

 Use: Prints the percent of successful searches as floating 
 point numbers.

 Parameters: An int called totalSucCnt, and an int called
 vec_size.

 Returns: None. 

 ***************************************************************/
void printStat (int totalSucCnt, int vec_size) 
{
}

/***************************************************************
 print_vec

 Use: Prints the contents of vector. 

 Parameters: A reference to a constant vector of type int called
 vec.

 Returns: None. 

 ***************************************************************/
void print_vec( const vector<int>& vec )
{
    const int ITEM_W = 6;
    const int NO_ITEMS = 10;
    vector<int>::const_iterator it;
    for (it = vec.begin(); it != vec.end(); it++)
    {
        cout << setw(ITEM_W) << *it;
        if ((it - vec.begin()) % NO_ITEMS == 7)
        { 
            cout << endl;
        }
    }

}

int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
    cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    sortVector( inputVec );

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    return 0;
}

