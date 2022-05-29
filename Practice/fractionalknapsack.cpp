#include<bits/stdc++.h>
using namespace std;
class obj{
    public:
    int weight;
    int profit;    
};
bool cmp(obj a,obj b){
    double a1=double(a.profit)/(double(a.weight));
    double a2=double(b.profit)/(double(b.weight));
    return a1>a2;
}
int fractional_knapsack(int max_wt,obj list[],int n){
    double pweight=0,pval=0;
    sort(list,list+n,cmp);
    int i,j;
    for(i=0;i<n;i++){
        if(pweight+list[i].weight<=max_wt){
            pweight+=list[i].weight;
            pval+=list[i].profit;
            cout<<list[i].weight<<"/"<<list[i].profit<<"\t"<<1<<"\n";
        }
        else{
            double frac_wt=max_wt-pweight;
            pweight=max_wt;
            pval+=(double(frac_wt)/(double(list[i].weight))*list[i].profit);
            cout<<list[i].weight<<"/"<<list[i].profit<<"\t"<<(double(frac_wt)/(double(list[i].weight)))<<"\n";
            break;
        }
    }

    for(int j=i+1;j<n;j++){
        cout<<list[i].weight<<"/"<<list[i].profit<<"\t"<<0<<"\n";
    }

    cout<<"Therefore, total profit is equal to : "<<pval;
}
int main(){
    int n;
    cout<<"Enter number of objects : "; 
    cin>>n;
    int max_wt;
    cout<<"Enter maximum weight : ";
    cin>>max_wt;
    obj list[n];
    int val,wt;
    cout<<"Value/Weights  are : ";
    for(int i=0;i<n;i++){
        val=rand()%300+1;
        wt=rand()%max_wt+1;
        list[i].weight=wt;
        list[i].profit=val;
        cout<<val<<" "<<wt<<"\t\t";
    }
    
    cout<<"\n";
    cout<<"ObjectsChosen\tFractionChosen : \n";
    fractional_knapsack(max_wt,list,n);
}