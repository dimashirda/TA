void dfs(int index, int parent, vector<int>* lis, 
    vector<int>* lds){
	
    int maks = -1, big = -1;
    
	for(int i=0;i<=(int)inp[index].size()-1;i++)
	{
		int temp = inp[index][i];
        if(temp == parent)continue;
        
		if(size[temp] > maks)
		{
            maks = size[temp];
            big = temp;
        }
    }
    addto(lis, index);
    addto(lds, -index);

    if(big == -1)
	{ 
	uplis[index] = new vector<int>();
        uplis[index]->push_back(index);
        
	uplds[index] = new vector<int>();
        uplds[index]->push_back(-index);
        
        ans = max(ans, (int)lis->size());
        ans = max(ans, (int)lds->size());
    }
	else if(parent != -1 && inp[index].size() 
        == 2)
	{ 
        dfs(big, index, lis, lds);
        
        uplis[index] = uplis[big];
        uplds[index] = uplds[big];
        
		addto(uplis[index], index);
		addto(uplds[index], -index);
    }
	else
	{ 
        vector<int> a = *lis;
        vector<int> b = *lds;
        
		dfs(big, index, &a, &b);
        
        uplis[index] = uplis[big];        
		uplds[index] = uplds[big];

        addto(uplis[index], index); 
        addto(uplds[index], -index);

        combine(lis, uplis[index]);
        combine(lds, uplds[index]);

        for(int i=0;i<=(int)inp[index].size()-1;i++)
		{ 
            int temp = inp[index][i];
            if(temp == parent || temp == big)
                continue;
            
            a = *lis;
            b = *lds;

            dfs(temp, index, &a, &b);

            addto(uplis[temp], index);
            addto(uplds[temp], -index);

            combine(uplis[index], uplis[temp]);
            combine(uplds[index], uplds[temp]);
			
			if(i+1 < inp[index].size())
			{
                combine(lis, uplis[temp]);
                combine(lds, uplds[temp]);
            }

            delete uplis[temp];
            delete uplds[temp];
        }
    }
}