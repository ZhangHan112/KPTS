#include "KPTS.h"

KPTS::KPTS(int Iteration,int Files){
    iter = Iteration;
    files = Files;

    v1=0;
    v2=0;
    w1=0;
    w2=0;
    W=0;

    alternation = vector<int>();
    neighbor = vector<int>();
    value = vector<int>();
    weight = vector<int>();
    TabuList = vector<int>();

    srand(time(NULL));

}
void KPTS::TS(){
    string s = "output0.dat";
    for(int f=1;f<=files;f++){
        ReadFile(f);
        Initialize();

        s.replace(6,1,to_string(f));
        ofstream file(s);

        for(int i=0;i<iter;i++){    
            neighbor = Transition(alternation);
            v1 = FitnessV(alternation);
            v2 = FitnessV(neighbor);
            w1 = FitnessW(alternation);
            w2 = FitnessW(neighbor);
            Determination();
            file << i << " " << Best << endl;
        }
        file.close();
        cout << "Best: " << Best << endl;
    }
}

void KPTS::Initialize(){
    Best=0;
    tabuL = value.size()*0.3;
    alternation.clear();
    neighbor.clear();
    TabuList.clear();
    for(int i=0;i<value.size();i++){
        alternation.push_back(0);
        neighbor.push_back(0);
    }
    for(int i=0;i<tabuL;i++){
        TabuList.push_back(-1);
    }

}

vector<int> KPTS::Transition(vector<int> arr){
    int pos,it=0;
    vector<int> temp = arr;
    vector<int> res = arr;
    while(it<100){
        pos = rand()%value.size();
        
        if( IsTabu(pos)==true )
            continue;
        else{
            if(temp[pos]==1) 
                temp[pos] = 0;
            else 
                temp[pos] = 1;

            it++;
            if(FitnessV(temp)<=Best)
                continue;
            else
                res = temp;
            
            InsertTabu(pos);
            break;
        }
    }
    return res;
}

bool KPTS::IsTabu(int element){
    bool temp=false;
    for(int i=0;i<tabuL;i++)
            if(TabuList[i]==element)
                temp = true;
             
    return temp;

}

void KPTS::InsertTabu(int element){
    int update = 0;
    for(int i=0;i<tabuL;i++){
        if(TabuList[i]==-1){
            TabuList[i] = element;
            update = 1; 
            break;
        }   
    }
    if(update==0){
        TabuList.erase(TabuList.begin());
        TabuList.push_back(element);
    }
}

int KPTS::FitnessV(vector<int> arr){
    int sum=0;
    for(int i=0;i<arr.size();i++)
        if(arr[i]==1)
            sum += value[i];
    return sum;
}

int KPTS::FitnessW(vector<int> arr){
    int sum=0;
    for(int i=0;i<arr.size();i++)
        if(arr[i]==1)
            sum += weight[i];
    return sum;
}

void KPTS::Determination(){
    if( w1<W && w2<W ){
        if( v1<v2 ){
            if(Best<v2)
                Best = v2;
            alternation = neighbor;
            
        }
    }

}

void KPTS::ReadFile(int num){
    string s = "p00_p.txt";
    ifstream inputFile;
    int temp;

    value.clear();
    weight.clear();
    W=0;

    s.replace(2,1,to_string(num));
    inputFile.open(s);
    while(inputFile>>temp){
        value.push_back(temp);
    }
    inputFile.close();

    s.replace(4,1,"w");
    inputFile.open(s);
    while(inputFile>>temp){
        weight.push_back(temp);
    }
    inputFile.close();

    s.replace(4,1,"c");
    inputFile.open(s);
    inputFile>>temp;
    W = temp;
    inputFile.close();
}