impl Solution {
    fn is_vowel(c: char) -> bool {
        let valids = vec!['a', 'e', 'i', 'o', 'u'];
        for valid in valids.iter() {
            if *valid == c { return true; }
        }
        return false
    }
    pub fn does_alice_win(s: String) -> bool {
        for c in s.chars() {
            if (Self::is_vowel(c)) {
                return true;
            }
        }
        return false;
    }
}