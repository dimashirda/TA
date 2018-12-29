void init(int index, int parent)
{ 
   	size[index] = 1;
    for(int i=0;i<=(int)inp[index].size()-1;i++)
	{
        if(inp[index][i] == parent)continue;
        init(inp[index][i], index);
        size[index] += size[inp[index][i]];
    }
}