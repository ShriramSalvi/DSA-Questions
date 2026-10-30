class Solution {
    public int[] plusOne(int[] digits) {
        
        int right=digits.length-1;
        int carry=1;
        
        while(right>=0 && carry!=0){
            int val = digits[right];
            digits[right]=(carry+digits[right])%10;
            carry=(carry+val)/10;
            right--;
        }

        if(carry==1){
            System.out.println(carry);
             System.out.println(right);
            int []temp= new int[digits.length+1];
            temp[0]=1;

            for(int i=0;i<digits.length;i++){
                temp[i+1]=digits[i]%10;
            }

            return temp;
        }

        return digits;
    }
}