
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
using namespace std;

int main () {
    string firstLine;
    string line;
    ifstream myfile ("A-small-practice.in.txt");
    ofstream myfile2 ("smallOutputFile.txt");
    string totalCredit;
    string numProducts;
    string spacedInts;
    string garbageLine;
    int caseCount = 1;
    
    
    //while both files are open
    if (myfile.is_open() && myfile2.is_open())
    {
        while ( getline (myfile,line) )
        {
            //get the first line, which will state the number of cases
            getline(myfile, firstLine);
            int convertedFirstLine = atoi(firstLine.c_str());
        
            //run for as many cases there are
            for(int b=0; b<convertedFirstLine; b++) //consider using while loop
            {
                list<int> steps;
                int matchCounter = 0;
                int count1 = 0;
                int count2 = 0;
                
                //get the total credit and convert to int
                getline(myfile, totalCredit);
                int convertedTotalCredit = atoi(totalCredit.c_str());
                
                //get the number of products and convert to int
                getline(myfile, numProducts);
                int convertedNumProducts = atoi(numProducts.c_str());
                
                
                //cout << "Enter the cost of the items in the store separated by spaces" << endl;
                getline(myfile, spacedInts);
                
                istringstream is( spacedInts );
                int n;
                while( is >> n ) {
                    steps.push_back(n);
                }

                for (list<int>::const_iterator i = steps.begin(); i != steps.end(); ++i)
                {
                    count1++;
                    count2 = 0;
                    
                    for(list<int>::const_iterator x = steps.begin(); x != steps.end(); ++x)
                    {
                        count2++;
                        if(matchCounter < 1)
                        {
                            if((*i+*x == convertedTotalCredit) && (i != x))
                            {
                                myfile2 << "Case #" << caseCount << ": " << count1 << " " << count2 << endl;
                                matchCounter++;
                                caseCount++;
                            }
                        }
                    }
                }
            }
            myfile2.close();
            myfile.close();
        }
    }
    else cout << "Unable to open file";
    
    return 0;
}



