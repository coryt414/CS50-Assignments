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


---

# Problem Set 3

Plurality.c implements a plurality election.  The program takes candidates as command line arguments (max 9 candidates), and then takes user input to determine how many voters are involved, then collects votes one user at a time (1 vote per voter).  The program calculates the winner or winners of the election and prints the name(s).

Runoff.c is a program that implements a more complex runoff election.  The program takes candidates as command line arguments (max 9 candidates), and then takes user input to determine how many voters are involved.  From there, the user is prompted to rank candidates for each voter, so that each voters ballot contains the complete list of candidates in order of voter preference.  The program reports if there is a tie among all candidates, a winner if one candidate has more than 50% of the vote, or begins eliminating candidates one by one based on who has the minimum number of votes.  As each candidate is elimintated, the program re-assesses if any candidates have received the majority vote by looking at subsequent selections by voters who have had their candidate eliminated from the running.  Final result of the program is an announcement of the winner's name printed to the console.



---

# Problem Set 4

Volume.c takes 3 command line arguments -- an input filename (.wav), an output filename (.wav), and a factor.  The program reads the input.wav file, copies the header (44-bits for a .wav) to the output.wav, and then adjusts the volume by the factor input (i.e. 0.5 = half the volume, 2.0 = double the volume).  This program explores several topics: error handling based on incorrect number or type of command line arguments, memory usage, pointers & buffers, and 'fread' / 'fwrite' functions.

Filter.c takes 3 command line arguments -- a flag for a filter type (-g - grayscale, -s - sepia, -r - reflected, -b - blurred), an input filename (.bmp), and an output filename (.bmp).  The program then copies 2 headers from the input.bmp file to the output.bmp file and applies the selected filter to the input.bmp image by looping through each pixel and performing the prescribed filter function. The assignment primarily involved creating the helper functions in helpers.c, while the supplied material (instructor-made) included functions that handled opening & closing the files, calling the helper functions, defining some of the data types (using typedef), and running the Makefile.  The key concepts used in this assignment include understanding custom data types and how to access various bytes within them, how to effectively use buffers to temporarily store data for use, and how to work on projects with multiple files in the primary directory.

Recover.c takes one command line argument -- an input filename (.raw).  The program is intended to identify the number of .jpg images on a corrupt memory card, generate unique filenames for each image, and copy all data from each image into it's respective file.  This program steps through the memory cards memory, looking for 3 bits that signify the beginning of a .jpg image (0xff, 0xd8, 0xff).  Once these are identified, it opens a new file and begins to copy data.  The memry card stores data in blocks that are 512-bytes long, so the program copies data in these 512-byte chunks.  Once the program identifies the start of a new .jpg (sees bits 0xff, 0xd8, 0xff), it closes the previous image file and opens a new image file.  This continues until the program reads all data present on the memory card, at which case it closes all open files.
