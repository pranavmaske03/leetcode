import java.util.*;

class Solution 
{
    public int[][] transpose(int[][] matrix) 
    {
        int row = matrix.length;
        int col = matrix[0].length;

        int[][] transpose = new int[col][row];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                transpose[j][i] = matrix[i][j];
            }
        }
        return transpose;
    }
}

public class 867_TransposeMatrix 
{
    public static void main(String[] args) 
    {
        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        Solution sol = new Solution();
        int[][] result = sol.transpose(matrix);

        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[0].length; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }
}
