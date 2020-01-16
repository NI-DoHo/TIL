/*
   You should use the standard input/output

   in order to receive a score properly.

   Do not use file input and output

   Please be very careful. 
 */

#include <stdio.h>
/*
   DH.KIM 2020.01.10. NOTE::

   Vertexs in bin & small cube

   1. Min x Min y Min z
   2. Min x Min y Max z
   3. Min x Max y Min z
   4. Min x Max y Max z

   5. Max x Min y Min z
   6. Max x Min y Max z
   7. Max x Max y Min z
   8. Max x Max y Max z
 */

#define X 0
#define Y 1
#define Z 2

#define MIN_X 0
#define MIN_Y 1
#define MIN_Z 2
#define MAX_X 3
#define MAX_Y 4
#define MAX_Z 5

#define DEFAULT -999999999

int main(void)
{
	int T, test_case;

	int big_cube_position[6];
	int small_cube_position[6];
	int big_cube_side_length = 0;
	int small_cube_side_length = 0;

	int i;
	
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using scanf function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */
	freopen("input.txt", "r", stdin);

	/*
	   If you remove the statement below, your program's output may not be recorded
	   when your program is terminated after the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		// NOTE :: Init big, small cube position array
		for (i = 0; i < 6; i++)
		{
			big_cube_position[i] = DEFAULT;
			small_cube_position[i] = DEFAULT;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////

		int points;

		scanf("%d", &points);
		int position[points][3];

		// Get locations (get big cube)
		for (i = 0; i < points; i++)
		{
			scanf("%d %d %d", &position[i][X], &position[i][Y], &position[i][Z]);

			// Get Min/Max X position
			if (big_cube_position[MIN_X] == DEFAULT || big_cube_position[MIN_X] > position[i][X]) big_cube_position[MIN_X] = position[i][X];
			if (big_cube_position[MAX_X] == DEFAULT || big_cube_position[MAX_X] < position[i][X]) big_cube_position[MAX_X] = position[i][X];

			// Get Min/Max Y position
			if (big_cube_position[MIN_Y] == DEFAULT || big_cube_position[MIN_Y] > position[i][Y]) big_cube_position[MIN_Y] = position[i][Y];
			if (big_cube_position[MAX_Y] == DEFAULT || big_cube_position[MAX_Y] < position[i][Y]) big_cube_position[MAX_Y] = position[i][Y];

			// Get Min/Max Z position
			if (big_cube_position[MIN_Z] == DEFAULT || big_cube_position[MIN_Z] > position[i][Z]) big_cube_position[MIN_Z] = position[i][Z];
			if (big_cube_position[MAX_Z] == DEFAULT || big_cube_position[MAX_Z] < position[i][Z]) big_cube_position[MAX_Z] = position[i][Z];
		}

		// Get big cube side length
		int x_side = big_cube_position[MAX_X] - big_cube_position[MIN_X];
		int y_side = big_cube_position[MAX_Y] - big_cube_position[MIN_Y];
		int z_side = big_cube_position[MAX_Z] - big_cube_position[MIN_Z];

		if (x_side < y_side)
			big_cube_side_length = y_side < z_side ? z_side : y_side;
		else
			big_cube_side_length = x_side < z_side ? z_side : x_side;

		float side_center = big_cube_side_length / 2.0;
		/* DEBUG
		printf("side_center : %f\n", side_center);
		*/

		// Get small cube
		for (i = 0; i < points; i++)
		{
			// Get Min/Max X position
			if ((float)position[i][X] < side_center && (small_cube_position[MIN_X] == DEFAULT || small_cube_position[MIN_X] < position[i][X]))
				small_cube_position[MIN_X] = position[i][X];
			if ((float)position[i][X] > side_center && (small_cube_position[MAX_X] == DEFAULT || small_cube_position[MAX_X] > position[i][X]))
				small_cube_position[MAX_X] = position[i][X];

			// Get Min/Max Y position
			if ((float)position[i][Y] < side_center && (small_cube_position[MIN_Y] == DEFAULT || small_cube_position[MIN_Y] < position[i][Y]))
				small_cube_position[MIN_Y] = position[i][Y];
			if ((float)position[i][Y] > side_center && (small_cube_position[MAX_Y] == DEFAULT || small_cube_position[MAX_Y] > position[i][Y]))
				small_cube_position[MAX_Y] = position[i][Y];

			// Get Min/Max Z position
			if ((float)position[i][Z] < side_center && (small_cube_position[MIN_Z] == DEFAULT || small_cube_position[MIN_Z] < position[i][Z]))
				small_cube_position[MIN_Z] = position[i][Z];
			if ((float)position[i][Z] > side_center && (small_cube_position[MAX_Z] == DEFAULT || small_cube_position[MAX_Z] > position[i][Z]))
				small_cube_position[MAX_Z] = position[i][Z];
		}
	
		// Get small cube side length
		if (small_cube_position[MAX_X] != DEFAULT) x_side = small_cube_position[MAX_X] - small_cube_position[MIN_X];
		else x_side = big_cube_side_length;
		if (small_cube_position[MAX_Y] != DEFAULT) y_side = small_cube_position[MAX_Y] - small_cube_position[MIN_Y];
		else y_side = big_cube_side_length;
		if (small_cube_position[MAX_Z] != DEFAULT) z_side = small_cube_position[MAX_Z] - small_cube_position[MIN_Z];
		else z_side = big_cube_side_length;

		if (x_side < y_side)
			small_cube_side_length = x_side < z_side ? x_side : z_side;
		else
			small_cube_side_length = y_side < z_side ? y_side : z_side;

		// Print the answer to standard output(screen).
		printf("Case #%d\n", test_case+1);
		printf("%d\n", big_cube_side_length - small_cube_side_length);
		
		/* DEBUG
		printf("[BIG CUBE POSITION]\n");
		printf("MAX_X : %d / MIN_X : %d\n", big_cube_position[MAX_X], big_cube_position[MIN_X]);
		printf("MAX_Y : %d / MIN_Y : %d\n", big_cube_position[MAX_Y], big_cube_position[MIN_Y]);
		printf("MAX_Z : %d / MIN_Z : %d\n", big_cube_position[MAX_Z], big_cube_position[MIN_Z]);

		printf("[SMALL CUBE POSITION]\n");
		printf("MAX_X : %d / MIN_X : %d\n", small_cube_position[MAX_X], small_cube_position[MIN_X]);
		printf("MAX_Y : %d / MIN_Y : %d\n", small_cube_position[MAX_Y], small_cube_position[MIN_Y]);
		printf("MAX_Z : %d / MIN_Z : %d\n", small_cube_position[MAX_Z], small_cube_position[MIN_Z]);
		*/
	}

	return 0;//Your program should return 0 on normal termination.
}
