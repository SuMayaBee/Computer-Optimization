#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int cut[1000];

int func(int len, vector<int> &prices) {
    if(len==0) return 0;
    if(dp[len]!=-1) return dp[len];
    int ans=0;
    for(int len_to_cut=1; len_to_cut<=len; len_to_cut++) {
        int temp = prices[len_to_cut-1] + func(len-len_to_cut, prices);
        if(temp > ans) {
            ans = temp;
            cut[len] = len_to_cut;
        }
    }

    return dp[len]=ans;
}


vector<int> cutrod(int price[], int n) {
    memset(dp, -1, sizeof(dp));
    vector<int> prices(price, price+n);

    int ans = func(n, prices);
    cout<<ans<<endl;

    vector<int> pieces;
    while(n > 0) {
        pieces.push_back(cut[n]);
        n -= cut[n];
    }

    return pieces;
}

int main() {

    int n;
    cin>>n;
    int array[n];
    for(int i=0; i<n; i++) {
        cin>>array[i];
    }

    vector<int> pieces = cutrod(array, n);
    for(int piece : pieces) {
        cout << piece << " ";
    }
    cout << endl;

    // multiple rod cutting

    // int m;
    // cin>>m;
    // int rods[m];
    // for(int i=0; i<m; i++) {
    //     cin>>rods[i];
    // }

    // for(int i=0; i<m; i++) {
    //     vector<int> pieces = cutrod(array, rods[i]);
    //     for(int piece : pieces) {
    //         cout << piece << " ";
    //     }
    //     cout << endl;
    // }

  

    return 0;
}

//----------------------------------------------------------------------------------------------------

// with cost

// #include<bits/stdc++.h>
// using namespace std;
// int dp[1000];
// int cut[1000];

// int func(int len, vector<int> &prices, int cost) {
//     if(len==0) return 0;
//     if(dp[len]!=-1) return dp[len];
//     int ans=0;
//     for(int len_to_cut=1; len_to_cut<=len; len_to_cut++) {
//         int temp = prices[len_to_cut-1] + func(len-len_to_cut, prices, cost) - (len_to_cut < len ? cost : 0);
//         if(temp > ans) {
//             ans = temp;
//             cut[len] = len_to_cut;
//         }
//     }

//     return dp[len]=ans;
// }


// vector<int> cutrod(int price[], int n, int cost) {
//     memset(dp, -1, sizeof(dp));
//     vector<int> prices(price, price+n);

//     int ans = func(n, prices, cost);
//     cout<<ans<<endl;

//     vector<int> pieces;
//     while(n > 0) {
//         pieces.push_back(cut[n]);
//         n -= cut[n];
//     }

//     return pieces;
// }

// int main() {

//     int n;
//     cin>>n;
//     int array[n];
//     for(int i=0; i<n; i++) {
//         cin>>array[i];
//     }

//     int cost;
//     cin>>cost;

//     vector<int> pieces = cutrod(array, n, cost);
//     for(int piece : pieces) {
//         cout << piece << " ";
//     }
//     cout << endl;

//     return 0;
// }

//8
// 1 5 8 9 10 17 17 20
// 2

// multiple cost

// #include<bits/stdc++.h>
// using namespace std;
// int dp[1000];
// int cut[1000];

// int func(int len, vector<int> &prices, vector<int> &costs) {
//     if(len==0) return 0;
//     if(dp[len]!=-1) return dp[len];
//     int ans=0;
//     for(int len_to_cut=1; len_to_cut<=len; len_to_cut++) {
//         int temp = prices[len_to_cut-1] + func(len-len_to_cut, prices, costs) - (len_to_cut < len ? costs[len_to_cut-1] : 0);
//         if(temp > ans) {
//             ans = temp;
//             cut[len] = len_to_cut;
//         }
//     }

//     return dp[len]=ans;
// }


// vector<int> cutrod(int price[], int n, int cost[]) {
//     memset(dp, -1, sizeof(dp));
//     vector<int> prices(price, price+n);
//     vector<int> costs(cost, cost+n);

//     int ans = func(n, prices, costs);
//     cout<<ans<<endl;

//     vector<int> pieces;
//     while(n > 0) {
//         pieces.push_back(cut[n]);
//         n -= cut[n];
//     }

//     return pieces;
// }

// int main() {

//     int n;
//     cin>>n;
//     int array[n];
//     for(int i=0; i<n; i++) {
//         cin>>array[i];
//     }

//     int cost[n];
//     for(int i=0; i<n; i++) {
//         cin>>cost[i];
//     }

//     vector<int> pieces = cutrod(array, n, cost);
//     for(int piece : pieces) {
//         cout << piece << " ";
//     }
//     cout << endl;

//     return 0;
// }




// 8
// 1 5 8 9 10 17 17 20


//----------------------------------------------------------------------------------------------------------------------
// normal rod cutting

// #include<bits/stdc++.h>
// using namespace std;
// int dp[1000];

// int func(int len, vector<int> &prices) {
//     if(len==0) return 0;
//     if(dp[len]!=-1) return dp[len];
//     int ans=0;
//        for(int len_to_cut=1; len_to_cut<=len; len_to_cut++) {
//          int temp = prices[len_to_cut-1] + func(len-len_to_cut, prices);
//          if(temp > ans) {
//              ans = temp;
//              //cut[len] = len_to_cut;
//             // cout<<len_to_cut<<" ";
//          } 
//      }  

//     return dp[len]=ans;
// }


// int cutrod(int price[], int n) {
//     memset(dp, -1, sizeof(dp));
//     vector<int> prices(price, price+n); 

//     return func(n, prices);

// }

// int main() {

//     int n;
//     cin>>n;
//     int array[n];
//     for(int i=0; i<n; i++) {
//         cin>>array[i];
//     }

//    cout<<cutrod(array, n)<<endl;

//     return 0;
// }

