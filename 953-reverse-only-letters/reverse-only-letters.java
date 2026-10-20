class Solution {
    public String reverseOnlyLetters(String s) {
        int left = 0, right = s.length() - 1;
        char[] arr = s.toCharArray();

        while(left < right) {
            while(left < right && !Character.isLetter(arr[left])) 
                left++;

            while(left < right && !Character.isLetter(arr[right]))
                right--;
            
            char tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;

            left++;
            right--;
        }
        return new String(arr);
    }
}