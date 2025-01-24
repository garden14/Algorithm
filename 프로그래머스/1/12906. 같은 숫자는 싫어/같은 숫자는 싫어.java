import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        ArrayDeque<Integer> stack = new ArrayDeque<>();
        stack.push(arr[0]);
        
        for(int i=1; i<arr.length; i++) {
            if(arr[i] != stack.peek()) {
                stack.push(arr[i]);
            }
        }
        
        List<Integer> list = new ArrayList<>(stack);
        Collections.reverse(list);
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}