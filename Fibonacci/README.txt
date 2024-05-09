                          FIBONACCI SEQUENCE

Fibonacci sequence is a mathematical sequence of numbers, where each term
is calculated as the sum of the two preceding terms.

The algorithms in this file compute the nth term of Fibonacci sequence.
There are multiple ways to derive a nth term of Fibonacci sequence, and
here we analyze their efficiency.

The approaches we analyze are:
1. Recursive
2. Utilizing data structures to store data and minimize the number of
    calculations.

Even though recursive algorithm for deriving the nth term of the Fibo-
nacci sequence may look like quick and straightforward solution, the
cost of recursion clearly increases for large terms, demonstrating
inefficiency in applications as the values are computed over and over
again. The table below shows almost double increase in terms computed
every time n is increased by 2.

        | n | Number of terms computed |
        | 0 |            1             |
  		  | 1 |            1             |
        | 2 |            3             |
        | 3 |            5             |
        | 4 |            9             |
        | 5 |            15            |
        | 6 |            25            |

If T(n) denotes the number of terms in the recursion tree for n, we can
say that the number of terms more than doubles each time n increases by 2.
Therefore, we have following for even n:

 T(n) > 2 x T(n-2)
      > 2 x 2 x T(n-4)
      > 2 x 2 x 2 x T(n-6)
      .
      .
      .
      > 2 x 2 x 2 x ... x 2 x T(0)

T(0) = 1, which yields T(n) = 2^(n/2)
Induction can be used to show that this is also true for n>=2 even in cases
when n is odd. The inequality does not hold for n=1 because T(1) = 1, which
is less than 2^(1/2).

NOTE: The program uses n > 0 for terms of Fibonacci sequence.
TODO: Review induction in section A.3 in Appendix A.
 
 
