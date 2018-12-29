void dfs(int now, int par, int flag)
{
	int maks = -1, big = -1;
	for(int i=0;i<=(int)inp[now].size()-1;i++)
	{	
		int temp = inp[now][i];
		if(temp == par) continue;
		if(size[temp] > maks)
		{
			maks = size[temp];
			big = temp;
		}
	}
	for(int i=0;i<=(int)inp[now].size()-1;i++)
	{	
		int temp = inp[now][i];
		if(temp != par && temp != big)
		{	
			dfs(temp,now,0);
		}
	}
	if(big > 0) 
	{	
		dfs(big,now,1);
	}
	for(int i=0;i<=(int)inp[now].size()-1;i++)
	{	
	int temp = inp[now][i];
	if(temp == par || temp == big) 
	continue; 
	for(int i=in[temp];i<=out[temp];i++)
	{	
		int val = num[i], maks;

		if(val < now) 
		{	
		maks = query(0,1,n,now+1,n,1);
		ans = max(ans,maks+1+dpUp[val]);
		}
		else 
		{
		maks = query(0,1,n,1,now-1,0);
		ans = max(ans,maks+1+dpDec[val]);
		}

	maks = query(0,1,n,1,val-1,0);
	ans = max(ans,maks+dpDec[val]);

	maks = query(0,1,n,val+1,n,1);
	ans = max(ans,maks+dpUp[val]);
	}
	for(int i=in[temp];i<=out[temp];i++)
	{
	int val = num[i];
	update(0,1,n,val,dpUp[val],dpDec[val]);
	}
	}
	dpUp[now] = query(0,1,n,1,now-1,0) + 1; 
	dpDec[now] = query(0,1,n,now+1,n,1) + 1;

	ans = max(ans, max(dpUp[now], dpDec[now]));
		
	if(!flag)
	{	
	for(int i=in[now]+1;i<=out[now];i++)
	{	
		update(0,1,n,num[i],0,0);
	}
	}
	else 
	{	
	update(0,1,n,now,dpUp[now],dpDec[now]);
	}
}