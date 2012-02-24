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

/* 
 * this code is borrow from 
 * http://altdevblogaday.com/2012/02/22/comparing-floating-point-numbers-2012-edition/
 */

/* 
 * limited
 * (int) must be 32bit
 * <math.h> and <float.h> is required
 */

/*
 * PS:
 * about ULP(unit in the last place) see this:
 * http://en.wikipedia.org/wiki/Unit_in_the_last_place
 *
 * maxdiff is for if a,b near-zero case
 * ULP and Relative differ is not work well when it's near-zero;
 *
 * fequalulps() is more precision than fequalrelt()
 * but fequalrelt is work well for most case;
 *
 * fequal(a, b) == fequalrelt(a, b, FLT_EPSILON, FLT_EPSILON)
 *
 * NaN's result is undefined
 *
 */


int fequal(float a, float b);
int fequalulps(float a, float b, float maxdiff, int maxulpsdiff);
int fequalrelt(float a, float b, float maxdiff, int maxreltdiff);

