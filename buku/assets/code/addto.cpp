void addto(vector<int>* vec, int val){
    vector<int>::iterator p = lower_bound(vec->begin(), 
    	vec->end(), val);    
    if(p == vec->end())	
    {	
		vec->push_back(val);	
	}
    else
	{	
    	*p = val;	
	}
}