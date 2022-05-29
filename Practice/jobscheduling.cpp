#include<bits/stdc++.h>
using namespace std;
class job{
    public:
    string id;
    int profit;
    int deadlines;
};
bool cmp(job a,job b){
    return a.profit>b.profit;
}
void job_scheduling(job list[],int n){
    sort(list,list+n,cmp);
    int i,j;
    int slots[n];
    int results[n];
    for(i=0;i<n;i++){
        slots[i]=false;
    }
    for(i=0;i<n;i++){
        for(j=min(list[i].deadlines,n)-1;j>=0;j--){
            if(slots[j]==false){
                slots[j]=true;
                results[j]=i;
                break;
            }
        }
    }

    for(i=0;i<n;i++){
        if(slots[i]){
            cout<<list[results[i]].id;
        }
    }

    


}
int main(){
    cout<<"Enter number of objects : ";
    int n;
    cin>>n;
    job list[n];
    for(int i=0;i<n;i++){
        cin>>list[i].id>>list[i].profit>>list[i].deadlines;
    }

    job_scheduling(list,n);
        
}