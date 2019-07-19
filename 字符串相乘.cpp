class Solution {
public:
    string multiply(string num1, string num2) {
        string result;
        string zero;
        if(num2=="0"||num1=="0")
            return "0";
        for(int i = num2.size()-1;i>=0;i--)
        {
            string temp = getNum(num1,num2[i])+zero;
            result = getSum(temp,result);
            zero = zero+'0';
        }
        return result;
    }
    string getNum(string num1,char num2)
    {
        
        string result;
        if(num2=='0')
            return result;
        int temp = 0;
        for(int i = num1.size()-1;i>=0;i--)
        {
            char y = '0' + ((num1[i]-'0')*(num2-'0')+temp)%10;
            result = y + result;
            temp = ((num1[i]-'0')*(num2-'0')+temp)/10;
        }
        if(temp>0)
        {
            char y = '0' + temp;
            result = y + result;
        }
        return result;
    }
    string getSum(string num1,string num2)
    {
        if(num2=="")
            return num1;
        if(num1[0]=='0')
            return num2;
        int index = num1.size()-1;
        while(num2.size()<num1.size())
        {
            num2='0'+num2;
        }
        int temp = 0;
        string result;
        while(index>=0)
        {
            char x = '0';
            x = (num1[index]-'0'+num2[index]-'0'+temp)%10+'0';
            //cout<<x<<endl;
            result = x+result;
            temp = (num1[index]-'0'+num2[index]-'0'+temp)/10;
            index--;
        }
        if(temp>0)
        {
            char y = '0' + temp;
            result = y + result;
        }
        return result;
    }
};