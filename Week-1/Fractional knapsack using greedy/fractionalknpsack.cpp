#include <bits/stdc++.h>
using namespace std;

class obj{
    public:
        int weight;
        int value;  
};

bool cmp(obj a,obj b){
    double r1 = (double)a.value/(double)a.weight;
    double r2 = (double)b.value/(double)b.weight;
    return r1>r2;
}

void knapsack(int max_weight,obj list[],int num){
    /*for(int i=1;i<=num;i++){
        cout << list[i].value << list[i].weight << endl;
    }
    cout << endl;*/
    sort(list,list+num,cmp);

    double pweight=0,pval=0;
    int i;
    for(i=0;i<num;i++){
        if(pweight+list[i].weight<=max_weight){
            pweight+=list[i].weight;
            pval+=list[i].value;
            cout<<list[i].weight<<"/"<<list[i].value<<"\t\t\t\t\t"<<1<<"\n";
        }
        else{
            int frac_weight=max_weight-pweight;
            pweight = max_weight;
            pval += ((double)frac_weight/(double)list[i].weight)*list[i].value;
            cout<<list[i].weight<<"/"<<list[i].value<<"\t\t\t\t\t"<<(double)frac_weight/(double)list[i].weight<<"\n";
            break;
        }
    }

    for(int j=i+1;j<num;j++){
        cout<<list[j].weight<<"/"<<list[j].value<<"\t\t\t\t\t"<<0<<"\n";
    }
    cout << "Maximum Value: " << pval;
}

int main(){
    int num;
    cout << "Enter the number of objects : ";
    cin >> num;
    int mweight;
    cout << "Enter the maximum weight : ";
    cin >> mweight;
    int val,weight;
    obj list[num];
    cout<<"Profits Weights :\n";

    for(int i=0;i<num;i++){
        // cout << "Enter value of object" << i+1 << ": ";
        // cin >> val;
        // cout << "Enter weight of object" << i+1 << ": ";
        // cin >> weight;
        val=rand()%300+1;
        weight=rand()%mweight+1;
        list[i].value=val;
        list[i].weight=weight;
        cout<<val<<" "<<weight<<"\t";
    }

    cout<<"\nObjectsChosen/It's Profit\tFraction Chosen : \n";
    knapsack(mweight,list,num);
    
}