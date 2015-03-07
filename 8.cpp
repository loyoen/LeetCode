class Solution {
public:
    int atoi(string str) {
        if(str.length()==0)
            return 0;
        long long ans = 0;
        int sig = 1;
        int index=0;
        while(str.at(index)==' '||str.at(index)=='\t')
            index++;
        if(str.at(index)=='-')
        {
            sig = -1;
            index ++; 
        }
        else if(str.at(index)=='+')
        {
            index ++;
        }
        for(;index<str.length();index++)
        {
            if(str.at(index)>='0'&&str.at(index)<='9')
            {
                ans *= 10;
                ans += str.at(index)-'0';
                if(sig==1&&ans>2147483647)
                    return 2147483647;
                if(sig==-1&&sig*ans<-2147483648)
                    return -2147483648;
            }
            else
                break;
        }
        return int(sig*ans);
    }
};
