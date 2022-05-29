#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin>>a;
    cin>>b;
    int B[b.length()+1][a.length()+1];
    for(int i=0;i<=b.length();i++){
        for(int j=0;j<=a.length();j++){
            B[i][j]=0;
        }
    }

    for(int i=1;i<=b.length();i++){
        for(int j=1;j<=a.length();j++){
            if(a[j-1]=='\0'||b[i-1]=='\0'){
                continue;
            }
            else if(a[j-1]==b[i-1]){
                B[i][j]=1+B[i-1][j-1];
            }
            else{
                B[i][j]=max(B[i-1][j],B[i][j-1]);
            }
        }
    }

        for(int i=0;i<=b.length();i++){
        for(int j=0;j<=a.length();j++){
            cout<<B[i][j]<<"\t";
        }
        cout<<"\n";
    }
}