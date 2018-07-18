int gcd(int x,in y){
	if (y==0)
	{
		return x;
	}else{
		return gcd(y,x%y);
	}
}