class Solution {
public:
    bool isPalindrome(int x) 
    {
        int r;
        long int rev=0;
        int n=x;
        if(x<0)
        {
            return false;

        }
        while(x)
        {
            r=x%10;
            rev=(10*rev)+r;
            x/=10;
        }
        if(rev<=pow(-2,31)||rev>=(pow(2,31)-1))
        {
            return false;
        }
        else
        {
            if(n==rev)
            return true;
            else
            return false;
        }
    }
};