void init(int now, int par)
{
	size[now] = 1;
	in[now] = ++cnt;
	num[cnt] = now;
	for(int i=0;i<=(int)inp[now].size()-1;i++)
	{
		if(inp[now][i] == par) continue;
		init(inp[now][i],now);
		size[now] += size[inp[now][i]];
	}
	out[now] = cnt;
}		