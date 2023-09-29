/*Write a recursive program that determines whether a given sentence is palindromic or not 
just considering the alpha-numeric characters ('a'-'z'), ('A'-'Z'), ('0'-'9').
This means if you find any non alphanumeric value , you should skip it and consider others alphanumeric values
Input:
madam, i'm adam
hulala
Output:
palindromic
not palindromic
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
using min_heap = priority_queue<T , vector<T> , greater<T>> ; //to make minHeap. min_heap<type> name
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

int isValid(char ch){
    return (isalpha(ch)|| isdigit(ch)) ;
}
bool palin(string& s , int n , int i , int j){

    if(i<n/2){
        if(isValid(s[i]) && isValid(s[j])){
            if(s[i]!=s[j]) return false ; 
            else return palin(s , n , i+1 , j-1) ;
        }
        else if(isValid(s[i])) return palin(s , n , i , j-1) ;
        else if(isValid(s[j])) return palin(s,n , i+1 , j) ;     
    }
    return true; 
}

int32_t main(){
    int t; cin>>t; 
    while(t--){
        string s ; cin>>s; 
        int n = s.size() ; 
        if(palin(s , n , 0 , n-1)) cout<<"palindromic\n" ;
        else cout<<"not palindromic\n" ;  
    }
    
}