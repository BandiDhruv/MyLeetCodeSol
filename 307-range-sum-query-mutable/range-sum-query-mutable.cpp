class NumArray {
public:
    vector<int> segTree;
    
    void built(vector<int>&nums,int idx,int l,int r){
        if(l==r){
            segTree[idx]=nums[l];
            return ;
        }
        int mid=(l+r)/2;
        built(nums,2*idx+1,l,mid);
        built(nums,2*idx+2,mid+1,r);
        segTree[idx]=segTree[2*idx+1]+segTree[2*idx+2];
        return ;
    }
    void updateQ(int index,int val,int idx,int l,int r){
        if(l==r){
            segTree[idx]=val;
            return ;
        }
        int mid=(l+r)/2;
        if(index<=mid)updateQ(index,val,2*idx+1,l,mid);
        else updateQ(index,val,2*idx+2,mid+1,r);
        segTree[idx]=segTree[2*idx+1]+segTree[2*idx+2];
        return ;
    }
    int query(int s,int e,int i,int l,int r){
        if(l>e || r<s)return 0; //out of bound wala case
        if(l>=s && r<=e) return segTree[i]; //compeletely inside
        int mid=(l+r)/2;
        return query(s,e,2*i+1,l,mid)+query(s,e,2*i+2,mid+1,r);
    }

    int n;
    NumArray(vector<int>& nums) {
        segTree.resize(4*nums.size());
        n=nums.size();
        if(n!=0)
            built(nums,0,0,n-1);
    }
    
    void update(int index, int val) {
        updateQ(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return query(left,right,0,0,n-1);    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */