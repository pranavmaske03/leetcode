import java.util.*;

class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        long shiftSum = 0;
        StringBuilder str = new StringBuilder(s); 

        for (int i = shifts.length - 1; i >= 0; i--) {
            shiftSum = (shiftSum + shifts[i]) % 26;
            int idx = str.charAt(i) - 'a';
            char shifted = (char)('a' + (idx + shiftSum) % 26);
            str.setCharAt(i, shifted);
        }

        return str.toString(); 
    }
}


public class 848_ShiftingLetters
{
    public static void main(String args[])
    {
        String s = "abc";
        int[] shifts = {3, 5, 9};

        Solution solution = new Solution();
        String result = solution.shiftingLetters(s, shifts);

        System.out.println("Original: " + s);
        System.out.println("Shifted : " + result);   
    }
}