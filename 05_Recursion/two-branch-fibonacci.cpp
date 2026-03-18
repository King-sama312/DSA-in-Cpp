// Recursive implementation to calculate n-th fibonacci number

int fibonacci(int n)
{
    // Base Case
    if (n <= 1)
    {
        return n;
    }
    // recursive step
    return fibonacci(n - 1) + fibonacci(n - 2);
}