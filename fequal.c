/*
 *   Copyright Zhicheng Wei <zhicheng1988@gmail.com>
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include <math.h>
#include <float.h>

#include "fequal.h"

#define fequalsign(i) 	(((i) >> 31) != 0)

typedef enum {false = 0, true = 1} bool;

union fequal_t
{
	int   i;    /* must be sure your int is 32bit */
	float f;
};

int fequal(float a, float b)
{
	return fequalrelt(a, b, FLT_EPSILON, FLT_EPSILON);
}

int fequalulps(float a, float b, float maxdiff, int maxulpsdiff)
{
	/* Check if the numbers are really close -- needed */
	/* when comparing numbers near zero.  */
	float absdiff = fabs(a - b);
	if (absdiff <= maxdiff)
		return true;

	union fequal_t ua, ub;
	ua.f = a;
	ub.f = b;

	/* Different signs means they do not match. */
	if (fequalsign(ua.i) != fequalsign(ub.i))
		return false;

	/* Find the difference in ULPs. */
	int ulpsdiff = abs(ua.i - ub.i);
	if (ulpsdiff <= maxulpsdiff)
		return true;
	return false;
}

int fequalrelt(float a, float b, float maxdiff, int maxreltdiff)
{
	/* Check if the numbers are really close -- needed */
	/* when comparing numbers near zero. */
	float diff = fabs(a - b);
	if (diff <= maxdiff)
		return true;

	a = fabs(a);
	b = fabs(b);
	float largest = (b > a) ? b : a;

	if (diff <= largest * maxreltdiff)
		return true;
	return false;
}

