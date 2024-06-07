


#include<bits/stdc++.h>
using namespace std;


class sgt{
      public :
      vector<int>seg;
      sgt(int n){
        seg.resize(4*n+2);
      }

      void build(int ind,int start,int end,vector<int>&arr){
           
           if(start==end){
            seg[ind]=arr[start];
            return;
           }

         int mid=(start+end)>>1;
          build(2*ind+1,start,mid,arr);
          build(2*ind+2,mid+1,end,arr);
          seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
         // cout<<seg[ind]<<ind<<endl;
      }

      int query(int ind,int start,int end,int l,int r){

              if(end<l||r<start){
                return INT_MAX;
              }

              if(r>=end&&start>=l){
                 return seg[ind];
              }
              int mid=(start+end)>>1;
              int left=query(2*ind+1,start,mid,l,r);
              int right=query(2*ind+2,mid+1,end,l,r);
              return min(left,right);
      }
};

int main(){
    int n,q;
cin>>n>>q;
vector<int>arr(n);
for(int i=0;i<n;i++) cin>>arr[i];

    sgt sg(n);
  sg.build(0,0,n-1,arr);

  while(q--){
    int l,r;
    cin>>l>>r;
    l--;r--;
    cout<<sg.query(0,0,n-1,l,r)<<endl;
  }

}
