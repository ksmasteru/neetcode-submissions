class Solution {
    public boolean isAnagram(String s, String t) {
        // key/val where key is char and val is occurence rate/freq
        HashMap<Character, Integer> sMap = new HashMap<>();
        HashMap<Character, Integer> tMap = new HashMap<>();

        for (char c : s.toCharArray()) {
            if (sMap.containsKey(c)) {
                sMap.put(c, sMap.get(c) + 1);
            }
            else {
                sMap.put(c, 1);
            }
        }
        for (char c : t.toCharArray()) {
            if (tMap.containsKey(c)) {
                tMap.put(c, tMap.get(c) + 1);
            }
            else {
                tMap.put(c, 1);
            }
        }
        return (tMap.equals(sMap));
    }
}
