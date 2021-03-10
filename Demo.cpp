/**
 * Demo program for snowman exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-02
 */

#include "snowman.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	cout << ariel::snowman(44242223) << endl;   /* Should print:
_===_
(.,.)
( : )
( : )
	*/
	cout << ariel::snowman(12341234) << endl;   /* Should print:
   _
  /_\
\(o_O)
 (] [)>
 (   )
	*/
	// try {
	// 	cout << ariel::snowman(5) << endl;   // Exception - not a valid code
	// } catch (exception& ex) {
	//  	cout << "   caught exception: " << ex.what() << endl;  // should print "Invalid code '5'"
	// }
}
