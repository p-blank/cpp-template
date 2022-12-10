// GENERATE ALL PERMUTATIONS WITH REPITITIONS

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define rep(I, A, B) for(int I = A; I < B; I++)
#define all(s) s.begin(),s.end()
#define endl "\n"

/*----------------------------------------------------------------------*/
template<typename TYPE> 
void print(vector<TYPE> s){
    for(auto i : s) cout << i;
    cout << "\t";
}

template<typename TYPE>
void nextPerm(vector<TYPE> &s, vector<TYPE> &p, int id){
   rep(i, 0, s.size()){
       p[id] = s[i];
       if(id == s.size() - 1) print(p);
       else nextPerm(s, p, id + 1);
   }
}

template<typename TYPE>
void genPerm(vector<TYPE> s){
    vector<TYPE> p(s.size());
    nextPerm(s, p, 0);
}
/*----------------------------------------------------------------------*/

int main(){
    genPerm(vector<int> ({1, 2, 3}));
}