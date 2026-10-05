class Solution {
    public int[] shortestToChar(String s, char c) {
        int n = s.length();
        List<Integer> charIdx = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == c) {
                charIdx.add(i);
            }
        }

        int[] res = new int[n];
        for (int i = 0, k = 0; i < n; i++) {
            res[i] = Math.abs(i - charIdx.get(k));
            if (k + 1 < charIdx.size() && i == charIdx.get(k)) {
                k++;
            }
        }
        for (int i = n - 1, k = charIdx.size() - 1; i >= 0; i--) {
            res[i] = Math.min(res[i], Math.abs(i - charIdx.get(k)));
            if (k - 1 >= 0 && i == charIdx.get(k)) {
                k--;
            }
        }
        return res;
    }
}