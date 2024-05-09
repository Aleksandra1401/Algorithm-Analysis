#include <iostream>
#include <vector>
using namespace std;

/* FIBONACCI SEQUENCE
 *
 * Fibonacci sequence is a mathematical sequence of numbers, where each term
 * is calculated as the sum of the two preceding terms.
 *
 * The algorithms in this file compute the nth term of Fibonacci sequence.
 * There are multiple ways to derive a nth term of Fibonacci sequence, and
 * here we analyze their efficiency.
 *
 * The approaches we analyze are:
 * 1. Recursive
 * 2. Utilizing data structures to store data and minimize the number of
 *    calculations.
 *
 * Even though recursive algorithm for deriving the nth term of the Fibo-
 * nacci sequence may look like quick and straightforward solution, the
 * cost of recursion clearly increases for large terms, demonstrating
 * inefficiency in applications as the values are computed over and over
 * again. The table below shows almost double increase in terms computed
 * every time n is increased by 2.
 *
 *        | n | Number of terms computed |
 *        | 0 |            1             |
 *		  | 1 |            1             |
 *        | 2 |            3             |
 *        | 3 |            5             |
 *        | 4 |            9             |
 *        | 5 |            15            |
 *        | 6 |            25            |
 *
 * If T(n) denotes the number of terms in the recursion tree for n, we can
 * say that the number of terms more than doubles each time n increases by 2.
 * Therefore, we have following for even n:
 *
 * T(n) > 2 x T(n-2)
 *      > 2 x 2 x T(n-4)
 *      > 2 x 2 x 2 x T(n-6)
 *      .
 *      .
 *      .
 *      > 2 x 2 x 2 x ... x 2 x T(0)
 *
 * T(0) = 1, which yields T(n) = 2^(n/2)
 * Induction can be used to show that this is also true for n>=2 even in cases
 * when n is odd. The inequality does not hold for n=1 because T(1) = 1, which
 * is less than 2^(1/2).
 * 
 * NOTE: The program uses n > 0 for terms of Fibonacci sequence.
 * TODO: Review induction in section A.3 in Appendix A.
 * 
 */


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
		cout << "Enter an integer greater than 0: ";


		while (!(cin >> (*num))) {

			cout << "Error: Please enter an integer: ";
			// clear and discard previous input 
			cin.clear();
			cin.ignore(123, '\n');

		}
		// check validity of integer
		if ((*num) <= 0) {
			cout << "Error: Integer should be greater then 0." << endl;
		}
		else {
			input_valid = true;
		}

	}//while

}
/* Recursive fibonacci algorithm.
 *
 * @param num: pointer to the integer denoting n
 * @param terms_computed: pointer to the integer to hold
 * the number of computed terms so far
 *
 * @return fib: nth term of Fibonacci sequence.
 */
int recursive_fib(int* num, int* terms_computed) {

	int fib;

	// recursive fibonacci algorithm
	// if 1 or 2 return 1
	if (*num == 1 || *num == 2) {
		fib = 1;
		(*terms_computed)++;
	} 
	// n > 2
	else {
		int num1 = (*num) - 1;
		int num2 = num1 - 1;
		(*terms_computed) = (*terms_computed) + 1;
		fib = recursive_fib(&num1, terms_computed) + recursive_fib(&num2, terms_computed);
	}


	return fib;
}
/* Efficient way to calculate nth term of Fibonacci sequence. Uses vector to
 * hold values for terms, decreasing the number of calculations.
 *
 */
int efficient_fibonacci(int* num, int* terms_computed) {

	// initialize vector to hold values for terms
	vector<int> vec;
	

	if (*num > 0) {
		// assign values for 1st and 2nd term
		vec.push_back(1);
		(*terms_computed)++;
		if (*num > 1) {
			vec.push_back(1);
			(*terms_computed)++;
		}
		// calculate terms for n>2
		for (int i = 2; i < *num; i++) {
			int result = vec.at(i - 1) + vec.at(i - 2);
			vec.push_back(result);
			(*terms_computed)++;
		}

	}

	return vec.back();
}


/* Main method.
 *
 */
int main() {

	int num;
	int terms = 0;
	// take valid input
	take_input(&num);
	cout << endl;

	//recursive fibonacci
	cout << "RECURSIVE FIBONACCI" << endl;
	cout << num << ". term is " << recursive_fib(&num, &terms) << endl;
	cout << "Number of terms computed: " << terms << endl;
	cout << endl;


	// efficient fibonacci
	terms = 0;
	cout << "VECTOR FIBONACCI" << endl;
	cout << num << ". term is " << efficient_fibonacci(&num, &terms) << endl;
	cout << "Number of terms computed: " << terms << endl;
	cout << endl;


	return 0;

}