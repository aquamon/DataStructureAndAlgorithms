// 
// Recursive
class Solution {
public:
    double Pow(double x, int n) {
        
        double temp;
        if(n == 0)
            return 1;
        temp = Pow(x,n/2);
        if(n%2 == 0)
            return temp*temp;
        else
            return temp*temp*x;
    }
    
    double myPow(double x, int n)
    {
        if(n<0)
        {
            return double(1/Pow(x,n));
        }
        return Pow(x,n);
    }
};
// Iterative
class Solution {
public:
    double myPow(double x, int n) {
        
        if(n == 0)
            return 1;
        if(n < 0)
        {
            n = abs(n);
            x = 1/x;
        }
        double ans = 1.0;
        while(n > 0)
        {
            if(n%2 == 0)
            {
                x = x*x;
                n /=2;
            }
            else
            {
                ans = ans*x;
                n -= 1;
            }
        }
        
        return ans;
    }
};