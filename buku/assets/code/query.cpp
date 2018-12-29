int query(int idx, int l, int r, int x, int y, int flag)
{
	if (l>y || r<x)
	{
		return 0;
	} 
	if (x<=l && r<=y)
	{	
		if (!flag) 
		{
			return inc[idx];
		}
		else
		{	
			return dcr[idx];
		}
	}
	int mid = (r+l)>>1, lc = (idx<<1)+1
	int rc = (idx<<1)+2;
	int a = max(query(lc,l,mid,x,y,flag),
	query(rc,mid+1,r,x,y,flag));
	return a;
}