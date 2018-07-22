//O(nlogn)
void lis(){
	v.clear();
	v.push_back(seq[0]);
	for (int i = 1; i < n; ++i)
	{
		if (seq[i]>v[v.size()-1])
		{
			v.push_back(seq[i]);
		}else{
			it=lower_bound(v.begin(),v.end(),seq[i]);
			*it=seq[i];
		}
	}
}