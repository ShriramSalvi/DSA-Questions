class Solution {
    public int numRescueBoats(int[] people, int limit) {
        if(people.length==1)return 1;
        if(people.length==2 &&( people[0]+people[1])<=limit)return 1;
        if(people.length==2 &&( people[0]+people[1])>limit)return 2;

        Arrays.sort(people);

        int ans=0;
        int left=0;
        int right=people.length-1;
        int currWeight=0;

        while(left<=right){
           if((right-1>=0)&&(people[right]+people[right-1])<=limit){
            right-=2;
           }
           else if((people[left]+people[right])<=limit){
                left++;
                right--;
            }
           else{
                right--;
            }
            ans++;
        }

        

        return ans;
    }
}