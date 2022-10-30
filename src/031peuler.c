#include <stdio.h>
#include <time.h>

int main(){
	unsigned int a, b, c, d, e, f, g, h, sum;
	unsigned int count = 0;
	clock_t start, end;
	start = clock();


	/* 200p */
	for(a = 0; a <= 1; a++){
		/* 100p */
		for(b = 0; b <= 2; b++){
			/* 50p */
			for(c = 0; c <= 4; c++){
				/* 20p */
				for(d = 0; d <= 10; d++){
					/* 10p */
					for(e = 0; e <= 20; e++){
						sum = 200*a + 100*b + 50*c + 20*d + 10*e;
						if(sum > 200)
							break;

						/* 5p */
						for(f = 0; f <= 40; f++){
							sum = 200*a + 100*b + 50*c + 20*d + 10*e + 5*f;
							if(sum > 200)
								break;

							/* 2p */
							for(g = 0; g <= 100; g++){
								sum = 200*a + 100*b + 50*c + 20*d + 10*e + 5*f + (g << 1);
								if(sum > 200)
									break;

								/* 1p */
								for(h = 0; h <= 200; h++){
									sum = 200*a + 100*b + 50*c + 20*d + 10*e + 5*f + (g << 1) + h;

									if(sum == 200){
										count ++;
									}
									else if(sum > 200)
										break;
								}
							}
						}
					}
				}
			}
		}
	}
	end = clock();
	printf("Count: %d\n", count);
	printf("Time taken: %f\n", ((double)end - (double)start) / CLOCKS_PER_SEC);
	return 0;
}
