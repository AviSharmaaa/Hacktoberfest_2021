// A simple coding problem based upon String, but could also be asked with numbers. You need to write a Java program to check if two given strings are anagrams of Each other. Two strings are anagrams if they are written using the same exact letters, ignoring space, punctuation, and capitalization. Each letter should have the same count in both strings. For example, the Army and Mary are an anagram of each other.
//
// Read more: https://javarevisited.blogspot.com/2015/01/top-20-string-coding-interview-question-programming-interview.html#ixzz782yYIms1

import java.util.Arrays;

/**
 * Java program - String Anagram Example.
 * This program checks if two Strings are anagrams or not
 *
 * @author Javin Paul
 */
public class AnagramCheck {
   
    /*
     * One way to find if two Strings are anagram in Java. This method
     * assumes both arguments are not null and in lowercase.
     *
     * @return true, if both String are anagram
     */
    public static boolean isAnagram(String word, String anagram){       
        if(word.length() != anagram.length()){
            return false;
        }
       
        char[] chars = word.toCharArray();
       
        for(char c : chars){
            int index = anagram.indexOf(c);
            if(index != -1){
                anagram = anagram.substring(0,index) 
                       + anagram.substring(index +1, anagram.length());
            }else{
                return false;
            }           
        }
       
        return anagram.isEmpty();
    }
   
    /*
     * Another way to check if two Strings are anagram or not in Java
     * This method assumes that both word and anagram are not null and lowercase
     * @return true, if both Strings are anagram.
     */
    public static boolean iAnagram(String word, String anagram){
        char[] charFromWord = word.toCharArray();
        char[] charFromAnagram = anagram.toCharArray();       
        Arrays.sort(charFromWord);
        Arrays.sort(charFromAnagram);
       
        return Arrays.equals(charFromWord, charFromAnagram);
    }
   
   
    public static boolean checkAnagram(String first, String second){
        char[] characters = first.toCharArray();
        StringBuilder sbSecond = new StringBuilder(second);
       
        for(char ch : characters){
            int index = sbSecond.indexOf("" + ch);
            if(index != -1){
                sbSecond.deleteCharAt(index);
            }else{
                return false;
            }
        }
       
        return sbSecond.length()==0 ? true : false;
    }
}


Read more: https://javarevisited.blogspot.com/2013/03/Anagram-how-to-check-if-two-string-are-anagrams-example-tutorial.html#ixzz782ygYEnX

