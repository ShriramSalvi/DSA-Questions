/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        
        HashMap<ListNode,Integer>mp = new HashMap<>();

        ListNode temp = head;

        while(temp != null){
            if(!mp.containsKey(temp)){
              mp.put(temp,0);
              temp=temp.next;
            }
            else{
             return   true;
            }
        }

        return false;
    }
}