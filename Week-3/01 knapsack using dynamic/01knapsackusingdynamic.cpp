#include <bits/stdc++.h>
using namespace std;

class obj{
    public:
        int time;
        int points;  
};

bool cmp(obj a,obj b){
    double r1 = (double)a.points/(double)a.time;
    double r2 = (double)b.points/(double)b.time;
    return r1>r2;
}

void knapsack(int max_time,obj list[],int num){
    int B[num+1][max_time+1];
    for(int i=0;i<=num;i++){
        for(int w=0;w<=max_time;w++){
            if(i==0||w==0){
                B[i][w]=0;
            }
            else if(list[i-1].time<=w){
                if(list[i-1].points+B[i-1][w-list[i-1].time]>B[i-1][w])
                    B[i][w]=list[i-1].points+B[i-1][w-list[i-1].time];
                else
                    B[i][w]=B[i-1][w];
            }
            else
                B[i][w]=B[i-1][w];
        }
    }
    //return B[num][max_time];
    int max_score = B[num][max_time];
    cout << "Maximum Score= " << max_score << endl;
    cout << "Questions: ";
    for(int i=num;i>0;i--){
        if(max_score>0){
            if(max_score!=B[i-1][max_time]){
                cout << i << " ";
                max_score-=list[i-1].points;
                max_time-=list[i-1].time;
            }
        }
    }
}

void randgen(obj list[], int num,int mtime){
    for(int i=0;i<num;i++){
        list[i].points=(rand()%300)+1;
        list[i].time=(rand()%mtime)+1;
        cout<<list[i].points<<"\t"<<list[i].time<<"\n";
    }
    cout << endl;
}

int main(){
    int num;
    cout << "Enter the number of objects: ";
    cin >> num;
    int val,time;
    obj list[num];
    int mtime;
    cout << "Enter the maximum time: ";
    cin >> mtime;
    cout<<"Points\tTime : \n";
    randgen(list,num,mtime);
    knapsack(mtime,list,num);
}