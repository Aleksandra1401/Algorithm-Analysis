#include <iostream>
#include <vector>
#include <random>
using namespace std;


/* BINARY SEARCH
 * 
 * Binary Search is a search algorithm that falls in the cathegory of 
 * Divide and Conquer algorithms. Divide and Conquer algorithms are
 * algorithms that use the top-down approach to solve a problem. 
 * This means that the problem is divided into multiple subproblems
 * and the solution for the problem is obtained by solving for 
 * subproblems.
 * 
 * Binary Search searches for the item n within some sorted array
 * (usually in ascending order) by dividing the array in the middle
 * and comparing n to the middle element. Then, few things are 
 * considered:
 * 
 * 1. If n and the middle element are equal - the search is done. 
 * 2. If not, then the array is divided into two subarrays, one 
 *    containing all the items less than the middle and the other
 *    containing items greater than middle element. The search 
 *    continues depending on is the middle element greater or less 
 *    than n. If  greater, we know that the n must be in the first 
 *    half of the array. If less, n is in the second half. 
 * 3. The appropriate half of the array is used for search to be 
 *    further performed until the element is found. If array can
 *    not be further divided - the element is not in the array.
 * 
 * Here I implemented the recursive version of algorithm because this
 * version illustrates the top-down approach used by divide-and-conquer.
 * 
 * Binary Search is the simplest kind of divide and conquer algorithms
 * because the problem is broken down into only one subproblem and 
 * there is no combination of outputs.
 * 
 */


class RandomNumberBetween
{
public:
	RandomNumberBetween(int low, int high)
		: random_engine_{ std::random_device{}() }
		, distribution_{ low, high }
	{
	}
	int operator()()
	{
		return distribution_(random_engine_);
	}
private:
	std::mt19937 random_engine_;
	std::uniform_int_distribution<int> distribution_;
};


/* Prompt user for integer input. Validate input.
 * 
 * @param 
 */
void get_int_input(int* integer, string* text) {

	bool input_valid = false;
	// Take and validate input
	while (!input_valid) {
		// Ask user for integer input
		//cout << "Please enter the size of array: ";
		cout << *text;

		while (!(cin >> (*integer))) {

			cout << "Error: Please enter an integer: ";
			// clear and discard previous input 
			cin.clear();
			cin.ignore(123, '\n');

		}
		// check validity of integer
		if ((*integer) <= 0) {
			cout << "Error: Integer should be greater then 0." << endl;
		}
		else {
			input_valid = true;
		}

	}//while
}
/* Initilize an array of random ints
 *
 * @param size: size of the array
 * @param max: upper bound for array elements
 */
void initialize_vector(int* size, int* max) {

	// initialize vector to hold values for terms
	vector<int> vec(*size, 0);

	generate(begin(vec), end(vec), RandomNumberBetween(1, *max));

	for (int number : vec)
	{
		std::cout << number << ' ';
	}




}
void get_max_num(int* max_num) {

}
/* Calls methods to take and validate user input.
 *
 * @param size: int* to hold a size of desired array
 * @param max_num: int* to hold an int representing 
 *                 max value in the array
 */
void take_input(int* size, int* max_num) {

	// get size
	string text = "Please enter the size of array: ";
	get_int_input(size, &text);
	// get max value of array elements
	text = "Please enter upper bound for array elements: ";
	get_int_input(max_num, &text);
	// initialize vector
	initialize_vector(size, max_num);
}



int main() {



	int size;
	int max_num;
	// prompt user for input for size of the 
	// array 
	take_input(&size, &max_num);

	cout << "Input is " << size << endl;



	//initialize_vector();

	//random_device random_device;
	//mt19937 random_engine(random_device());
	//uniform_int_distribution<int> distribution_1_100(1, 100);

	//auto const randomNumber = distribution_1_100(random_engine);

	//cout << randomNumber << '\n';

	
	

	return 0;
}