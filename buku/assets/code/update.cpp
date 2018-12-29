void update(int idx, int l, int r, int x, int a, int b)
{	
	if (l==r) 
	{
		inc[idx] = a; dcr[idx] = b;
		return;
	}
	int mid = (l+r)>>1, lc = (idx<<1)+1
	int rc = (idx<<1)+2;
	if (x <= mid)
	{
		update(lc, l, mid, x, a,b);
	}
	else
	{
		update(rc, mid+1, r, x, a,b);	
	}
	inc[idx] = max(inc[lc], inc[rc]);
	dcr[idx] = max(dcr[lc], dcr[rc]);
}