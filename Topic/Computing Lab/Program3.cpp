#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int aug[n][n+1];

    for(int i=0;i<n;i++){                                          //row  i
        for(int j=0;j<n+1;j++){                                    //col  j
            cin>>aug[i][j];                                        //input
        }
    }

    for(int i=0;i<n-1;i++){                                         //row  i
        for(int j=i+1;j<n;j++){                                     //other row   j
            float r=(float)aug[j][i]/(float)aug[i][i];              //ratio  r

            for(int k=i;k<n+1;k++){                                   //col  k
                aug[j][k]-=r*aug[i][k];
            }
        }
    }

    for(int i=0;i<n;i++){                                          //row  i
        for(int j=0;j<n+1;j++){                                    //col  j
            cout<<aug[i][j]<<" ";                                  //output
        }
        cout<<endl;
    }

    int flag=0,ans=0;
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(aug[i][j]!=0) {flag=1;break;}
        }

        if(flag==0) {
            if(aug[i][j]!=0){             //Inconsistent
                ans=-1;
                break;
            }
        }
        else break;                        //Inf soln
    }

    return 0;
}