
#include <stdio.h>
#include <math.h> // only for log calculation for error comparison

float calculatePartialSum(int, int);

void main()
{
    unsigned int n = 1e7; // number of terms
    // unsigned int n = 4294967295; // maximum number of terms

    int quarter = n / 4;
    int halfway = n / 2;
    int three_fourths = 3 * n / 4;

    float processor_1 = 0.0;
    float processor_2 = 0.0;
    float processor_3 = 0.0;
    float processor_4 = 0.0;

    float half_sum_1 = 0.0;
    float half_sum_2 = 0.0;

    processor_1 = calculatePartialSum(1, quarter);             // from 2 to quarter - 1
    processor_2 = calculatePartialSum(quarter, halfway);       // from quarter to halfway - 1
    processor_3 = calculatePartialSum(halfway, three_fourths); // from halfway to three_fourths - 1
    processor_4 = calculatePartialSum(three_fourths, n + 1);   // from three_fourths to n

    half_sum_1 = processor_1 + processor_2;
    half_sum_2 = processor_3 + processor_4;

    float sum = half_sum_1 + half_sum_2;

    printf("\n");
    printf("------------------------------------------------------\n");
    printf("\n");
    printf("Ln2 approximation with %d terms: %.10f\n", n, sum);
    printf("\n");
    printf("------------------------------------------------------\n");
    printf("\n");
    printf("Ln2 approximation using C built-in log function: %.10f\n", log(2));
    printf("\n");
}

float calculatePartialSum(int lower_limit, int upper_limit)
{
    // assuming the first element of any part (lower_limit) is even => negative
    // int sign = -1;
    float partial_sum = 0.0;

    for (int n = lower_limit; n < upper_limit; n++)
    {
        float term = (float)(1 / (float)n) * pow(-1.0, n - 1);
        partial_sum = (float)partial_sum + term;
    }

    return partial_sum;
}