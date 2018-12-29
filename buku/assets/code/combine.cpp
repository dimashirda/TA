void combine(vector<int>* a,vector<int> *b)
{     
	int p = 0;
	while(1)
	{
        if(p >= b->size()) break;
        else if(p >= a->size())
		{	
			a->push_back((*b)[p]);	
		}
        else if(p < b->size())
		{	
			(*a)[p] = min((*a)[p], 
				(*b)[p]);	
		}
        p++;
    }
}