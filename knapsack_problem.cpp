/*
0/1 knapsack problem
------------------------

item   1   2   3   4   5
--------------------------
P=     10  15  18  8   4 (price/value)
W=     2   5   7   11  3 (weight)

n= 3 (maximum item)
w= 14 (maximum weight)

find the maximum profit/value. 
*/



#include<bits/stdc++.h>
using namespace std;

int P[5]={10,15,18,8,4}, W[5]= {2,5,7,11,3}, n = 3, w= 14, check[5];

int utility_function(){

    int cnt = 0, cntW = 0, cntP = 0;

    for(int i = 0; i < 5; i++){
        if (check[i]==1){
            cnt++;
            cntW = cntW + W[i];
            cntP = cntP + P[i];
            //cout << i << ' ' << cnt << ' ' << cntW << ' ' << cntP << endl;
        }
    }
    if(cnt>n || cntW>w) return -1; //invalid solution
    return cntP;
}




int  main(){

//hill climbing algorithm
// srand(time(NULL)); //[to generate unique random numbers]

    int global = 0;
    while(true){

    
        for(int i = 0; i<5; i++){
            int x = rand(); //[same pile of random numbers]
            check[i]= x % 2;
            //cout << i << ' ' << x << ' ' << check[i] << endl; 
        }

        int local = utility_function();

        for(int j = 1; j<=1000; j++){
            int index = rand()%5;

            if(check[index]==1) check[index]= 0;
            else check[index]=1;

            local = max(local,utility_function());
        

            if(global<local){
                global = local;
                for(int i = 0; i < 5; i++){
                    if(check[i]==1){
                        cout << i << endl;
                    } 
                }   cout << endl << endl;
            }
        }
    }
    return 0;

}