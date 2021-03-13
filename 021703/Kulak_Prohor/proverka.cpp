#include <iostream>
#include <sstream>
#include <vector>
#include "test.h"

int main() {
    std::vector<int> alice{1, 2, 3};
    std::vector<int> bob{7, 8, 9, 10};
    std::vector<int> eve{1, 2, 3};
    std::vector<int> c;
    if (1 == linear_search(alice,bob,10) ){
        std::cout<<"yes";
    }
    //  int n,m,x,value;
    //cin>>n;
    //int a[n];
    //make_set(a,n);
    /*cin>>m;
    int b[m],c[n+m];
    make_set(b,m);
     x=m+n;
     */
    /*
make_sett(d,n);
cout<<"\n";
cin>>m;
make_sett(b,m);
cout<<"\n";
union_sett(d,b,z);
for (int it : z){
 cout << ' ' << it;}
cout<<'\n';
cin>>x;
element(d,x);
cout<<'\n';
return 0;*/
    /*for( i=0; i<n;i++){
        make_set(i);
    }*/

/*cin>>value;
   insertX(n,a,value);


    cout<<'\n';
    out_set(a,n);
    cout<<'\n';
    remove_duplicate_elements(a,n);
    cout<<'\n';
    out_set(a,n);*/
    /*  union_set(a,b,c,n,m);
      int length;
      length = sizeof(c) / sizeof(c[0]);
      remove_duplicate_elements(c,x);
  */
    /*    insertv(a,value);
        outSet(a);
        vector<int> c(size);
        unionSet(a,b,c);
        outSet(c);
    *//*
void make_set (int v) {
    parent[v] = v;
}
int make_sett(std::set<int>& a,int n){
    int m;
    srand( time(0) );
    for( int i = 0; i < n; i++) {
        std::cin>>m;
        a.insert(m);
    }
    for(auto& str: a) std::cout << str << ' ';
}
int find_set (int v) {
    if (v == parent[v])
        return v;
    return find_set (parent[v]);
}



void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b)
        parent[b] = a;
}
void element(std::set<int>& a,int n){
    if (a.count(n)) {
        std::cout << "yes";
    } else {
        std::cout << "no" ;
    }
}
void union_sett(std::set<int>& a,std::set<int>& b,std::set<int>& c){
c.insert(a.begin(),a.end());
c.insert(b.begin(),b.end());
    for (int it : c){
        std::cout << ' ' << it;}
}
*/
/*typedef struct syst_
{
    int rank, p;
} syst;
void init(syst *a, int n)
{
    int i;
    for (i = 0; i<n; i++)
    {
        a[i].p = i;
        a[i].rank = 0;
    }
}
int fset(syst *a, int x)
{
    if (x != a[x].p)
        a[x].p = fset(a, a[x].p);
    return a[x].p;
}
void sunion(syst *a, int x, int y)
{
    if (a[x].rank < a[y].rank)
        a[x].p = a[y].p;
    else
    {
        a[y].p = a[x].p;
        if (a[x].rank == a[y].rank) a[x].rank++;
    }
}
class dsu {
public:

    void MakeSet(int x) {
        p[x] = x;
    }
};*/

/*void make_set(int a[],const int n){
    for (int i = 0; i < n; i++) {
        std::cin>>a[i];
    }
}

void out_set(int a[], int n){
    for (int i=0;i<n;i++){
        std::cout<<a[i]<<' ';
    }
}
void swapping(int &a, int &b) {      //swap the content of a and b
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void remove_duplicate_elements(int arr[], int n)
{
// Hash map which will store the elements which has appeared previously.
    std::unordered_map<int, bool> mp;


    for(int i = 0; i<n; i++) {
        int swaps = 0;         //flag to detect any swap is there or not
        for(int j = 0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {       //when the current item is bigger than next
                swapping(arr[j], arr[j+1]);
                swaps = 1;    //set swap flag
            }
        }
        if(!swaps)
            break;       // No swap in this pass, so array is sorted
    }
    for (int i = 0; i < n; ++i) {

// Print the element if it is there in the hash map
        if (mp.find(arr[i]) == mp.end()) {
            std::cout << arr[i] << " ";
        }

// Insert the element in the hash map
        mp[arr[i]] = true;
    }
}
void union_set(int a[],int b[],int c[],int n,int m) {
    int index=0;
    for (int i=0;i<n;i++){
        c[index++]=a[i];
    }
    for (int i=0;i<m;i++){
        c[index++]=b[i];
    }
}*/
/*
void insert(std::vector<int>& a, int e)
{
    auto i = std::lower_bound(a.begin(), a.end(), e);
    if (*i != e)
        a.insert(i, e);
}*/
/*
int* insertX(int &n, int *arr,
             int x)
{
    if (arr.find(x)!=arr.end()){
        return 0;
    }

    int i;

    // increase the size by 1
    n++;

    // shift elements forward
    for (i = n; i >= n; i--)
        arr[i] = arr[i - 1];

    // insert x at pos
    arr[n - 1] = x;
    remove_duplicate_elements(a,n);
}*/

}