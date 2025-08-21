#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

string convert(int n, int k)
{
    string result;
    int r = n;
    while (n > 0)
    {
        r = n % k;
        n = n / k;
        result += (r + '0');
    }
    return result;
}

vector<string> split(string input, char sep)
{
    vector<string> result;
    
    int len = input.size();
    string token;
    for (int i = 0; i < len; i++)
    {
        if (input[i] == sep)
        {
            if (token.size() > 0)
            {
                result.push_back(token);
            }
            token = string();
        }
        else
        {
            token += input[i];
        }
    }
    if (token.size() > 0)
    {
        result.push_back(token);
    }
    return result;
}

long long convert_to_number(string input, long long n)
{
    long long result = 0;
    long long pow = 1;
    for (const char& c : input)
    {
        result += (c - '0') * pow;
        pow *= n;
    }
    return result;
}

bool is_prime(long long number)
{
    if (number <= 1) return false;
    long long rt = sqrt(number) + 1;
    for (long long i=2; i < rt; i++) 
    {
        if (number % i == 0) 
        {
            cout << "is_not_prime: " << number << ", " << i << endl;
            return false;
        }
    }
    cout << "is_prime: " << number << endl;
    return true;
}


int solution(int n, int k)
{
    string k_number = convert(n, k);
    cout << "k_number: " << k_number << endl;
    
    vector<string> tokens = split(k_number, '0');
    
    int answer = 0;
    for (string& token : tokens)
    {
        long long number = convert_to_number(token, 10);
        if (is_prime(number))
        {
            answer += 1;
        }
    }
    return answer;
}


