class Solution {
public:
    int addDigits(int n) {
        while(n>9){
            int tp=0;
            string s = to_string(n);
            for(int i=s.size()-1;i>=0;i--){
                tp+= s[i]-'0';
            }

            n=tp;
        }

        return n;
    }
};

class Solution {
public:
    int addDigits(int num) {
        while(num>=10)
        {  int ans=0,rem;
            while(num!=0)
            {
            rem=num%10;
            num=num/10;
            ans=ans+rem;
            }
            num=ans;
        }
         
         return num;   
    }
    
};
