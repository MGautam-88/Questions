long long solve2(vector<int>&a,vector<int>&b){
    int n=a.size();

    map<int,int> ma,mb,df;
    for(int i=0;i<n;i++){
        ma[a[i]]++;
    }

    for(int i=0;i<n;i++){
        mb[b[i]]++;
    }
    
    for(auto x:ma){
        df[x.first]= x.second - mb[x.first];
    }
    for(auto y:mb){
        df[y.first]=ma[y.first]-y.second;
    }

    vector<int> ea,eb;

    for(auto z:df){
        if(z.second & 1)return -1;//if diff is odd not possible 
        if(z.second>0){ea.insert(ea.end(),z.second/2,z.first);}
        else if(z.second<0){eb.insert(eb.end(),abs(z.second/2),z.first);}
    }
    
    sort(ea.begin(),ea.end());//not needed but for safety
    sort(eb.begin(),eb.end(),greater<int>());//in dec order

    if(ea.size()!= eb.size()) return -1;
    
    int m = ea.size();
    long long ans=0;

    for(int i=0;i<m;i++){
        ans+=min(ea[i],eb[i]);
    }

    return ans;
}
