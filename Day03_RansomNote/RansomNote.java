package Day03_RansomNote;

import java.util.Map;
import java.util.Scanner;
import java.util.HashMap;

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> hm1 = new HashMap<>();
        Map<Character, Integer> hm2 = new HashMap<Character, Integer>();
        for (int i = 0, len = ransomNote.length(); i < len; ++i) {
            final char x = ransomNote.charAt(i);
            hm1.put(x, hm1.getOrDefault(x, 0) + 1);          
        }
        
        for (int i = 0, len = magazine.length(); i < len; ++i) {
            final char x = magazine.charAt(i);
            hm2.put(x, hm2.getOrDefault(x, 0) + 1);
        }

        for (Map.Entry<Character, Integer> entry : hm1.entrySet()) {
            if (!hm2.containsKey(entry.getKey()) ||  hm2.get(entry.getKey()) - entry.getValue() < 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String ransomNote = sc.nextLine();
        String magazine = sc.nextLine();
        System.out.println(new Solution().canConstruct(ransomNote, magazine));
        sc.close();
    }
}