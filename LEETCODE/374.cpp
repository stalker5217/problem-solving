/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long lower = 1;
        long long higher = n;
        
        long long pick;
        while(true) {
            pick = (lower + higher) / 2;
            int result = guess(pick);
            
            if(result == 0) break;
            else if(result < 0) higher = pick - 1;
            else lower = pick + 1;
        }
        
        return pick;
    }
};