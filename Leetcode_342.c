bool isPowerOfFour(int n) {

if(n<=0)
    {
        return 0;
    }
 for(int i=0; i<20;i++)
    {
  if(n==pow(4, i))
  {
    return 1;
    }
  
}
return 0;
}
//2147483647   

