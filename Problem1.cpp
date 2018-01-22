/* If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.*/

#include <iostream>

using namespace std;

int sumOfMultiples_constanttime(int upper_bound)
{
    /* sum1 = 3 + 6 + 9 + ... = 3 x (1 + 2 + 3 + ...)
       sum2 = 5 + 10 + 15 + ... = 5 x (1 + 2 + 3 + ...)
       sum3 = 15 + 30 + 45 + ... = 15 x (1 + 2 + 3 + ...)
       sum(1,2,3,4,...,n) = n x (n+1) / 2
    */
    
    int n1 = upper_bound / 3;
    if(upper_bound % 3 == 0)    n1--;
    int sum1 = n1 * (n1 + 1) / 2;
    
    int n2 = upper_bound / 5;
    if(upper_bound % 5 == 0)    n2--;
    int sum2 = n2 * (n2 + 1) / 2;
    
    int n3 = upper_bound / 15;
    if(upper_bound % 15 == 0)   n3--;
    int sum3 = n3 * (n3 + 1) / 2;
    
    return 3*sum1 + 5*sum2 - 15*sum3;
}

int sumOfMultiples_lineartime(int upper_bound)
{
    int running_sum = 0;
    for(int i=1; i<upper_bound; i++)
    {
        if( i % 3 == 0 || i % 5 == 0 )
        {
            running_sum += i;
        }
    }
    return running_sum;
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cout << "Enter upper bound value." << endl;
        return -1;
    }
    
    int sum_of_multiples_lt = sumOfMultiples_lineartime(atoi(argv[1]));
    int sum_of_multiples_ct = sumOfMultiples_constanttime(atoi(argv[1]));
    
    cout << sum_of_multiples_lt << endl;
    cout << sum_of_multiples_ct << endl;

    return 0;
}
