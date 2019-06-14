#include <bits/stdc++.h>

using namespace std;
// Segmnt tree code
const int N = 1e6+ 9 , M = 1e5 +9;
int tree[N] , arr[M] , n , querys ;
void build(int node , int start , int end){

    if(start==end) {
        tree[node] = arr[end];
    }
    else{
        int mid = start + (end - start) / 2;
        build(2 * node , start , mid);

        build(2 * node +1 , mid +1 , end);
        tree[node] = tree[2*node] + tree[2*node + 1];
    }


}
void update(int node , int start , int end ,  int idx , int val){
    if(start==end){
        arr[idx]+= val ;
        tree[node]+= val;
    }
    else{
        int mid = (start + end) / 2;
        if(idx>=start && idx<= mid)
            update(2*node , start , mid , idx , val);
        else{
            update(2*node +1 , mid +1  , end , idx , val);
        }
        tree[node] = tree[2* node] + tree[2 * node + 1];
    }
}
int main()
{   // an example to use segment tree to has some of queries

    for(int i = 0 ; i < 6; ++i){
        cin >> arr[i];
    }
    build(1 , 0 , 6);
    for(int i = 1 ; i<=13 ; ++i){
        cout << tree[i] << " ";
    }
    cout << "\n";
    // after updating idx (0)
    update(1 , 0 , 6 , 0 , 2 );
    for(int i = 1 ; i<=13 ; ++i){
        cout << tree[i] << " ";
    }

    return 0;
}
