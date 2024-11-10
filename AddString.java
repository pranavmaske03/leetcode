class Solution 
{
    public String addStrings(String num1, String num2) 
    {
        StringBuilder result = new StringBuilder();
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) 
        {
            int sum = carry;
            if (i >= 0) 
            {
                sum += num1.charAt(i--) - '0';
            }
            if (j >= 0) 
            {
                sum += num2.charAt(j--) - '0';
            }
            result.append(sum % 10);
            carry = sum / 10;
        }

        return result.reverse().toString();
    }
}
class AddString
{
    public static void main(String args[])
    {
        String str1 = "6913259244",str2 = "71103343";

        Solution obj = new Solution();
        String sret = obj.addStrings(str1,str2);
        System.out.println("Result is : "+sret);
    }
}