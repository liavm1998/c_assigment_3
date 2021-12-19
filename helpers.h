
/**
 * @file QuesAnswers.h
 * @author liav levi (liavmoshe12345@gmail.com)
 * @brief 
 * this header file represent assigment 3
 * @date 2021-12-16
 */
#define TXT 1024
#define WORD 30

/**
 * @brief 
 * 
 * @param c accept char 
 * @return the accepted char gematrical value
 */
int gio(int c);

/**
 * @brief 
 * 
 * @param txt represents text
 * @param s_pointer start point
 * @param e_pointer end point
 * @return the sum of the  gematrical value of the chars 
 *         in the accepted text in the scoup between the accepted points 
 */
int sumCal (char* txt, int s_pointer, int e_pointer);

/**
 * @brief 
 * this function accept string and return the reverse of that string 
 */
char *strrev(char *str);

/**
 * @brief 
 * this function accept string and char and return the string without the first occurance of the char
 */
void deletechar(char *s,char c);

/**
 * @brief 
 * this for scanning word
 */
char *scanWord();


/**
 * @brief 
 * this for scanning text
 */
char *scanText();