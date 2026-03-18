// Recursive implementation of n! (n-factorial)
int factorial(int n)
{
    // Base case
    if (n <= 1)
    {
        return 1;
    }

    // Recursive step
    return n * factorial(n - 1);
}