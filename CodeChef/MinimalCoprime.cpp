#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sieve(int max_n)
{
    vector<bool> is_prime(max_n + 1, true);
    vector<int> primes;

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= max_n; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = i * 2; j <= max_n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int count_minimal_coprime_segments(int l, int r, const vector<int> &primes)
{
    int count = 0;
    for (size_t i = 0; i < primes.size(); i++)
    {
        for (size_t j = i; j < primes.size(); j++)
        {
            int p1 = primes[i];
            int p2 = primes[j];
            if (p1 >= 1 && p2 <= r)
            {
                count++;
            }
            if (p2 > r)
                break;
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;

    // Generate all primes up to sqrt(10^9)
    vector<int> primes = sieve(sqrt(1000000000));

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        // Count minimal coprime segments
        cout << count_minimal_coprime_segments(l, r, primes) << endl;
    }

    return 0;
}