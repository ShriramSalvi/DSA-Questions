class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        
        Arrays.sort(tokens);
        
        if(tokens.length==0 || tokens[0]>power)return 0;

        int score1=0;
        int power1=power;

        int left=0;
        int right=tokens.length -1;

        while(left<right){
            if(power<tokens[left] && score1>=1){
                score1--;
                power+=tokens[right];
                right--;
            }
            else{
                score1++;
                power-=tokens[left];
                left++;
            }
        }
        
        int left1=0;
        int right1=tokens.length-1;
        int score2=0;
        
        while(left1<=right1){
            if(power1<tokens[left1] && score2>=1){
                score2--;
                power1+=tokens[right1];
                right1--;
            }
            else{
                score2++;
                power1-=tokens[left1];
                left1++;
            }
        }

        return Math.max(score1,score2);
    }
}