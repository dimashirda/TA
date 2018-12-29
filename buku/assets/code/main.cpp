int main()
{
	int T, n;
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
			int a, b;
			cin>>a;
			cin>>b;
			inp[a].push_back(b);
			inp[b].push_back(a);
		}
		ans = 0;
		cnt = 0;
		init(1,-1);
		dfs(1,-1,0);
		cout<<ans<<endl;
	}
	return 0;
}
