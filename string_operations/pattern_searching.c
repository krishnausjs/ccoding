/* 
Description: Given a text[0..n-1] and pattern pat[0..m-1], write a function
search(char pat[], char txt[]) that prints all occurances of pat[] in txt[].
You may assume that n>m.

Example:
Input : txt[] = "AABAACAADAABBAABA"
		  pat[] = "AABA"

Output: Pattern found at index 0
        Pattern found at index 13

Analysis:
==> Naive pattern searching algorithm doesnt work well in cases where we see
many matching characters followed by a mismatching character.

Ex. txt[]="AAAAAAAAAAAAAAAAAB"
    pat[]="AAAAB"

To solve this, we can use KMP Matching algorithm. KMP means Knuth Morris Pratt.
Worst case complexity of KMP is O(n). 
The basic idea behind KMP algorithm is: Whenever we detect a mismatch(after some matches),
we already know some of the characters in the text of next window.
We take advantage of this information to avoid matching the characters that we know
will anyway match.

Matching Overview:
txt = "AAAAABAAABA"
pat = "AAAA"

We compare first window of txt with pat



*/
