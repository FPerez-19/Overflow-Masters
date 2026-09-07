/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Euclidean distance between two points. When you only need to
 * compare distances, skip the sqrt and compare the squares: it is faster and
 * exact in integers.
 * Time: O(1)
 * Status: untested
 */
#pragma once
double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
