# Store-Credit
OOP Project Question #2

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <list>
using namespace std;

int main()
{
    string n;
    string x;
    string testCaseCount;
    
    cout << "How many test cases will you be entering?" << endl;
    getline(cin,testCaseCount);
    int convertedCaseCount = atoi(testCaseCount.c_str());
    
    
    for(int z = 0; z != convertedCaseCount; z++)
    {
        //Here we obtain the amount of store credit and the num of items in the store, and convert them into ints.
        cout << "Case # " << z+1 << ": " << endl << "Enter the store credit amount:" << endl;
        getline(cin, n);
        int storeCredit = atoi(n.c_str());
        
        cout << "Enter the number of items in the store:" << endl;
        getline(cin, x);
        int numItemsInStore = atoi(x.c_str());
        
        list<int> steps;
        
        int matchCounter = 0;
        int count1 = 0;
        int count2 = 0;
        
        
        string input;
        cout << "Enter the cost of the items in the store separated by spaces" << endl;
        getline(cin, input);
        istringstream iss(input);
        int temp;
        while(iss >> temp)
        {
            steps.push_back(temp);
        }
        
        for (list<int>::const_iterator i = steps.begin(); i != steps.end(); ++i)
        {
            count1++;
            
            for(list<int>::const_iterator x = steps.begin(); x != steps.end(); ++x)
            {
                count2++;
                if(matchCounter < 1)
                {
                    if(*i+*x == storeCredit && *i != *x)
                    {
                        cout << "The two items that add up to your store credit are " << count1 << " & " << count2 << endl;
                        matchCounter++;
                    }
                }
            }
        }
    }
}
