#include<bits/stdc++.h>

using namespace std;

vector<int> indices(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        arr[i] = i;
    }
    return arr;
}
void indicesByReference(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        arr[i] = i;
    }
}

bool comp(string &a, string &b){
    return a[0] < b[0];
}

bool comp_int(int &a, int &b){
    return a>b;
}

int medianFromVector(vector<int> arr){

    // arr.begin() -> iterator in vector
    // [1, 2, 4, 5, 6]
    // arr.begin() points arr[0] = 1;

    /*
    int arr1[10];
    int *p = arr1;  // points to arr1[0]
    cout<<*p<<endl;
    p = p+1;    // points to arr1[1]

    while(p!=arr+n){
        cout<<*p<<endl;
        p++;
    }
    */

   // vector<int>::iterator p = arr.begin();
   auto p = arr.begin();
   cout<<*p<<endl; // points to arr[0];
   p++;
   cout<<*p<<endl; // points to arr[1];

   while(p != arr.end()){
       cout<<*p<<endl;
       p++;
   }

   auto p_r = arr.rbegin(); // reverse iterator
   // p_r points arr[n-1]
   while(p_r != arr.rend()){
       cout<<*p<<endl;
       p++;
   }

    // sorting array
    // vector<string> v_s = {"bc", "abc", "aba"};
    // sort(v_s.begin(), v_s.end());   // arranges in increasing order
    // v_s = ["aba", "abc", "bc"]

    // sort(v_s.begin(), v_s.end(), comp);
    // v_s = ["abc", "aba", "bc"] or v_s = ["aba", "abc", "bc"];

    sort(arr.begin(), arr.end(), greater<int>());
    sort(arr.begin(), arr.end(), comp_int);

    int n = arr.size();
    if(n%2){
        return (arr[n/2]+arr[n/2-1])/2;
    } else {
        return arr[n/2];
    }
}

int medianFromSet(vector<int> arr){
    // Set
    // 1. stores unique element
    // 2. orders elements in increasing

    // set<int> s{0,1,5,7};

    // for(auto x:arr){
    //     cout<<x<<" ";
    // }
    // for(auto &x:arr){
    //     x = 1;
    // }
    // fill(arr.begin(), arr.end(), 4);    // fills array in the range

    set<int> s;
    for(auto x:arr){
        s.insert(x);
    }

    // arr = [1,4,1,3,6,6]
    // 1-> s = {1}
    // 2-> s = {1, 4}
    // 3-> s = {1, 4}
    // 4-> s = {1, 3, 4}
    // 6-> s = {1,3,4,6}

    multiset<int> ms;
    for(auto x:arr){
        ms.insert(x);
    }

    auto itr = ms.find(4);  // returns iterator to first occurrence of 4
    ms.erase(itr);   // delete 4
    // *itr;   // either gives error or garbage
    itr = ms.find(7); // returns ms.end()
    int n = ms.size();
    // 6-> ms = {1,1,3,4,6,6}
    
    vector<int> arr(ms.begin(), ms.end());
    return arr[n/2];
}

int medianFromMap(vector<int> arr){
    map<int, long> m;
    for(auto x:arr){
        m[x]++;
    }

    // arr = {1,3,1,2,2,3,4}
    // 1-> m{1:1}
    // 2-> m{1:1, 3:1}
    // 3-> m{1:2, 3:1}
    // 7-> m{1:2, 2:2, 3:2, 4:1}

    // m = {};
    // m[1]; // m = {1:0}
    // m[1]++; // m = {1:1}
    // m[3]; // m = {1:1, 3:0}
    // m[3]++; // m = {1:1, 3:1}

    pair<int, string> p{1,"devanshu"};
    p.first = 2;    // p = {2, "devanshu"}
    cout<<p.first<<endl;    //prints 1
    cout<<p.second<<endl;   //prints devanshu

    auto itr = m.find(3);
    // (*itr).first points to key
    // (*itr).second points to val

    // cout<<itr->first;    // more efficient and readable

    // vector<pair<int,int>> v_p{{1,2}, {2,4}, {4,5}};
    // cout<<v_p[0].first<<endl;
    // cout<<v_p[1].second<<endl;
    
    // iterating over map
    // for(auto &it:m){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    // changing key in map
    // int key = 5;
    // itr = m.find(key);
    // m[4] = itr->second;
    // m.erase(itr);
}

int main(){
    //empty array initialisation
    vector<int> arr;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x==-1) break;
        // arr = [1,2,3,4];
        // arr.push_back(x); // x = 5;
        // arr = [1,2,3,4,5];

        arr.push_back(x);
    }

    // declaring with size
    vector<int> arr2(n);    // n-length vector with each element as 0.
    vector<int> arr3(n,4);  // n-length vector with each element as 4.
    vector<int> arr4 = vector<int> (n);

    indicesByReference(arr4); // by reference

    vector<int> index_arr = indices(vector<int> (n,0));
    vector<int> x = vector<int> {-1,0,1,0};    // x = [-1,0,1,0]
    vector<int> y{0,-1,0,1};    // y = [0,-1,0,1]
    
    for(int i=0; i<n ;i++){
        cin>>arr2[i];
    }

    cout<<medianFromVector(arr)<<endl;

    cout<<medianFromSet(arr)<<endl;

    cout<<medianFromMap(arr)<<endl;

    return 0;
}