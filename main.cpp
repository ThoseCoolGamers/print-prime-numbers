#include <iostream>
#include <vector>
 
using namespace std;
 
int GetFactorInfo(int numberwithourinfo, int returnmode)
{
 
    int factorpairs = 0;
 
    int smallestfactor = 1;
 
    int biggestfactor = numberwithourinfo + 1;
 
 
    int smallestreturnablefactor = 0;
 
    int biggestreturnablefactor = 0;
 
 
    for(int i = 0; i < (numberwithourinfo * numberwithourinfo); i++)
    {
 
        if(smallestfactor * biggestfactor == numberwithourinfo)
        {
 
            smallestreturnablefactor = biggestfactor;
 
            biggestreturnablefactor = smallestfactor;
 
 
            biggestfactor -= 1;
 
            factorpairs += 1;
        }
        else
        {
 
            biggestfactor -= 1;
        }

        if(biggestfactor == 0)
        {
 
            biggestfactor = numberwithourinfo + 1;
 
            smallestfactor += 1;
        }
    }
	
    if(returnmode == 0)
        return factorpairs;
 
    if(returnmode == 1)
        return biggestreturnablefactor;
 
    if(returnmode == 2)
        return smallestreturnablefactor;
}
 
void PrintFactorization(int numbertofactorize)
{
    vector<int> factors;
 
    int printlooppos = 0;
 
    for(int i = 0; i < numbertofactorize; i++)
    {
 
        if(GetFactorInfo(numbertofactorize,0) > 1)
        {
 
            if(GetFactorInfo(numbertofactorize,0) == 1)
                factors.push_back(GetFactorInfo(numbertofactorize,1));
 
            if(GetFactorInfo(numbertofactorize,2) > 0)
                factors.push_back(GetFactorInfo(numbertofactorize,2));

            numbertofactorize = GetFactorInfo(numbertofactorize, 1);
        }
    }
 
    factors.push_back(GetFactorInfo(numbertofactorize,2));
 
    for(vector<int>::iterator i = factors.begin(); i != factors.end(); i++)
    {
 
        cout << factors.at(printlooppos) << endl;
 
        printlooppos++;
    }
}
 
 
int main()
{
 
    cout << "      Prime Numbers      " << endl;
 
    cout << "=========================" << endl;
 
    for(int i = 2; i < 100; i++)
    {
 
        if(GetFactorInfo(i,0) == 1)
            cout << i << endl;
    }

    int numbertofactorize;
 
    cout << "Please Enter a number to factorize: " << endl;
 
    cin >> numbertofactorize;
 
    if(GetFactorInfo(numbertofactorize, 0) == 1)
    {
 
        system("CLS");
 
        cout << "      Prime Numbers      " << endl;
 
        cout << "=========================" << endl;
 
        cout << "Prime factorization of " << numbertofactorize << endl;
 
        cout << "1" << endl;
 
        cout << numbertofactorize << endl;
    }
 
    else
    {
 
        system("CLS");
 
        cout << "      Prime Numbers      " << endl;
 
        cout << "=========================" << endl;
 
        cout << "Prime factorization of " << numbertofactorize << endl;
 
        PrintFactorization(numbertofactorize);
    }
 
 
    return 0;
 
}
