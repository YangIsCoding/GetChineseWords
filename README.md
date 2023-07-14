# GetChineseWords
 This is a program that reads text from stdin than analyze it into UTF-8.
 It checks the value of the first byte of the character and determines the number of bytes for that character based on the UTF-8 encoding rules. It then stores the corresponding bytes in the ch array.
 
 If the highest bit of the first byte is 1, it indicates a multi-byte UTF-8 character. According to the UTF-8 rules, the number of bytes for that character is determined by the count of consecutive bits with the highest bit set to 1.
 
 If the highest bit of the first byte is 0, it indicates a single-byte ASCII character.
