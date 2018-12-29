int main()
{   
    int T, n,
    cin>>T;   
    while(T--)
	{	
		cin>>n;
        for(int i=1;i<=n;i++)
		{ 
        	inp[i].clear();
        }
        for(int i=1;i<=n-1;i++)
		{
            int a,b;
            cin>>a;
            cin>>b;
            inp[a].push_back(b);
            inp[b].push_back(a);
        }        
        init(1, -1);
        ans = 0;
        vector<int> a,b;
        dfs(1, -1, &a, &b);
        ans = max(ans, (int)uplis[1]->size()); 
        ans = max(ans, (int)uplds[1]->size());
        cout<<ans<<endl;
    }
    return 0;
}