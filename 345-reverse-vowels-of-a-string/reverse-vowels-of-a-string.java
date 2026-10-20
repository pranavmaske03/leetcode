class Solution {
    public String reverseVowels(String s) {
        int left = 0, right = s.length() - 1;
        boolean isLeft = false, isRight = false;
        char[] charArr = s.toCharArray();
        String vowels = "AEIOUaeiou";

        while(left < right) {
            if(vowels.indexOf(charArr[left]) != -1) {
                isLeft = true;
            }

            if(vowels.indexOf(charArr[right]) != -1) {
                isRight = true;
            }

            if(isRight && isLeft) {
                char temp = charArr[left];
                charArr[left] = charArr[right];
                charArr[right] = temp;

                isLeft = false;
                isRight = false;
            }

            if(!isLeft)
                left++;
            if(!isRight)
                right--;
        }

        return new String(charArr);
    }
}