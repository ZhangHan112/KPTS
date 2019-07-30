#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<ctime>
#include<fstream>
using namespace std;

class KPTS{
public:
    int iter;
    int files;
    int tabuL;
    
    int v1;
    int v2;
    int w1;
    int w2;
    int W; 
    int Best;

    vector<int> alternation;
    vector<int> neighbor;
    vector<int> value;
    vector<int> weight;
    vector<int> TabuList;

    KPTS(int Iteration,int Files);
    void TS();
    void ReadFile(int num);
    void Initialize();
    vector<int> Transition(vector<int> arr);
    bool IsTabu(int element);
    void InsertTabu(int element);
    int FitnessV(vector<int> arr);
    int FitnessW(vector<int> arr);
    void Determination();
};