#include <bits/stdc++.h>
using namespace std;
class segment_tree{
    vector<int>segment;
    public: 
             segment_tree(int n){
                 segment.resize(4*n+1);
             }
             void build(int index,int low,int high,int arr[]){
                 if(low==high){
                     segment[index]=arr[low];
                     return;
                 }
                 int mid=(low+high)>>1;
                 build((2*index)+1,low,mid,arr);
                 build((2*index)+2,mid+1,high,arr);
                 segment[index]=min(segment[2*index+1],segment[2*index+2]);
             }
             int  query(int index,int low,int high,int l,int r){
                 //no overlap [low,high] [l,r] or [l,r] [low,high]
                 if(l>high || r<low){
                     return INT_MAX;
                 }
                 // full overlap [l low high r]
                 if(low>=l and high<=r){
                     return segment[index];
                 }
                 // partial overlap
                 int mid=(low+high)>>1;
                 int left=query((2*index)+1,low,mid,l,r);
                 int right=query((2*index)+2,mid+1,high,l,r);
                 return min(left,right);
             }
             void update(int index,int low,int high,int i,int val){
                 if(low==high){
                     segment[index]=val;
                     return;
                 }
                 int mid=(low+high)>>1;
                 if(i<=mid){
                     update((2*index)+1,low,mid,i,val);
                 }else{
                     update((2*index)+2,mid+1,high,i,val);
                 }
                 segment[index]=min(segment[2*index+1],segment[2*index+2]);
             }

};
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    segment_tree seg1(n);
    seg1.build(0,0,n-1,a);
   cout<< seg1.query(0,0,n-1,1,4)<<endl;
   seg1.update(0,0,n-1,3,12);
   cout<< seg1.query(0,0,n-1,1,4)<<endl;

}
