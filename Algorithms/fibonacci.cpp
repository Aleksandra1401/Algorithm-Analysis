#include <iostream>
#include <vector>
using namespace std;

/*
 * Prompts user for input. Validates input: user must enter an integer
 * greater than or equal to 0.
 * 
 * @param num: pointer to an integer variable to store input
 */
void take_input(int* num) {

	bool input_valid = false;
	// Take and validate input
	while (!input_valid) {
		// Ask user for integer input
		cout << "Enter an integer greater than or equal to 0: ";


		while (!(cin >> (*num))) {

			cout << "Error: Please enter an integer: ";
			// clear and discard previous input 
			cin.clear();
			cin.ignore(123, '\n');

		}
		// check validity of integer
		if ((*num) < 0) {
			cout << "Error: Integer should be 0 or greater." << endl;
		}
		else {
			input_valid = true;
		}

	}//while

}
/* Recursive fibonacci algorithm.
 * 
 * @param num: pointer to the integer denoting n
 * @return fib: nth term of Fibonacci sequence.
 */
int recursive_fib(int* num) {

	int fib;
	// recursive fibonacci algorithm
	// if 0 or 1 just return the value of num
	if (*num == 0 || *num == 1) {
		fib = *num;
	}
	// n >= 2
	else {
		int num1 = (*num)-1;
		int num2 = num1-1;
		fib = recursive_fib(&num1) + recursive_fib(&num2);
	}
	return fib;
}
/* Efficient way to calculate nth term of Fibonacci sequence. Uses vector to 
 * hold values for terms, decreasing the number of calculations.
 * 
 */
int efficient_fibonacci(int* num) {

	// initialize vector to hold values for terms
	vector<int> vec;
	// assign values for 1st and 2nd term
	vec.push_back(0);

	if (*num > 0) {

		vec.push_back(1);
		//
		for (int i = 2; i <= *num; i++) {
			int result = vec.at(i - 1) + vec.at(i - 2);
			vec.push_back(result);
		}

	}

	return vec.back();
}


/* Main method.
 *  
 */
int main() {

	int num;

	// take valid input
	take_input(&num);
	cout << endl;

	//recursive fibonacci
	cout << "RECURSIVE FIBONACCI" << endl;
	cout << num << ". term is " << recursive_fib(&num) << endl;

	cout << endl;
	cout << "VECTOR FIBONACCI" << endl;
	// efficient fibonacci
	cout<< num << ". term is " << efficient_fibonacci(&num) << endl;


	return 0;

}