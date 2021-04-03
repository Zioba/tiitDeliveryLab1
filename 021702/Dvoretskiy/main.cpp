#include <iostream>
#include <vector>
#include <string.h>
#include <time.h>
#include <fstream>
#include "myTree.h"

using namespace std;

pair<bool, int> runTest(string inputFilename, string expectedFilename)
{
    ifstream in(inputFilename);
    ifstream expIn(expectedFilename);
    while(in)
    {
        node* root;
        int length;
        string funcName, strArr;
        int answer = 1233;
        in >> funcName;
        if(funcName == "create")
        {
            vector<int> input;
            int vectSize;
            in >> vectSize;
            length = vectSize;
            for(int i = 0; i < vectSize; i++)
            {
                int buff;
                in >> buff;
                input.push_back(buff);
            }
            root = tree::build(input, 0, input.size() - 1);
        }
        if(funcName == "find_max")
        {
            int l, r;
            in >> l >> r;
            answer = tree::find_max(root, l, r, 0);
        }
        if(funcName == "add")
        {
            int l, r, value;
            in >> l >> r >> value;
            tree::add_value(root, l, r, value);
        }
        if(funcName != "" && funcName != "add" && funcName != "find_max" && funcName != "create")
        {
            cout << "ERROR: wrong function name in" << inputFilename << ": " << funcName << endl;
            pair<bool, int> result = {0, -1e9};
            return result;
        }

        if(funcName == "find_max"){
            int expectedAnswer;
            expIn >> expectedAnswer;
            if(answer != expectedAnswer){
                pair<bool, int> result = {0, answer};
                return result;
            }
        }
    }
    pair<bool, int> result = {1, 1e9};
    return result;
}

void testProgram()
{
    for(int curTestNumber = 0; curTestNumber <= 5; curTestNumber++)
    {
        string curTestNumberS = to_string(curTestNumber);
        string testFileName = "E:\\CodeBlocks\\projects\\myTree\\Tests\\Test" + curTestNumberS + ".txt";
        string expOutputFileName = "E:\\CodeBlocks\\projects\\myTree\\Tests\\ExpectedAnswer" + curTestNumberS + ".txt";
        pair<bool, int> testResult = runTest(testFileName, expOutputFileName);
        if(testResult.first)
        {
            cout << endl << "test #" + curTestNumberS + " passed successfully " << endl << endl;
        }
        else
        {
            int expectedAnswer;
            cout << "test #" + curTestNumberS + " failed" << endl;
            ifstream expIn(expOutputFileName);
            expIn >> expectedAnswer;
            cout << "Expected answer: " << expectedAnswer << endl;
            cout << "Resulting answer: " << testResult.second << endl << endl;
        }
    }
}

int main()
{
    testProgram();
}

