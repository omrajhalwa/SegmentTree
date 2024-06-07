


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
          seg[ind]=(seg[2*ind+1]+seg[2*ind+2]);
         
      }

      void update(int ind,int start,int end,int idx,int val){

          if(start==end){
            seg[ind]=val;
            return ;
          }
         int mid=(start+end)>>1;
         if(mid>=idx){
            update(2*ind+1,start,mid,idx,val);
         }else{
            update(2*ind+2,mid+1,end,idx,val);
         }

         seg[ind]=(seg[2*ind+1]+seg[2*ind+2]);
      }

      int query(int ind,int start,int end,int l,int r){

              if(end<l||r<start){
                return 0;
              }

              if(r>=end&&start>=l){
                 return seg[ind];
              }
              int mid=(start+end)>>1;
              int left=query(2*ind+1,start,mid,l,r);
              int right=query(2*ind+2,mid+1,end,l,r);
              return (left+right);
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
    int type=2;
   // cin>>type;
    if(type==1){
         int idx,val;
          cin>>idx>>val;
          idx--;
          sg.update(0,0,n-1,idx,val);
          arr[idx]=val;
    }else{
        int l,r;
    cin>>l>>r;
    l--;r--;
    cout<<sg.query(0,0,n-1,l,r)<<endl;
    }
    
  }

}
