class Solution {
public:
    string intToRoman(int num) {
        vector<int>ditributiveForm;
        int flag=1;
        while(num){
        ditributiveForm.push_back((num%10)*flag);
        num/=10;
        flag*=10;
        }
        
        unordered_map<int,string>mp;
        mp[0]="";
        mp[1000]="M";
        mp[2000]="MM";
        mp[3000]="MMM";

       
        mp[0]="";
        mp[100]="C";
        mp[200]="CC";
        mp[300]="CCC";
        mp[400]="CD";
        mp[500]="D";
        mp[600]="DC";
        mp[700]="DCC";
        mp[800]="DCCC";
        mp[900]="CM";

        

        mp[0]="";
        mp[10]="X";
        mp[20]="XX";
        mp[30]="XXX";
        mp[40]="XL";
        mp[50]="L";
        mp[60]="LX";
        mp[70]="LXX";
        mp[80]="LXXX";
        mp[90]="XC";

       
        mp[0]="";
        mp[1]="I";
        mp[2]="II";
        mp[3]="III";
        mp[4]="IV";
        mp[5]="V";
        mp[6]="VI";
        mp[7]="VII";
        mp[8]="VIII";
        mp[9]="IX";

        string ans="";

        for(int i=ditributiveForm.size()-1;i>=0;i--){
           ans+=mp[ditributiveForm[i]];
        }

return ans;
    }
};