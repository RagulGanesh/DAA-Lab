#include <bits/stdc++.h>
using namespace std;
class obj
{
public:
    int weight;
    int profit;
};
void knapsack(obj list[],int max_wt,int n){
    int B[n+1][max_wt+1];
    int i,w;
    for(i=0;i<=n;i++){
        for(w=0;w<=max_wt;w++){
            if(i==0||w==0){
                B[i][w]=0;
            }
            else if(list[i-1].weight<=w){
                B[i][w]=max(B[i-1][w],list[i-1].profit+B[i-1][w-list[i-1].weight]);
            }
            else{
                B[i][w]=B[i-1][w];
            }
        }
    }

    cout<<B[n][max_wt];

    cout<<"\nObjects Chosen : \n";
    i=n;
    int k=max_wt;
    int p=B[n][max_wt];
    while(i>0&&k>0){
        if(B[i][k]!=B[i-1][k]){
            cout<<i<<"\t";
            i-=1;
            k-=list[i].weight;
            p-=list[i].profit;
        }
        else{
            i-=1;
        }
    }


}
int main()
{
    int n;
    cout << "Enter number of objects : ";
    cin >> n;
    int max_wt;
    cout << "Enter maximum weight : ";
    cin >> max_wt;
    obj list[n];
    int val, wt;
    cout << "Value/Weights  are : ";
    for (int i = 0; i < n; i++)
    {
        val = rand() % 300 + 1;
        wt = rand() % max_wt + 1;
        list[i].weight = wt;
        list[i].profit = val;
        cout << val << " " << wt << "\t";
    }
    
    cout<<"\n";
    knapsack(list,max_wt,n);

}