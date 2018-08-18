#include <iostream>

using namespace std;

int FactorsPairs = 0;
int small = 1;
int big = 0;

void CheckFactors(int number)
{
    big = number + 1;
    small = 1;

    for(int i = 0; i < (number * number) +  1; i++)
    {
        if(small * big == number)
        {
            FactorsPairs += 1;
            big -= 1;
        }else
        {
            big -= 1;
        }

        if(big == 0)
        {
            big = number + 1;
            small += 1;
        }

    }

    if(FactorsPairs == 1)
    {
        cout << "number: " << number << endl;
    }
}

int main()
{
    for(int i = 2; i < 101; i++)
    {
        CheckFactors(i);
        FactorsPairs = 0;
    }


    return 0;
}
