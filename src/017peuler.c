#include <stdio.h>

int main(){

	int i;
	unsigned int sum = 0;
	//ones: one two three four five six seven eight nine =0+3+3+5+4+4+3+5+5+4 = 36
	const int ones = 36;
	// teens: ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen =
	// = 3+6+ 6+8+ 8+7+ 7+9+ 8+8= 9+14+15+16+16 = 70
	const int teens = 70;
	//twenty - ninety: twenty thirty forty fifty sixty seventy eighty ninety = 6+6+5+5+5+7+6+6 =46
	const int twe_to_nin = 46;



	for(i = 0; i < 10; i++){
		/* 0-19 */
		sum += ones;
		sum += teens;

		/* 20-99 */
		sum += twe_to_nin * 10;
		sum += ones * 8;
	}

	sum += 10; /*one hundred*/
	sum += 99 * 13; /*one hundred and*/

	sum += 10; /*two hundred*/
	sum += 99 * 13; /*two hundred and*/

	sum += 12; /*three hundred*/
	sum += 99 * 15; /*three hundred and*/

	sum += 11; /*four hundred*/
	sum += 99 * 14; /*four hundred and*/

	sum += 11; /*five hundred*/
	sum += 99 * 14; /*five hundred and*/

	sum += 10; /*six hundred*/
	sum += 99 * 13; /*six hundred and*/

	sum += 12; /*seven hundred*/
	sum += 99 * 15; /*seven hundred and*/

	sum += 12; /*eight hundred*/
	sum += 99 * 15; /*eight hundred and*/

	sum += 11; /*nine hundred*/
	sum += 99 * 14; /*nine hundred and*/


	sum += 11;/*one thousand*/
	printf("sum: %d\n", sum);
	return 0;
}
