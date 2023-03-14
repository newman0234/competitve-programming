#include <bits/stdc++.h>
using namespace std;
int lower_bound(int arr[],int n,int key){
    int s=0;
    int e=n-1;
    int ans=n;
    while(s<=e){
        int mid=(s+e)>>1;
        if(arr[mid]>=key){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
}
int main() {
   // lower bound in binary search
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   int key;
   cin>>key;
   cout<<lower_bound(a,n,key)<<endl;
}
