# CS50-Assignments

---

This is a repository to collect the assignments from Harvard's CS50 course.

---

# Problem Set 1

Hello.c is a simple Hello World program that prompts the user to enter their name, and then displays the response.

Mario.c is a program that prompts the user to enter a number, and then creates a pyramid from the game 'Super Mario Bros', with the height based on the user input.

Cash.c is a program that prompts the user for a numberic input and calculates the total number of coins needed to provide change to a customer based on the user input i.e. 96 returns 6 (3 quarters, 2 dimes, 1 penny)


---

# Problem Set 2

Scrabble.c is a lab that assesses each letter in a word entered by Player 1 & Player 2.  Each letter is mapped to a point value (based on the classic Scrabble scoring), then the program calculates a winner based on who enters a word that scores the highest.  In the event of a tie, the program will inform the users of a 'Tie!'.

Readability.c is a program that assesses the reading level of a user provided text using the Coleman-Liau Index.  The program takes into account the number of letters in each word and the number of words in each sentence, and provides the grade level for the text.  If the reading level is below Grade 1, the program declares "Below Grade 1" and if the reading level is 16 or above, the program declares "Grade 16+".

Caesar.c is a slightly more robust program than previous entries.  This program serves to encrypt user-entered text using a Caesar Cipher (letter + user defined key = new letter).  The program takes one positive numeric command line argument, and returns an error for any more or less than one argument or if the argument is not a positive numeric entry.  The command line argument serves as the "key" (k) for the cipher.  The user is then prompted to enter plain text that will be encrypted.  Any capital & lowercase letters will be shifted by "k" while any non-letter characters will be preserved (i.e. punctuation & numbers).  The cipher text will then e printed for the user.

